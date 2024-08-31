class Solution {
public:
    unordered_set<string> combinations;
    string ans = "";
    bool f(string& curr, int num, int k, int n)
    {
        if(combinations.size()==num)
        {
            ans = curr;
            return 1;
        }
        string s = curr.substr(curr.length() - n + 1, n - 1);
        for(int i=0;i<k;i++)
        {
            string temp = s + to_string(i);
            curr += to_string(i);
            if(combinations.find(temp)==combinations.end())
            {
                combinations.insert(temp);
                if(f(curr, num, k, n))
                    return true;
                combinations.erase(temp);
            }
            curr.pop_back();
        }
        return 0;
    }
    string crackSafe(int n, int k)
    {
        string curr = "";
        for (int i = 0; i < n; i++)
            curr += "0";
        int num = pow(k, n);
        combinations.insert(curr);
        f(curr, num, k, n);
        return ans;
    }
};