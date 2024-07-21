/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue <TreeNode*> que;
        vector<int> result; // check it is  one-dimen 
        if (root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector <int> vec;
            for(int i = 0; i < size ; ++i){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(i == (size -1)) result.push_back(node->val); // when i reach to the last element(from left to right) in the level, add the rightmost element to the vector (result)
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        } 
        return result;
    }
};