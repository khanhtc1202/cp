#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hm;
        for (auto& str: strs) {
            string key = buildKey(str);
            hm[key].push_back(str);
        }

        vector<vector<string>> out;
        for (auto& e: hm) {
            out.push_back(e.second);
        }
        return out;
    }

private:
    string buildKey(string& s) {
        vector<int> km(26, 0);
        for (auto& c : s) {
            km[c-'a']++;
        }
        string key;
        for (int i = 0; i < 26; i++) {
            key += string(km[i], i + 'a');
        }
        
        return key;
    }
};

int main() {
    return 0;
}
