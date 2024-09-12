class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(int i=0;i<allowed.size();i++)
            st.insert(allowed[i]);
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            int flag=1;
            for(auto j:words[i])
            {
                if(st.count(j)==0)
                {
                    flag=0;
                    break;
                }
            }
            count+=flag;
        }
        return count;
    }
};