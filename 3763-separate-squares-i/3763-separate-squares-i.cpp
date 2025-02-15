class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total_area = 0, high = 0, low = 0;
        for (int i = 0; i < squares.size(); ++i) {
            total_area += (double)(squares[i][2] * (double)squares[i][2]);
            high = max(high, (double)((double)squares[i][1] + (double)squares[i][2]));
        }
        double target = total_area / 2;
        auto calc_area = [&](double line) {
            double area = 0;
            for (auto& sq : squares) {
                double st = sq[1], ed = (double)sq[1] + (double)sq[2];
                if (line > st)
                    area += ((double)min(line, ed) - st) * (double)sq[2];
            }
            return area;
        };
        while (high - low > 1e-5) {
            double mid = ((double)high + (double)low) / 2;
            if (calc_area(mid) < target)
                low = mid;
            else
                high = mid;
        }

        return high;
    }
};