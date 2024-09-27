class MyCalendarThree 
{
    int maxCnt = 0;
    map<int, int> mp;
public:    
    int book(int start, int end) 
    {
        mp[start]++;
        mp[end]--;
        int cnt = 0;
        for(auto it:mp) 
        {
            cnt += it.second;
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;   
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */