class Solution {
    int findArea(int x1, int y1, int x2, int y2, vector<vector<int>>& points) {
        for (auto i : points) {
            int x = i[0], y = i[1];
            if ((x == x1 || x == x2) && (y == y1 || y == y2))
                continue;
            else if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
                return -1;
            else if (x >= x2 && x <= x1 && y >= y2 && y <= y1)
                return -1;
            else if (x >= x2 && x <= x1 && y >= y1 && y <= y2)
                return -1;
            else if (x >= x1 && x <= x2 && y >= y2 && y <= y1)
                return -1;
        }
        int area = abs(x2 - x1) * abs(y2 - y1);
        return area > 0 ? area : -1;
    }

public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size(), result = -1;
        set<pair<int, int>> st;
        for (auto i : points)
            st.insert({i[0], i[1]});
        for (auto i : points) {
            for (auto j : points) {
                if (i != j) {
                    int x1 = i[0], y1 = i[1], x2 = j[0], y2 = j[1];
                    if (st.find({x1, y2}) != st.end() && st.find({x2, y1}) != st.end())
                        result = max(result, findArea(x1, y1, x2, y2, points));
                }
            }
        }
        return result;
    }
};