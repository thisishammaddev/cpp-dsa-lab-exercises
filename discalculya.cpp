#include <iostream>
#include <cstring>
using namespace std;
// Function to display welcome message
void displayWelcomeMessage() {
	system("color 04");
	cout << "\033[1;32m******DYSCALCULIA LEARNING TOOL*********\033[0m" << endl; // Green text
    cout << "**********************\n";
    cout << "*                                                              *\n";
    cout << "*                Welcome to Dyscalculia Learning               *\n";
    cout << "*                  Empowering Minds with Math                  *\n";
    cout << "*                                                              *\n";
    cout << "**********************\n";
    cout << "*\n\n";
    cout << "Hi there! This tool is designed to help you improve your math skills while having fun.\n";
    cout << "Choose a level to start solving problems and track your progress along the way.\n";
    cout << "Let's embark on this exciting journey together!\n\n";
}
// Problem Node for Linked List
struct Problem {
    int id;
    char question[100];
    char answer[20];
    Problem* next;

    Problem(int id, const char* q, const char* a) : id(id), next(NULL) {
        strcpy(question, q);
        strcpy(answer, a);
    }
};

// MCQ Problem Node
struct MCQProblem {
	
    int id;
    char question[100];
    char options[4][50]; // 4 options for MCQ
    int correctOption;   // Correct option (1-4)
    MCQProblem* next;

    MCQProblem(int id, const char* q, const char* a1, const char* a2, const char* a3, const char* a4, int correct)
        : id(id), correctOption(correct), next(NULL) {
        strcpy(question, q);
        strcpy(options[0], a1);
        strcpy(options[1], a2);
        strcpy(options[2], a3);
        strcpy(options[3], a4);
    }
};

// Linked List for Exercise Management
class ProblemList {
    Problem* head;
    Problem* problems[100]; // Fixed-size array for storage
    int count;

public:
    ProblemList() : head(NULL), count(0) {}

    void addProblem(int id, const char* question, const char* answer) {
        Problem* newProblem = new Problem(id, question, answer);
        if (!head) {
            head = newProblem;
        } else {
            Problem* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newProblem;
        }
        problems[count++] = newProblem;
    }

    Problem** getProblems(int& size) {
        size = count;
        return problems;
    }
};

// Linked List for MCQ Management
class MCQList {
    MCQProblem* head;
    MCQProblem* mcqProblems[100]; // Fixed-size array for MCQ storage
    int count;

public:
    MCQList() : head(NULL), count(0) {}

    void addMCQProblem(int id, const char* question, const char* a1, const char* a2, const char* a3, const char* a4, int correctOption) {
        MCQProblem* newMCQProblem = new MCQProblem(id, question, a1, a2, a3, a4, correctOption);
        if (!head) {
            head = newMCQProblem;
        } else {
            MCQProblem* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newMCQProblem;
        }
        mcqProblems[count++] = newMCQProblem;
    }

    MCQProblem** getMCQProblems(int& size) {
        size = count;
        return mcqProblems;
    }
};

// History Record
struct History {
    char question[100];
    char userAnswer[20];
    char correctAnswer[20];
    bool isCorrect;
};

// Star Calculation
int calculateStars(int correct, int total) {
    if (total == 0) return 0; // No stars if no questions were answered
    double accuracy = (correct / (double) total) * 100;
    if (accuracy >= 95) return 5;
    if (accuracy >= 85) return 4;
    if (accuracy >= 70) return 3;
    return 2;
}

// Shuffle Function
void shuffleProblems(Problem** problems, int size) {
	
    for (int i = 0; i < size; ++i) {
        int randomIndex = (i * 7 + 3) % size; // Custom pseudo-random logic
        Problem* temp = problems[i];
        problems[i] = problems[randomIndex];
        problems[randomIndex] = temp;
    }
}

void shuffleMCQProblems(MCQProblem** mcqProblems, int size) {
    for (int i = 0; i < size; ++i) {
        int randomIndex = (i * 7 + 3) % size; // Custom pseudo-random logic for MCQs
        MCQProblem* temp = mcqProblems[i];
        mcqProblems[i] = mcqProblems[randomIndex];
        mcqProblems[randomIndex] = temp;
    }
}

// Level Logic
void levelHandler(ProblemList& problemList, History history[], int& historyCount, int& stars, int questionsToSolve, const char* levelName, int requiredStars) {
    cout << "\nWelcome to the " << levelName << " Level!\n";
    cout << "You need " << requiredStars << " stars to complete this level.\n";

    if (questionsToSolve < 1) {
        cout << "You must select at least one question to complete the level.\n";
        return;
    }

    // Get problems and shuffle them
    int size;
    Problem** allProblems = problemList.getProblems(size);
    shuffleProblems(allProblems, size);

    int correct = 0, total = 0;

    while (total < questionsToSolve && total < size) {
        Problem* current = allProblems[total];

        cout << current->question << "\nYour answer: ";
        char userAnswer[20];
        cin >> userAnswer;

        // Track history
        History record;
        strcpy(record.question, current->question);
        strcpy(record.userAnswer, userAnswer);
        strcpy(record.correctAnswer, current->answer);
        record.isCorrect = strcmp(userAnswer, current->answer) == 0;
        history[historyCount++] = record;

        if (record.isCorrect) {
            cout << "Correct!\n";
            correct++;
        } else {
            cout << "Incorrect. Correct Answer: " << current->answer << "\n";
        }
        total++;
    }

    if (total < questionsToSolve) {
        cout << "Only " << total << " questions were available to solve.\n";
    }

    stars = calculateStars(correct, total);

    if (total == 0) {
        cout << "You did not attempt any questions. No stars earned for this level.\n";
    } else {
        cout << "You earned " << stars << " stars for this level!\n";
    }

    if (stars >= requiredStars) {
        cout << "Congratulations! You completed the " << levelName << " Level!\n";
    } else {
        cout << "You need at least " << requiredStars << " stars to pass this level. Try again!\n";
    }
}

// Multiple Choice Question Handler
void mcqHandler(MCQList& mcqList, History history[], int& historyCount, int& stars, int questionsToSolve) {
    cout << "\nWelcome to the Multiple Choice Questions section!\n";

    if (questionsToSolve < 1) {
        cout << "You must select at least one question to complete.\n";
        return;
    }

    int size;
    MCQProblem** allMCQs = mcqList.getMCQProblems(size);
    shuffleMCQProblems(allMCQs, size);

    int correct = 0, total = 0;

    while (total < questionsToSolve && total < size) {
        MCQProblem* current = allMCQs[total];

        cout << "\n" << current->question << "\n";
        for (int i = 0; i < 4; ++i) {
            cout << i + 1 << ". " << current->options[i] << "\n";
        }

        cout << "Select the correct option (1-4): ";
        int userAnswer;
        cin >> userAnswer;

        // Track history
        History record;
        strcpy(record.question, current->question);
        strcpy(record.userAnswer, current->options[userAnswer - 1]);
        strcpy(record.correctAnswer, current->options[current->correctOption - 1]);
        record.isCorrect = (userAnswer == current->correctOption);
        history[historyCount++] = record;

        if (record.isCorrect) {
            cout << "Correct!\n";
            correct++;
        } else {
            cout << "Incorrect. Correct Answer: " << current->options[current->correctOption - 1] << "\n";
        }
        total++;
    }

    stars = calculateStars(correct, total);
    cout << "You earned " << stars << " stars for this section.\n";
}

// View Progress
void viewProgress(const int starsPerLevel[]) {
	system("color 30");
    cout << "\n=== Progress ===\n";
    cout << "Easy Level Stars: " << starsPerLevel[0] << "\n";
    cout << "Medium Level Stars: " << starsPerLevel[1] << "\n";
    cout << "Hard Level Stars: " << starsPerLevel[2] << "\n";
}

// View History
void viewHistory(const History history[], int historyCount) {
	system("color 80");
    cout << "\n=== History ===\n";
    for (int i = 0; i < historyCount; ++i) {
        cout << "Q: " << history[i].question << "\n"
             << "Your Answer: " << history[i].userAnswer << "\n"
             << "Correct Answer: " << history[i].correctAnswer << "\n"
             << (history[i].isCorrect ? "Result: Correct" : "Result: Incorrect") << "\n\n";
    }
}

void viewGuide(MCQList& mcqList) {
	system("color 04");
    cout << "\n=== Guide / Help ===\n";
    
    cout << "\n-- Easy Level Solutions --\n";
    cout << "1. 5 + 3 = 8\n";
    cout << "2. 10 - 7 = 3\n";
    cout << "3. 2 + 6 = 8\n";
    cout << "4. 4 * 2 = 8\n";
    cout << "5. 12 / 3 = 4\n";

    cout << "\n-- Medium Level Solutions --\n";
    cout << "1. 5 * 3 = 15\n";
    cout << "2. 12 / 4 = 3\n";
    cout << "3. 6 * 2 = 12\n";
    cout << "4. 15 - 6 = 9\n";
    cout << "5. 8 + 9 = 17\n";

    cout << "\n-- Hard Level Solutions --\n";
    cout << "1. 5.5 + 3.2 = 8.7\n";
    cout << "2. 10.4 - 7.1 = 3.3\n";
    cout << "3. 12.5 / 2.5 = 5\n";
    cout << "4. 25 * 1.2 = 30\n";
    cout << "5. 14.3 - 4.3 = 10\n";

    cout << "\n-- Multiple Choice Question Solutions --\n";
    int size;
    MCQProblem** mcqProblems = mcqList.getMCQProblems(size);

    for (int i = 0; i < size; ++i) {
        cout << "Q: " << mcqProblems[i]->question << "\n";
        for (int j = 0; j < 4; ++j) {
            cout << j + 1 << ". " << mcqProblems[i]->options[j] << "\n";
        }
        cout << "Correct Answer: " << mcqProblems[i]->options[mcqProblems[i]->correctOption - 1] << "\n\n";
    }
}
// Main Menu
void showMenu() {
    cout << "\n=== Dyscalculia Learning Tool ===\n";
    cout << "1. Easy Level\n";
    cout << "2. Medium Level\n";
    cout << "3. Hard Level\n";
    cout << "4. Multiple Choice Questions\n";
    cout << "5. View Progress\n";
    cout << "6. View History\n";
    cout << "7. View Guide/Help\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

// Main Function
int main() {
	
    cout << "==================================================================" << endl;
    cout << "              W   W   EEEE   L       CCCC   OOO   M   M   EEEE" << endl;
    cout << "              W   W   E      L      C      O   O  MM MM   E   " << endl;
    cout << "              W W W   EEEE   L      C      O   O  M M M   EEEE" << endl;
    cout << "              WW WW   E      L      C      O   O  M   M   E   " << endl;
    cout << "              W   W   EEEE   LLLLL   CCCC   OOO   M   M   EEEE" << endl;
    cout << "==================================================================" << endl;
    displayWelcomeMessage();
    ProblemList easyProblems, mediumProblems, hardProblems;
    MCQList mcqProblems;

    // Add problems for Easy Level
    easyProblems.addProblem(1, "5 + 3 = ?", "8");
    easyProblems.addProblem(2, "10 - 7 = ?", "3");
    easyProblems.addProblem(3, "2 + 6 = ?", "8");
    easyProblems.addProblem(4, "4 * 2 = ?", "8");
    easyProblems.addProblem(5, "12 / 3 = ?", "4");

    // Add problems for Medium Level
    mediumProblems.addProblem(1, "5 * 3 = ?", "15");
    mediumProblems.addProblem(2, "12 / 4 = ?", "3");
    mediumProblems.addProblem(3, "6 * 2 = ?", "12");
    mediumProblems.addProblem(4, "15 - 6 = ?", "9");
    mediumProblems.addProblem(5, "8 + 9 = ?", "17");

    // Add problems for Hard Level
    hardProblems.addProblem(1, "5.5 + 3.2 = ?", "8.7");
    hardProblems.addProblem(2, "10.4 - 7.1 = ?", "3.3");
    hardProblems.addProblem(3, "12.5 / 2.5 = ?", "5");
    hardProblems.addProblem(4, "25 * 1.2 = ?", "30");
    hardProblems.addProblem(5, "14.3 - 4.3 = ?", "10");

    // Add MCQ Problems
    mcqProblems.addMCQProblem(1, "What is 2 + 2?", "3", "4", "5", "6", 2);
    mcqProblems.addMCQProblem(2, "What is 3 * 5?", "12", "13", "15", "16", 3);
    mcqProblems.addMCQProblem(3, "What is 10 / 2?", "3", "4", "5", "6", 3);
    mcqProblems.addMCQProblem(4, "What is 9 - 3?", "4", "5", "6", "7", 3);

    int starsPerLevel[3] = {0, 0, 0}; // Tracks stars for Easy, Medium, Hard
    History history[100];            // Tracks all question attempts
    int historyCount = 0;

    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 4) {
            int questionsToSolve;
            cout << "\033[1;34mHow many multiple choice questions do you want to solve \033[0m" << endl; // Dark Blue text
            cout << "How many multiple choice questions do you want to solve? ";
            cin >> questionsToSolve;
            mcqHandler(mcqProblems, history, historyCount, starsPerLevel[0], questionsToSolve);
        }
        
else if (choice >= 1 && choice <= 3) {
    int questionsToSolve;
    cout << "How many questions do you want to solve? ";
    cin >> questionsToSolve;

    if (choice == 1) {
        system("color B0"); // Easy level color
        levelHandler(easyProblems, history, historyCount, starsPerLevel[0], questionsToSolve, "Easy", 3);
    } 
    else if (choice == 2) {
        system("color D0"); // Medium level color
        levelHandler(mediumProblems, history, historyCount, starsPerLevel[1], questionsToSolve, "Medium", 4);
    } 
    else if (choice == 3) {
        system("color C0"); // Hard level color
        levelHandler(hardProblems, history, historyCount, starsPerLevel[2], questionsToSolve, "Hard", 5);
    }
}
        else if (choice == 5) {
            viewProgress(starsPerLevel);
        } 
        else if (choice == 6) {
            viewHistory(history, historyCount);
        }
        else if (choice == 7) {
            viewGuide(mcqProblems);
        }
        else if (choice == 8) {
            cout << "Thank you for using the Dyscalculia Learning Tool!\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}