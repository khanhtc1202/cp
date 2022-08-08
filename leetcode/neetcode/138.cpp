#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        Node* copy = new Node(head->val);
        unordered_map<Node*, Node*> nodes;
        nodes[head] = copy;
        
        Node *curr = head, *ccurr = copy;
        while (curr->next) {
            curr = curr->next;
            ccurr->next = new Node(curr->val);
            ccurr = ccurr->next;
            nodes[curr] = ccurr;
        }
        
        curr = head; ccurr = copy;
        while (curr) {
            ccurr->random = nodes[curr->random];
            curr = curr->next;
            ccurr = ccurr->next;
        }
        
        return copy;
    }
};
