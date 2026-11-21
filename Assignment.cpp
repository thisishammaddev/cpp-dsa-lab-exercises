#include <iostream>
#include <fstream>
using namespace std;

void displayMenu()
{
    cout << "\nPlease type 1 for 'First Class'" << endl;
    cout << "Please type 2 for 'Economy'" << endl;
    cout << "Please type 3 for Main Menu" << endl;
    cout << "Please type 4 to Exit the Program" << endl;
}

bool assignSeat(int seatingChart[], int start, int end, string classType)
{
    for (int i = start; i < end; ++i)
    {
        if (seatingChart[i] == 0)
        {
            seatingChart[i] = 1;
            cout << "Boarding Pass: Seat Number " << i + 1 << ", " << classType << " Section" << endl;
            ofstream outFile("reservations.txt", ios::app);
            outFile << "Seat Number " << i + 1 << ", " << classType << " Section\n";
            outFile.close();
            return true;
        }
    }
    return false;
}

void printReservations()
{
    ifstream inFile("reservations.txt");
    if (!inFile)
    {
        cout << "No reservations have been made yet." << endl;
    }
    else
    {
        string line;
        cout << "\nReserved Seats:\n";
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
        inFile.close();
    }
}

int main()
{
    int seatingChart[10] = {0};
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (!assignSeat(seatingChart, 0, 5, "First Class"))
            {
                cout << "First Class is full. Would you like to be placed in the Economy section? (y/n): ";
                char response;
                cin >> response;
                if (response == 'y' || response == 'Y')
                {
                    if (!assignSeat(seatingChart, 5, 10, "Economy"))
                    {
                        cout << "Economy is also full. Next flight leaves in 3 hours." << endl;
                    }
                }
                else
                {
                    cout << "Next flight leaves in 3 hours." << endl;
                }
            }
            break;

        case 2:
            if (!assignSeat(seatingChart, 5, 10, "Economy"))
            {
                cout << "Economy is full. Would you like to be placed in the First Class section? (y/n): ";
                char response;
                cin >> response;
                if (response == 'y' || response == 'Y')
                {
                    if (!assignSeat(seatingChart, 0, 5, "First Class"))
                    {
                        cout << "First Class is also full. Next flight leaves in 3 hours." << endl;
                    }
                }
                else
                {
                    cout << "Next flight leaves in 3 hours." << endl;
                }
            }
            break;

        case 3:
            break;

        case 4:
            printReservations();
            cout << "Exiting the program. Have a nice day!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}
