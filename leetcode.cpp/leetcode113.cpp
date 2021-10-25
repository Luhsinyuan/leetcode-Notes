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
    vector<int> path;
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum,0);
        return result;
    }
    void dfs(TreeNode* root,int targetSum,int cur_sum)
    {
        if(!root)
        {
            return;
        }
        
        
        cur_sum+=root->val;
        path.push_back(root->val);
        
        if(targetSum==cur_sum&&!root->left&&!root->right)
        {
            result.push_back(path);
            path.pop_back();
            return;
        }
        dfs(root->left,targetSum,cur_sum);
        dfs(root->right,targetSum,cur_sum);
        path.pop_back();
    }
};