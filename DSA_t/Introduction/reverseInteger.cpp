#include <iostream>
using namespace std;

int reverse(int num)
{

    int result = 0;
    while (num != 0)
    {
        result = (result * 10) + num % 10;
        num/=10;
    }
    return result;
}

int main()
{

    int num = 123;
    cout << "Number to be reversed is " << num << endl;
    cout << "Reversed Number is " << reverse(num) << endl;

    return 0;
}