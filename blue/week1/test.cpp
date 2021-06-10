#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> cnt_s(26, 0);
    vector<int> cnt_t(26, 0);
    for (int i = 0; i < s.length(); i++) {
        cnt_s[s[i] - 'a']+=1;
    }
    for (int i = 0; i < t.length(); i++) {
        cnt_t[t[i] - 'a']+=1;
    }
    for (int i = 0; i < 26; i++) {
        cout << cnt_s[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 26; i++) {
        cout << cnt_t[i] << " ";
    }
    cout << endl;
    bool tree = false, automaton = false;
    int count = 0, diff = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt_t[i] > cnt_s[i]) {
            tree = true;
            break;
        }
        if (cnt_t[i] < cnt_s[i]) {
            automaton = true;
            diff++;
            continue;
        }
        count++;
    }
    cout << diff << " " << count << endl;
    if (tree) cout << "need tree" << endl;
    else if (automaton && (diff == 26 - count)) cout << "both" << endl;
    else if (count == 26) cout << "array" << endl;
    else cout << "automaton" << endl;

    return 0;
}