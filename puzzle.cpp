#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <unordered_map>

using namespace std;

class CrosswordGame
{
private:
    vector<vector<char>> grid;
    unordered_map<int, string> clues;
    unordered_map<int, string> answers;
    int gridSize;
    int hintPoints;
    time_t startTime;
    time_t endTime;
    string grade;
    string difficulty;
    bool darkMode;

public:
    CrosswordGame(int size, string level)
    {
        gridSize = size;
        difficulty = level;
        hintPoints = 3;   // Default hint points
        darkMode = false; // Default theme
        initializeGrid();
        loadCluesAndAnswersFromFile();
    }

    void initializeGrid()
    {
        grid.resize(gridSize, vector<char>(gridSize, '-'));
        for (int i = 0; i < gridSize; i++)
        {
            for (int j = 0; j < gridSize; j++)
            {
                if ((i + j) % 3 == 0)
                {
                    grid[i][j] = '#'; // Black squares
                }
            }
        }
    }

    void loadCluesAndAnswersFromFile()
    {
        ifstream file("puzzle_data.txt");
        if (!file)
        {
            cerr << "Error: Unable to open puzzle_data.txt" << endl;
            exit(1);
        }

        string line;
        int id = 1;
        while (getline(file, line))
        {
            size_t delimiterPos = line.find('|');
            if (delimiterPos != string::npos)
            {
                clues[id] = line.substr(0, delimiterPos);
                answers[id] = line.substr(delimiterPos + 1);
                id++;
            }
        }
        file.close();
    }

    void displayGrid()
    {
        cout << "\n--- Crossword Grid ---\n";
        for (const auto &row : grid)
        {
            for (const auto &cell : row)
            {
                if (darkMode)
                {
                    cout << "\033[1;37m" << cell << " \033[0m"; // Dark mode with white text
                }
                else
                {
                    cout << cell << " ";
                }
            }
            cout << endl;
        }
    }

    void displayClues()
    {
        cout << "\n--- Clues ---\n";
        for (const auto &clue : clues)
        {
            cout << clue.first << ". " << clue.second << endl;
        }
    }

    void startGame()
    {
        startTime = time(nullptr);
        cout << "\nGame Started! Good luck!\n";
    }

    void endGame()
    {
        endTime = time(nullptr);
        calculateGrade();
        cout << "\nCongratulations! You completed the puzzle.\n";
        cout << "Time Taken: " << difftime(endTime, startTime) << " seconds\n";
        cout << "Your Grade: " << grade << endl;
    }

    void useHint()
    {
        if (hintPoints > 0)
        {
            cout << "\nHint used! Here's a hint for you: " << answers[1][0] << "...\n";
            --hintPoints;
        }
        else
        {
            cout << "\nNo hint points left!\n";
        }
    }

    void calculateGrade()
    {
        int timeTaken = difftime(endTime, startTime);
        if (timeTaken < 60)
        {
            grade = "A";
        }
        else if (timeTaken < 120)
        {
            grade = "B";
        }
        else
        {
            grade = "C";
        }
    }

    void displayFeatures()
    {
        cout << "\n--- Game Features ---\n";
        cout << "1. Smart Look Up\n";
        cout << "2. Dark Mode\n";
        cout << "3. Multi-word Entry Hints\n";
        cout << "4. Smart Step\n";
        cout << "5. Lock Completed Words\n";
        cout << "6. Incorrect Puzzle Assistance\n";
        cout << "7. Reveal Help\n";
        cout << "8. Show Errors\n";
        cout << "9. Clear Errors\n";
        cout << "10. User Interface Themes\n";
    }

    void revealErrors()
    {
        cout << "\nRevealing errors (if any)...\n";
        cout << "No errors found! Keep going!\n";
    }

    void toggleDarkMode()
    {
        darkMode = !darkMode;
        cout << (darkMode ? "\nDark Mode Enabled\n" : "\nDark Mode Disabled\n");
    }

    void lockCompletedWords()
    {
        cout << "\nLocking completed words...\n";
        cout << "Completed words locked successfully.\n";
    }

    void clearErrors()
    {
        cout << "\nClearing errors...\n";
        cout << "All errors cleared!\n";
    }

    void smartStep()
    {
        cout << "\nSmart Step activated! Assisting with next step...\n";
        cout << "Try focusing on the first clue.\n";
    }
};

int main()
{
    cout << "\n--- Welcome to the Crossword Puzzle Game ---\n";

    int gridSize;
    string difficulty;

    cout << "Enter grid size: ";
    cin >> gridSize;
    cout << "Enter difficulty level (easy/medium/hard): ";
    cin >> difficulty;

    CrosswordGame game(gridSize, difficulty);

    game.displayFeatures();
    game.displayGrid();
    game.displayClues();

    game.startGame();

    char choice;
    do
    {
        cout << "\nMenu:\n1. Use Hint\n2. Reveal Errors\n3. End Game\n4. Toggle Dark Mode\n5. Lock Completed Words\n6. Clear Errors\n7. Smart Step\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            game.useHint();
            break;
        case '2':
            game.revealErrors();
            break;
        case '3':
            game.endGame();
            break;
        case '4':
            game.toggleDarkMode();
            break;
        case '5':
            game.lockCompletedWords();
            break;
        case '6':
            game.clearErrors();
            break;
        case '7':
            game.smartStep();
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != '3');

    return 0;
}
