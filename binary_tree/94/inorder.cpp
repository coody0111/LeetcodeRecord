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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        TreeNode *cur = root; // use pointer to store node, only use in inorder
        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top(); // take first element and store. pop out from stack
                st.pop();       // pop out from stac
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};