class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end()), visited;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push({0, startGene});
        string tr="ACGT";
        while(!pq.empty())
        {
            auto s=pq.top().second;
            auto count=pq.top().first;
            pq.pop();
            if(s==endGene)
                return count;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<s.size();j++)
                {
                    string temp=s;
                    temp[j]=tr[i];
                    if(st.count(temp) && visited.count(temp)==0)
                    {
                        visited.insert(temp);
                        pq.push({count+1, temp});
                    }
                }
            }
        }
        return -1;
    }
};