class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& array) {
        int i, currow = 0, curcol = 0;
        vector<int> ans;
        int row=array.size(), col=array[0].size();
        while(currow < row && curcol < col)
        {
            for(i = curcol; i < col; i++)
                ans.push_back(array[currow][i]);
            currow++;
            for(i = currow; i < row; ++i)
                ans.push_back(array[i][col-1]);
            col--; 
            if(currow < row)
            { 
                for(i = col-1; i >= curcol; --i)
                    ans.push_back(array[row-1][i]);
                row--; 
            }
            if(curcol < col)
            { 
                for(i = row-1; i >= currow; --i)
                    ans.push_back(array[i][curcol]);
                curcol++;
            }
        }
        return ans;
    }
};