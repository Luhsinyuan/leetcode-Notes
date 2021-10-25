#include"iostream"
#include"vector"
#include"stack"
#include"algorithm"

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
//µÝ¹éÐ´·¨£º
/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> numlist;
        postorder(numlist,root);
        return numlist;
    }
    void postorder(vector<int> &result,TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        postorder(result,root->left);
        postorder(result,root->right);
        result.push_back(root->val);
    }
};
*/
//µü´úÐ´·¨£º
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if(root!=nullptr)
        {
            st.push(root);
        }
        while(!st.empty())
        {
            TreeNode* node=st.top();
            st.pop();
            result.push_back(node->val);
            if(node->left!=nullptr)
            {
                st.push(node->left);
            }
            if(node->right!=nullptr)
            {
                st.push(node->right);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};