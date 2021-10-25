#include"iostream"
#include"vector"

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
        {
            return false;
        }
        return dfs(root,targetSum,0);
    }
    bool dfs(TreeNode* root,int targetSum,int cur_sum)
    {
        if(root)
        {
            cur_sum+=root->val;
            
        }
        if(cur_sum==targetSum&&!root->left&&!root->right)
        {
            return true;
        }
        if(!root)
        {
            return false;
        }
        return dfs(root->left,targetSum,cur_sum)||dfs(root->right,targetSum,cur_sum);
    }
};