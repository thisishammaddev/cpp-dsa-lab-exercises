#include <iostream>
using namespace std;

void swapVar(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swapXor(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{

    int a = 5, b = 10;

    cout << "Before Swaping: " << a << " " << b << endl;
    swapVar(a, b);
    cout << "After Swaping: " << a << " " << b << endl;

    return 0;
// }