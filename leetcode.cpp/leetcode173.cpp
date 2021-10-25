#include"iostream"
#include"vector"
#include"stack"
#include"queue"
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
class BSTIterator {
public:
    queue<int> numlist;
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> st;
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
                numlist.push(current->val);
                current=current->right;
            }
        }
    }
    
    int next() {
        int num=numlist.front();
        numlist.pop();
        return num;
    }
    
    bool hasNext() {
        return !numlist.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */