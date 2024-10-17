class MagicDictionary {
public:
    unordered_set<string> st;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        unordered_set<string> temp(dictionary.begin(), dictionary.end());
        st=temp;
    }
    
    bool search(string s) {
        for(int i=0;i<s.size();i++)
        {
            char word=s[i];
            for(int j=0;j<26;j++)
            {
                s[i]='a'+j;
                if(s[i]!=word and st.count(s))
                    return 1;
            }
            s[i]=word;
        }
        return 0;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */