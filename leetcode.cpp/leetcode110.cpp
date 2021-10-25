#include"iostream"
#include"vector"
#include"math.h"

using namespace std;



 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(depth(root->left)-depth(root->right)>=2||depth(root->left)-depth(root->right)<=-2)
        {
            return false;
        }
        else
        {
            return isBalanced(root->left)&&isBalanced(root->right);
        }
    }
    int depth(TreeNode* root)
    {
        if(!root)
            return 0;
        if(root->left==nullptr&&root->right==nullptr)
        {
            return 1;
        }
        return 1+max(depth(root->left),depth(root->right));
    }
};