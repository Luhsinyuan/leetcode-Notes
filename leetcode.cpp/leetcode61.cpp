#include"iostream"
#include"vector"
#include"algorithm"
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
//solution 1
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)
        {
            return nullptr;
        }
        ListNode* head_move=head;
        ListNode* result=new ListNode(0);
        ListNode* result_to_return=result;
        vector<int> numlist;
        while(head_move!=nullptr)
        {
            numlist.push_back(head_move->val);
            head_move=head_move->next;
        }
        if(k>numlist.size())
        {
            k=k%numlist.size();
        }
        vector<int>::iterator it=numlist.begin();
        for(int i=0;i<numlist.size()-k;i++)
        {
            it++;
        }
        reverse(numlist.begin(),it);
        /*for(int i=0;i<numlist.size();i++)
        {
            cout<<numlist[i]<<endl;
        }*/
        reverse(it,numlist.end());
        /*for(int i=0;i<numlist.size();i++)
        {
            cout<<numlist[i]<<endl;
        }*/
        reverse(numlist.begin(),numlist.end());
        /*for(int i=0;i<numlist.size();i++)
        {
            cout<<numlist[i]<<endl;
        }*/
        for(int i=0;i<numlist.size();i++)
        {
            ListNode* temp=new ListNode(numlist[i]);
            result->next=temp;
            result=result->next;
        }
        result->next=nullptr;
        return result_to_return->next;
    }
};
int main()
{
    ListNode* head=new ListNode(1);
    ListNode* head1=new ListNode(2);
    ListNode* head2=new ListNode(3);
    ListNode* head3=new ListNode(4);
    ListNode* head4=new ListNode(5);
    head->next=head1;
    head1->next=head2;
    head2->next=head3;
    head3->next=head4;
    Solution s;
    ListNode* current=s.rotateRight(head,2);
    while(current!=nullptr)
    {
        cout<<current->val<<endl;
        current=current->next;
    }
    system("pause");
    return 0;
}
