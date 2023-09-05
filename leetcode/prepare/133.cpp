/*
https://leetcode.com/problems/clone-graph/
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (node->neighbors.size() == 0) return new Node(node->val);
        
        Node* ans = new Node(node->val);
        unordered_map<Node*, Node*> ref;
        ref[node] = ans;
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            for (auto nei: curr->neighbors) {
                if (ref.find(nei) == ref.end()) {
                    ref[nei] = new Node(nei->val);
                    q.push(nei);
                }
                ref[curr]->neighbors.push_back(ref[nei]);
            }
        }
        
        return ans;
    }
};
