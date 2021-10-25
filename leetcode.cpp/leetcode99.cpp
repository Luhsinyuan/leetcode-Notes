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
 
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> q;
        vector<int> result;
        inorder(-1,q,result,root);
        sort(result.begin(),result.end());
        
        inorder(0,q,result,root);
        
    }
    void inorder(int num,stack<TreeNode*>& q,vector<int>& result,TreeNode* root)
    {
        TreeNode* current=root;
        while(!q.empty()||current!=nullptr)
        {
            if(current!=nullptr)
            {
                q.push(current);
                current=current->left;
            }
            else
            {
                current=q.top();
                q.pop();
                if(num==-1)
                result.push_back(current->val);
                else
                {
                    current->val=result[num];
                    num++;
                }
                current=current->right;
            }
        }
    }
};
