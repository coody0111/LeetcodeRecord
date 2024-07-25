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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return subRoot == NULL;
        if(isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }
    bool isSame(TreeNode* i, TreeNode*j){
        if(i== NULL && j== NULL) return true;
        if(i == NULL|| j ==NULL) return false;
        if(i->val!= j->val) return false;

        return isSame(i->left, j->left) && isSame(i->right, j->right);
    }
};