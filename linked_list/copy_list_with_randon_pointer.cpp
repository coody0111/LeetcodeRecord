/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Node* : old, Node*: new // representing for old and new node
        unordered_map<Node*, Node*> con;
        Node* dummy = new Node(0);
        Node* tail = dummy;
        // copy all nodes
        for(auto cur = head; cur!=NULL; cur = cur->next){
            tail -> next = new Node(cur->val);
            tail = tail -> next;
            con[cur] = tail;
        }
        tail = dummy -> next; 
        // assign random and next pointers
        for( auto cur = head; cur; cur = cur-> next){
            tail -> random = con[cur->random];
            tail = tail ->next;
        }
        return dummy -> next;
    }
};