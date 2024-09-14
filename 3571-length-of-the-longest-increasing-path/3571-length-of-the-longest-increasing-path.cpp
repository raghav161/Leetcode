class Solution {
public:
    static bool cmp(vector<int>& x, vector<int>& y) {
        if (x[0] == y[0])
            return x[1] > y[1];
        return x[0] < y[0];
    }
    int lis_cal(vector<int>& arr)
    {
        vector<int> temp;
        for(auto i:arr)
        {
            auto it = lower_bound(temp.begin(), temp.end(), i) - temp.begin();
            if(it==temp.size())
                temp.push_back(i);
            temp[it]=i;
        }
        return temp.size();
    }
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int x_val = coordinates[k][0];
        int y_val = coordinates[k][1];
        sort(coordinates.begin(), coordinates.end(), cmp);
        vector<int> left, right;
        for (auto i : coordinates)
        {
            if (i[0] < x_val && i[1] < y_val)
                left.push_back(i[1]);
            if (i[0] > x_val && i[1] > y_val)
                right.push_back(i[1]);
        }
        int left_lis = lis_cal(left);
        int right_lis = lis_cal(right);
        return left_lis + right_lis + 1;
    }
};