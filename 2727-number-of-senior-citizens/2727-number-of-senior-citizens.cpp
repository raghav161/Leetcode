class Solution {
public:
    int countSeniors(vector<string>& a) {
        int count=0;
        for(int i=0;i<a.size();i++)
        {
            string x = a[i];
            int a = int(x[11] - 48)*10 + int(x[12] - 48);
            if(a>60)
                count++;
        }
        return count;
    }
};