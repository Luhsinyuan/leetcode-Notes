#include"iostream"
#include"vector"
#include"queue"
#include"math.h"

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    vector<Node*> temp;
    Node* connect(Node* root) {
        layerOrder(root);
        int total_num=temp.size();
        int layer_num=1;
        int layer=0;
        for(int i=1;i<total_num;i++)
        {
            Node* pre=temp[i-1];
            Node* cur=temp[i];
            if(i==layer_num)
            {
                pre->next=nullptr;
                layer++;
                layer_num+=pow(2,layer);
            }
            else
            {
                pre->next=cur;
            }
        }
        return root;
    }
    void layerOrder(Node* root)
    {
        queue<Node*> q;
        if(root)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            temp.push_back(q.front());
            if(q.front()->left!=nullptr)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right!=nullptr)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
};