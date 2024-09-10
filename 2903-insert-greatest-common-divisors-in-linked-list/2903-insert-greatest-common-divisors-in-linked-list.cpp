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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp=head;
        while(temp->next)
        {
            ListNode* a=temp;
            ListNode* b=temp->next;
            int q=a->val;
            int w=b->val;
            int c=__gcd(q, w);
            ListNode* d=new ListNode(c);
            d->next=temp->next;
            temp->next=d;
            temp=temp->next->next;
        }
        return head;
    }
};