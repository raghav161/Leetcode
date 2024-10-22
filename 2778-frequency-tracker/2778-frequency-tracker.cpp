class FrequencyTracker {
public:
    map<int, int> mp;
    map<int, set<int>> mp2;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int initial=mp[number];
        mp2[initial].erase(number);
        mp[number]++;
        mp2[mp[number]].insert(number);
    }
    
    void deleteOne(int number) {
        int initial=mp[number];
        if(initial==0)
            return;
        mp2[initial].erase(number);
        mp[number]--;
        if(mp[number]==0)
            mp.erase(number);
        mp2[mp[number]].insert(number);
    }
    
    bool hasFrequency(int frequency) {
        return mp2[frequency].size();
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */