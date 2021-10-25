#include"iostream"
#include"vector"
#include"stack"

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
    vector<int> result;
    void inorder(TreeNode* root)
    {
        if(root!=nullptr)
        {
            inorderTraversal(root->left);
            result.push_back(root->val);
            inorderTraversal(root->right);
        } 
    }
    vector<int> inorderTraversal(TreeNode* root) {
       inorder(root);
       return result;
    }
};*/

//µü´úÐ´·¨

class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root) {
       stack<TreeNode*> st;
       vector<int> result;
       TreeNode* current=root;
       while(current!=nullptr||!st.empty())
       {
          if(current!=nullptr)
          {
            st.push(current);
            current=current->left;
          }
          else
          {
            current=st.top();
            st.pop();
            result.push_back(current->val);
            current=current->right;
          }
       }
        return result;
    }
};