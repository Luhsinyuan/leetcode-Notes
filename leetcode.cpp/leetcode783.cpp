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
    int minDiffInBST(TreeNode* root) {
      vector<int> numlist=inorder_tra(root);
      int min_num=INT32_MAX;
      for(int i=0;i<numlist.size()-1;i++)
      {
          if(numlist[i+1]-numlist[i]<min_num)
          {
              min_num=numlist[i+1]-numlist[i];
          }
      }
      return min_num;
    }
    vector<int> inorder_tra(TreeNode* root)
    {
        stack<TreeNode*> st;
        vector<int> numlist;
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
                numlist.push_back(current->val);
                current=current->right;
            }
        }
        return numlist;
    }
};
int main()
{
    Solution s;
    TreeNode* root=new TreeNode(4);
    TreeNode* root_left=new TreeNode(2);
    TreeNode* root_right=new TreeNode(6);
    root->left=root_left;
    root->right=root_right;
    int result=s.minDiffInBST(root);
    cout<<result<<endl;
    system("pause");
    return 0;
}