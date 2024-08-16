/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        // Stop Condition
        if (root == NULL)
            return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftnode = 0;
        int rightnode = 0;
        while (left) {
            left = left->left;
            leftnode++;
           
        }
        while (right) {
            right = right->right;
            rightnode++;
        }
        if (leftnode == rightnode) {
            return (2 << leftnode) - 1;
        }
        int getleft = countNodes(root->left);
        int getright = countNodes(root->right);
        int result = getleft + getright + 1;
        return result;
    }
};
