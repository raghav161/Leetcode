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
    int length(ListNode* head){
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int len = length(head); 
        ListNode* curr = head;
        ListNode* prev = head;
        int width = len/k;
        int rem = len%k;
        for(int i=0;i<k;i++)
        {
            ans.push_back(curr);
            int end=width;
            if(i<rem)
                end++;
            for(int j=0;j<end;j++)
            {
                prev = curr;
                curr = curr->next;
            }
            if(prev)
                prev->next = NULL;
        }
        return ans;
    }
};