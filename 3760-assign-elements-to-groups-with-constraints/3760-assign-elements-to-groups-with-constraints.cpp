class Solution {
public:
    int f(int n, unordered_map<int, int>& mp){
        int k=INT_MAX;
        for(int i=1;i*i<=n;i++){
            if(n%i==0 and mp.count(i))
                k=min(k, mp[i]);
            if(i!=n/i and n%i==0 and mp.count(n/i))
                k=min(k, mp[n/i]);
        }
        return k!=INT_MAX ? k:-1;
    }

    vector<int> assignElements(vector<int>& groups, vector<int>& elements){
        unordered_map<int, int> mp;
        for(int i=0;i<elements.size();i++){
            if(mp.count(elements[i])==0) 
                mp[elements[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<groups.size();i++)
            ans.push_back(f(groups[i], mp));
        return ans;
    }
};