#include"iostream"
#include"vector"
#include"stack"

using namespace std;

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> numlist;
        preorder(numlist,root);
        return numlist;
    }
    void preorder(vector<int> &result,TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        result.push_back(root->val);
        preorder(result,root->left);
        preorder(result,root->right);
    }
};
*/
//µü´úÐ´·¨£º
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> preorder;
        vector<int> result;
        if(root!=nullptr)
        {
            preorder.push(root);
        }
        while(!preorder.empty())
        {
            TreeNode* node=preorder.top();
            preorder.pop();
            result.push_back(node->val);
            if(node->right!=nullptr)
            {
                preorder.push(node->right);
            }
            if(node->left!=nullptr)
            {
                preorder.push(node->left);
            }

        }
        return result;
    }
};