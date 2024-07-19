class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> rowmin(rows, INT_MAX);
        vector<int> colmax(cols, INT_MIN);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                rowmin[i]=min(rowmin[i], matrix[i][j]);
                colmax[j]=max(colmax[j], matrix[i][j]);
            }
        }
        vector<int> ans;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(rowmin[i]==matrix[i][j] && colmax[j]==matrix[i][j])
                    ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};