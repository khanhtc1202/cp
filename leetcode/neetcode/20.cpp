#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto& c: s) {
            switch (c)
            {
            case ')':
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
                break;
            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
                break;
            default:
                st.push(c);
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s; cin >> s;
    cout << sol.isValid(s) << endl;
    return 0;
}
