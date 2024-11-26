class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in(n+1);
		for(auto edge:edges)
            in[edge[1]]++;
        int ans=0, count=0;
		for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                count++;
                ans=i;
            }
        }
        if(count>1)
            return -1;
        return ans;
    }
    
};