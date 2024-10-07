class Solution {
public:
    int minLength(string s) {
        stack<char> q;
        int count=0;
        for(auto i:s)
        {
            if(q.empty())
            {
                q.push(i);
                continue;
            }
            char x=q.top();
            if((x=='A' and i=='B') or (x=='C' and i=='D'))
            {
                count++;
                q.pop();
                continue;
            }
            q.push(i);
        }
        return s.size()-2*count;
    }
};