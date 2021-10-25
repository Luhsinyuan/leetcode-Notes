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

class Solution {                        //不在vector中存储值，而是按顺序存储指针，最将指针重新连接起来
public:
    vector<TreeNode*> roots;
    void flatten(TreeNode* root) {
        preorder(root);
        TreeNode* newRoot=new TreeNode(0);
        TreeNode* result = newRoot;
        for(int i=1;i<roots.size();i++)
        {
            TreeNode* pre=roots[i-1];
            TreeNode* cur=roots[i];
            pre->left=nullptr;
            pre->right=cur;
        }
    }
    void preorder(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        roots.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
};