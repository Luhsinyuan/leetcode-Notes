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
 // iteration solution
/*class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
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
        int total;
        for(int num:result)
        {
            if(num>=low&&num<=high)
            {
                total+=num;
            }
            if(num>high)
            {
                break;
            }
        }
        return total;
    }
}; */
// dfs solution
class Solution {
public:
    int result=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
       dfs(root,low,high);
       return result;
    }
    void dfs(TreeNode* root,int low,int high)
    {
        if(root==nullptr)
        {
            return;
        }
        int temp=root->val;
        if(temp>=low&&temp<=high)
        {
            result+=temp;
            dfs(root->left,low,high);
            dfs(root->right,low,high);
        }
        else if(temp<low)
        {
            dfs(root->right,low,high);
        }
        else if(temp>high)
        {
            dfs(root->left,low,high);
        }
    }
}; 