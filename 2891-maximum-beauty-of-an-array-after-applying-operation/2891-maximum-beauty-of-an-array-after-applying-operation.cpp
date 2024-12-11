class Solution {
public:
    int maximumBeauty(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int i = 0, n = A.size();
        for(int j = 0; j < n; j++)
        {
            if(A[j] - A[i] > k * 2)
                i++;
        }
        return n - i;
    }
};