#include <bits/stdc++.h>
using namespace std;

class Soution {
public:
    bool isPalindrome(string str) {
        int s = 0, e = str.size() -1;
        while (s <= e) {
            if (!isalnum(str[s])) s++;
            else if (!isalnum(str[e])) e--;
            else {
                if (tolower(str[s++]) != tolower(str[e--])) return false;
            }
        }
        return true;
    }
};
