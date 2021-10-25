#include"iostream"
#include"vector"
#include"map"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,bool> m;
        ListNode* head_move=head;
        ListNode* new_list=new ListNode(101);
        ListNode* new_list_toreturn=new_list;
        while(head_move!=nullptr)
        {
            if(m.find(head_move->val)==m.end())
            {
                m.insert(pair<int ,bool>(head_move->val,false));
            }
            else if(!m[head_move->val])
            {
                m[head_move->val]=true;
            }
            head_move=head_move->next;
        }
        head_move=head;
        while(head_move)
        {
            if(!m[head_move->val])
            {
                new_list->next=head_move;
                new_list=new_list->next;
            }
            head_move=head_move->next;
        }
        new_list->next=nullptr;
        return new_list_toreturn->next;
    }
};
int main()
{
    ListNode* head=new ListNode(2);
    ListNode* head1=new ListNode(2);
    ListNode* head2=new ListNode(2);
    ListNode* head3=new ListNode(4);
    head->next=head1;
    head1->next=head2;
    head2->next=head3;
    Solution S;
    ListNode* result=S.deleteDuplicates(head);
    while(result!=nullptr)
    {
        cout<<result->val<<endl;
        result=result->next;
    }
    system("pause");
    return 0;
}
