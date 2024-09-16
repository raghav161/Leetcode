class Solution {
public:
    int findMinDifference(vector<string>& time) {
        sort(time.begin(), time.end());
        int minDiff = INT_MAX;
        int x = stoi(time[0].substr(0, 2));
        string last=to_string(x+24) + ":" + time[0].substr(3, 5);
        time.push_back(last);
        for(int i=0;i<time.size()-1;i++)
        {
            int a = stoi(time[i].substr(0, 2));
            int b = stoi(time[i+1].substr(0, 2));
            int a1 = stoi(time[i].substr(3, 5));
            int b1 = stoi(time[i+1].substr(3, 5));
            int value = b1 + (60-a1) + (60*(b-a-1));
            if(b==a)
                minDiff = min(minDiff, b1-a1);
            else
                minDiff = min(minDiff, value);
        }
        // int a = stoi(time[0].substr(0, 2));
        // int b = stoi(time[time.size() - 1].substr(0, 2));
        // int a1 = stoi(time[0].substr(3, 5));
        // int b1 = stoi(time[time.size() - 1].substr(3, 5));
        // int value = a1 + 60 - b1 + (60 * (24 + a - b - 1));
        // return min(minDiff, value);
        return minDiff;
    }
};
