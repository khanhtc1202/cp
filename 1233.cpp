/*
https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
*/
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEndOfDir;
    unordered_map<string, TrieNode*> children;
    TrieNode(): isEndOfDir(false) {}
};

class Solution {
    TrieNode* root = new TrieNode();
public:
    vector<string> removeSubfolders(vector<string>& dirs) {
        // Build trie
        for (string& path: dirs) {
            TrieNode* currNode = root;
            istringstream iss(path);
            string dirName;

            while (getline(iss, dirName, '/')) {
                if (dirName.empty()) continue;
                // Add node if not existed
                if (currNode->children.find(dirName) == currNode->children.end()) {
                    currNode->children[dirName] = new TrieNode();
                }
                currNode = currNode->children[dirName];
            }
            currNode->isEndOfDir = true;
        }

        vector<string> res;
        for (string& path: dirs) {
            TrieNode* currNode = root;
            istringstream iss(path);
            string dirName;
            bool isSubDir = false;

            while (getline(iss, dirName, '/')) {
                if (dirName.empty()) continue;
                TrieNode* next = currNode->children[dirName];
                if (next->isEndOfDir && iss.rdbuf()->in_avail() != 0) {
                    isSubDir = true;
                    break;
                }
                currNode = next;
            }
            if (!isSubDir) res.push_back(path);
        }
        return res;
    }
};
