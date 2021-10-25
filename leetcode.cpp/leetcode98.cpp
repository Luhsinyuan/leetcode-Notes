#include"iostream"
#include"vector"
#include"queue"
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
//troditional
/*
    long long find_(bool flag,TreeNode* root)
    {
        if(root==nullptr)
        {
            if(flag)
            return INT64_MIN;
            else
            return INT64_MAX;
        }
        vector<long long> temp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* current=q.front();
            q.pop();
            temp.push_back(current->val);
            if(current->left!=nullptr)
            {
                q.push(current->left);
            }
            if(current->right!=nullptr)
            {
                q.push(current->right);
            }
        }
    sort(temp.begin(),temp.end());
    if(flag)
    {
        reverse(temp.begin(),temp.end());
    }
    return temp[0];
}

    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }
        else if(isValidBST(root->left)&&isValidBST(root->right))
        {
           long long left_max=find_(true,root->left);
           long long right_min=find_(false,root->right);
           if(root->val>left_max&&root->val<right_min)
           {
               return true;
           }
        }
        return false;
    }
    */
   bool helper(TreeNode* root,long long lower,long long upper)
   {
        if(root==nullptr)
        {
            return true;
        }
        if(root->val<=lower||root->val>=upper)
        {
            return false;
        }
        return helper(root->left,lower,root->val)&&helper(root->right,root->val,upper);
   }
   bool isValidBST(TreeNode* root) {
        return helper(root,INT64_MIN,INT64_MAX);
        
    }
};

int main()
{
    TreeNode* root=new TreeNode(5);
    TreeNode* node1=new TreeNode(4);
    TreeNode* node2=new TreeNode(6);
    TreeNode* node3=new TreeNode(3);
    TreeNode* node4=new TreeNode(7);
    root->left=node1;
    root->right=node2;
    node2->left=node3;
    node2->right=node4;
    Solution s;
    bool result=s.isValidBST(root);
    if(result)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    system("pause");
    return 0;
}