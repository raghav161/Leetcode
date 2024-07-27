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
class Solution 
{
private:
    int length(ListNode* head)
    {
        int count=0;
        ListNode* h=head;
        while(h)
        {
            count++;
            h=h->next;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL)
            return NULL;
        if(k==0 || head->next==NULL)
            return head;
        int a=length(head);
        if(k>a)
            k=k%a;
        ListNode* t=head;
        while(t->next->next!=NULL)
            t=t->next;
        ListNode* t1=t->next;
        t->next=NULL;
        t1->next=head;
        head=t1;
        return rotateRight(head, k-1);
    }
};