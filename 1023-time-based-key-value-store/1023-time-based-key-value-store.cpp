class TimeMap {
public:
    unordered_map<string, map<int, string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto x=mp[key].upper_bound(timestamp);
        if(x==mp[key].begin())
            return "";
        return prev(x)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */