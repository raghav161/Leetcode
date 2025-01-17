class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int ans=0;
        for(auto it:d)
            ans=ans^it;
        if(ans==0)
            return 1;
        return 0;
    }
};