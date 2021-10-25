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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A||!B)
            return false;
        return hasSubStructure(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool hasSubStructure(TreeNode* A,TreeNode* B)
    {
        if(!B)
            return true;
        if(!A||A->val!=B->val)
            return false;
        return hasSubStructure(A->left,B->left)&&hasSubStructure(A->right,B->right);
    }
};