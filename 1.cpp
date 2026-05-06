#include <iostream>
#include <string>
using namespace std;

int balancedStringSplit(string s) {
    int balance = 0;
    int count = 0;

    for (char ch : s) {
        if (ch == 'R')
            balance++;
        else if (ch == 'L')
            balance--;

        if (balance == 0)
            count++;
    }
    return count;
}

int main() {
    string s1 = "RLRRLLRLRL";
    cout << balancedStringSplit(s1) << endl;  // 4

    string s2 = "RLRRRLLRL";
    cout << balancedStringSplit(s2) << endl;  // 2

    string s3 = "LLLLRRRR";
    cout << balancedStringSplit(s3) << endl;  // 1

    return 0;
}