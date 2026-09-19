#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, temp, digit;
    stack<int> s;

    cout << "Enter a number: ";
    cin >> n;

    temp = n;

    // Push each digit into stack
    while (temp > 0) {
        digit = temp % 10;
        s.push(digit);
        temp = temp / 10;
    }

    // Compare digits with stack
    temp = n;
    bool palindrome = true;

    while (temp > 0) {
        digit = temp % 10;

        if (digit != s.top()) {
            palindrome = false;
            break;
        }

        s.pop();
        temp = temp / 10;
    }

    if (palindrome)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}