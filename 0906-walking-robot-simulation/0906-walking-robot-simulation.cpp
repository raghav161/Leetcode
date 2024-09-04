class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> directions={0, 1, 0, -1, 0};
        unordered_set<string> st;
        for(auto i:obstacles)
            st.insert(to_string(i[0]) + "_" + to_string(i[1]));
        int x=0, y=0, direction=0, maxi=0;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]==-2)
                direction=(direction+3)%4;
            else if(commands[i]==-1)
                direction=(direction+1)%4;
            else
            {
                for(int j=0;j<commands[i];j++)
                {
                    int newX = x+directions[direction];
                    int newY = y+directions[direction+1];
                    if(st.find(to_string(newX) + "_" + to_string(newY))==st.end())
                    {
                        x=newX, y=newY;
                        maxi=max(maxi, x*x + y*y);
                    }
                    else
                        break;
                }
            }
        }
        return maxi;
    }
};
