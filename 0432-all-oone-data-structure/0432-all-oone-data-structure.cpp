class AllOne {
public:
    unordered_map<string, int> mp;
    set<pair<int, string>> st;
    AllOne() {
        
    }
    
    void inc(string key) {
        st.erase({mp[key], key});
        mp[key]++;
        st.insert({mp[key], key});
    }
    
    void dec(string key) {
        st.erase({mp[key], key});
        mp[key]--;
        if(mp[key]==0)
            mp.erase(key);
        else
            st.insert({mp[key], key});
    }
    
    string getMaxKey() {
        if(!st.empty())
            return st.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if(!st.empty())
            return st.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */