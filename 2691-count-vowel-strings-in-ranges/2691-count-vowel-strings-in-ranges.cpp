class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> st={'a', 'e', 'i', 'o', 'u'};
        vector<int> temp(words.size()+1);
        for(int i=0;i<words.size();i++)
        {
            string a=words[i];
            if(st.count(a[0]) and st.count(a[a.size()-1]))
                temp[i+1]=1;
        }
        for(int i=1;i<temp.size();i++)
            temp[i]+=temp[i-1];
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
            ans.push_back(temp[queries[i][1]+1] - temp[queries[i][0]]);
        return ans;
    }
};