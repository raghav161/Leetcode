class TopVotedCandidate {
public:
    map<int, int> mp;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int count=0, ans=0;
        map<int, int> mp2;
        for(int i=0;i<persons.size();i++)
        {
            mp2[persons[i]]++;
            if(count<=mp2[persons[i]])
            {
                count=mp2[persons[i]];
                ans=persons[i];
            }
            mp[times[i]]=ans;
        }
    }
    
    int q(int t) {
        auto x=mp.upper_bound(t);
        x--;
        return x->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */