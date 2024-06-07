/*
https://leetcode.com/problems/replace-words/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 26;
struct Trie {
    Trie* next[N];
    bool isEnd = 0;

    Trie() {
        fill(next, next+N, (Trie*)NULL);
    }

    void insert(string& word) {
        Trie* Node = this;
        for (char c: word) {
            int i = c-'a';
            if (Node->next[i] == NULL)
                Node->next[i] = new Trie();
            Node = Node->next[i];
        }
        Node->isEnd = 1;
    }

    string findRoot(string& word) {
        Trie* Node = this;
        string root;
        for (char c: word) {
            int i = c-'a';
            if (Node->next[i]==NULL) return word;
            Node = Node->next[i];
            root += c;
            if (Node->isEnd) return root;
        }
        return word; // Return word if can not found prefix root
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (string& word: dictionary)
            trie.insert(word);

        string ans, word;
        for (char c: sentence) {
            if (c != ' ') word += c;
            else {
                ans += trie.findRoot(word);
                ans += " ";
                word = "";
            }
        }
        ans += trie.findRoot(word); // Last word of sentence
        return ans;
    }
};
