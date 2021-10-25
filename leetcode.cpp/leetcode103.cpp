#include"iostream"
#include"vector"
#include"queue"
#include"algorithm"
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int layer=1;
        queue<TreeNode*> que;
        vector<vector<int>> result;
        if(root!=nullptr)
        {
            que.push(root);
        }
        while(!que.empty())
        {
            int size=que.size();
            vector<int> temp;
            TreeNode* node;
            for(int i=0;i<size;i++)
            {
                node=que.front();
                temp.push_back(node->val);
                if(node->left!=nullptr)
                {
                    que.push(node->left);
                }
                if(node->right!=nullptr)
                {
                    que.push(node->right);
                }
                que.pop();
            }
            if(layer%2==0)
            {
                reverse(temp.begin(),temp.end());
            }
            layer++;
            result.push_back(temp);
        }
        return result;
    }
};