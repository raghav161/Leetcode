class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long ans=0, skillval=skill.front()+skill.back();
        int l=0, r=skill.size()-1;
        while(l<r)
        {
            long long currval=skill[l]+skill[r];
            if(currval!=skillval)
                return -1;
            ans+=(skill[l]*skill[r]);
            l++;
            r--;
        }
        return ans;
    }
};