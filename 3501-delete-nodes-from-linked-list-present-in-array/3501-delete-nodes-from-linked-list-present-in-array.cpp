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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        auto h=new ListNode(-1);
        auto b=h;
        while(head)
        {
            if(st.find(head->val)==st.end())
            {
                b->next=head;
                b=b->next;
            }
            head=head->next;
        }
        b->next=NULL;
        return h->next;
    }
};