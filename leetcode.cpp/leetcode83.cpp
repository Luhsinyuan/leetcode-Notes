#include"iostream"
#include"vector"

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
        int test_num=0;
        if(head==nullptr)
        {
            return nullptr;
        }
        else
        {
            test_num=head->val;
        }
        ListNode* head_s=head;
        while(head->next!=nullptr)
        {
            if(head->next->val==test_num)
            {
                head->next=head->next->next;
            }
            else
            {
                head=head->next;
                test_num=head->val;
            }
        }
        return head_s;
    }
};
int main()
{
    ListNode* head=new ListNode(1);
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