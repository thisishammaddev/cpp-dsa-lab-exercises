#include <iostream>
#include <fstream>
using namespace std;

struct student
{
    int rollno;
    string name;
    char section;
    int session;
    string gender;
};

int main()
{
    student s1[5] = {
        {111, "Zakki", 'B', 2023, "Male"},
        {112, "Mudassir", 'B', 2023, "Male"},
        {113, "Jazib", 'B', 2023, "Male"},
    };

    cout << "Enter the remaining students' data: " << endl;
    for (int i = 3; i < 5; i++)
    {
        cout << "Enter the " << i + 1 << " idx student roll number: ";
        cin >> s1[i].rollno;
        cout << "Enter the " << i + 1 << " idx student name: ";
        cin >> s1[i].name;
        cout << "Enter the " << i + 1 << " idx student section: ";
        cin >> s1[i].section;
        cout << "Enter the " << i + 1 << " idx student session: ";
        cin >> s1[i].session;
        cout << "Enter the " << i + 1 << " idx student gender: ";
        cin >> s1[i].gender;
    }

    ofstream studentFile;
    studentFile.open("D:\\UET LAHORE\\3rd Semester\\dsaLab\\studntRecord.txt");

    if (!studentFile)
    {
        cout << "There is an error while opening the file" << endl;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            studentFile << "The roll number of student " << i + 1 << " is " << s1[i].rollno << endl;
            studentFile << "The name of student " << i + 1 << " is " << s1[i].name << endl;
            studentFile << "The section of student " << i + 1 << " is " << s1[i].section << endl;
            studentFile << "The session of student " << i + 1 << " is " << s1[i].session << endl;
            studentFile << "The gender of student " << i + 1 << " is " << s1[i].gender << endl;
            studentFile << endl;
        }
    }
    studentFile.close();

    ifstream studentFileOut;
    studentFileOut.open("D:\\UET LAHORE\\3rd Semester\\dsaLab\\studntRecord.txt");

    string fileContent;

    if (studentFileOut.is_open())
    {
        cout << "Reading the data from the file: " << endl;
        while (getline(studentFileOut, fileContent))
        {
            cout << fileContent << endl;
        }
        studentFileOut.close();
    }
    else
    {
        cout << "Unable to open the file" << endl;
    }

    return 0;
}
