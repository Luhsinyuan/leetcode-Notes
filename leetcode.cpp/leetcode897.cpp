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
 
class Solution {
public:

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* new_root=new TreeNode(0);
        TreeNode* move=new_root;
        bool is_first=true;
        stack<TreeNode*> result;
        TreeNode* current=root;
        while(current!=nullptr||!result.empty())
        {
            if(current!=nullptr)
            {
                result.push(current);
                current=current->left;
            }
            else
            {
                current=result.top();
                result.pop();
                TreeNode* temp1=new TreeNode(current->val);
                if(is_first)
                {
                    move->val=temp1->val;
                    is_first=false;
                }
                else
                {
                    move->right=temp1;
                    move=move->right;
                }
                current=current->right;
            }
        }
        return new_root;
    }
};
