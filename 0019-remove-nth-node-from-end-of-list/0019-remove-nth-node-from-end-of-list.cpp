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
class Solution {
public:
    int length(ListNode* head)
    {
        if(head==NULL)
            return 0;
        int count=0;
        ListNode* temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head==NULL)
            return NULL;
        if(length(head)==n)
            return head->next;
        if(head->next==NULL and n==1)
            return NULL;
        ListNode* q=head;
        for(int i=0;i<length(head)-n-1;i++)
            q=q->next;
        ListNode* p=q->next;
        if(p)
            q->next=p->next;
        return head; 
    }
};