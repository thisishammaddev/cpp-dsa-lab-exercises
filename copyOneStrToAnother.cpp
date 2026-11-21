#include <iostream>
#include <string>
using namespace std;

void copyOneStrToAnother(char str1[], char str2[], int idx = 0)
{

    str2[idx] = str1[idx]; // base case
    if (str1[idx] == '\0')
    {
        return;
    }

    // recursive relation
    copyOneStrToAnother(str1, str2, idx + 1);
}

int main()
{

    char str1[100] = "HelloWorld";

    char str2[100] = "";
    copyOneStrToAnother(str1, str2);
    cout << "String Two: "<< str2 << endl;

    return 0;
}