class OrderedStream {
public:
    vector<string> s;
    int i=1;
    OrderedStream(int n) {
        s.resize(n+1);
    }
    
    vector<string> insert(int idKey, string value) {
        s[idKey]=value;
        vector<string> ans;
        while(i<s.size() and s[i].size())
        {
            ans.push_back(s[i]);
            i++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */