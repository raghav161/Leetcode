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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head, *curr = head -> next, *nxt;
        if(curr->next == NULL) 
            return {-1 , -1};
        nxt=curr->next;
        vector<int> v;
        int i = 0;
        while(nxt)
        {
            if(curr->val > prev->val && curr->val > nxt->val)
                v.push_back(i);
            else if(curr->val < prev->val && curr->val < nxt->val)
                v.push_back(i);
            prev = curr; 
            curr = nxt;
            nxt = nxt->next;
            i++;
        }
        if(v.size() < 2) 
            return {-1 , -1};
        int mn = INT_MAX;
        for(int j=0;j<v.size()-1;j++)
            mn = min(mn , v[j+1] - v[j]);
        int mx = v[v.size()-1] - v[0];
        return {mn , mx};
    }
};