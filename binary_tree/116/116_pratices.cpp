/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root!= NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            Node* nodePre;
            Node* node;
            for(int i = 0; i < size; i++){
                if (i == 0){ // queue only one element
                    nodePre = que.front(); 
                    que.pop();
                    node = nodePre;
                }else{
                    node = que.front();
                     // node always refresh and stand for the first element.
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre ->next;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            nodePre->next = NULL;
        }
        return root;
    }
};