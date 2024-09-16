class Solution {
public:
    int findMinDifference(vector<string>& time) {
        sort(time.begin(), time.end());
        int mini = INT_MAX;
        string last=to_string(stoi(time[0].substr(0, 2))+24) + ":" + time[0].substr(3, 5);
        time.push_back(last);
        for(int i=0;i<time.size()-1;i++)
        {
            int a = stoi(time[i].substr(0, 2));
            int b = stoi(time[i+1].substr(0, 2));
            int a1 = stoi(time[i].substr(3, 5));
            int b1 = stoi(time[i+1].substr(3, 5));
            if(b==a)
                mini = min(mini, b1-a1);
            else
                mini = min(mini, b1 + (60-a1) + (60*(b-a-1)));
        }
        return mini;
    }
};
