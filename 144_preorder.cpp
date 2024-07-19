// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;

        if (root == NULL)
        {
            return result;
        }
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top(); // get num
            st.pop();                  // pop num from stack
            result.push_back(node->val);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return result;
    }
};