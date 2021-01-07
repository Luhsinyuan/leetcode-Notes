#include"iostream"
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* s_head=small;
        ListNode* big=new ListNode(0);
        ListNode* b_head=big;
        while(head!=nullptr)
        {
            if(head->val>=x)
            {
                ListNode* node=new ListNode(head->val);
                big->next=node;
                big=big->next;
            }
            else
            {
                ListNode* node=new ListNode(head->val);
                small->next=node;
                small=small->next;
            }
            head=head->next;
        }
        small->next=b_head->next;
        return s_head->next;
    }
};
int main()
{
    ListNode* head=new ListNode(0);
    ListNode* current;
    ListNode* node=new ListNode(1);
    head->next=node;
    current=node;
    ListNode* node1=new ListNode(4);
    current->next=node1;
    current=node1;
    ListNode* node2=new ListNode(3);
    current->next=node2;
    current=node2;
    ListNode* node3=new ListNode(2);
    current->next=node3;
    current=node3;
    ListNode* node4=new ListNode(5);
    current->next=node4;
    current=node4;
    ListNode* node5=new ListNode(2);
    current->next=node5;
    current=node5;
    ListNode* temp=head->next;
    for(;temp!=nullptr;temp=temp->next)
    {
        cout<<temp->val<<endl;
    }
    cout<<"**********"<<endl;
    Solution s;
    
    for(ListNode* bighead=s.partition(head->next,3)->next;bighead!=nullptr;bighead=bighead->next)
    {
        cout<<bighead->val<<endl;
    }
    system("pause");
    return 0;
}