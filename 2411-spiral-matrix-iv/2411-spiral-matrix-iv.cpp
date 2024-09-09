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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int left=0, right=n-1, top=0, bottom=m-1;
        ListNode* temp=head;
        while(temp and top<=bottom and left<=right)
        {
            for(int i=left;i<=right and temp;i++)
            {
                ans[top][i] = temp->val;
                temp = temp->next;
            }
            top++;
            if(top>bottom or temp==NULL)
                break;
            for(int i=top;i<=bottom and temp;i++)
            {
                ans[i][right] = temp->val;
                temp = temp->next;
            }
            right--;
            if(left>right or temp==NULL)
                break;
            for(int i=right;i>=left and temp;i--)
            {
                ans[bottom][i] = temp->val;
                temp = temp->next;
            }
            bottom--;
            if(top>bottom or temp==NULL)
                break;
            for(int i=bottom;i>=top and temp;i--)
            {
                ans[i][left] = temp->val;
                temp = temp->next;
            }
            left++;
        }
        return ans;
    }
};