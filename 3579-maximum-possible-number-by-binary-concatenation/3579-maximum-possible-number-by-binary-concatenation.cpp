class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        auto cmp = [](int a, int b) {
            string binA = bitset<32>(a).to_string();  
            string binB = bitset<32>(b).to_string();  
            binA = binA.substr(binA.find('1'));  
            binB = binB.substr(binB.find('1'));  
            return binA + binB > binB + binA;
        };
        sort(nums.begin(), nums.end(), cmp);
        string ans = "";
        for(auto num:nums)
        {
            string bin = bitset<32>(num).to_string();  
            ans += bin.substr(bin.find('1'));  
        }
        return stoi(ans, 0, 2);
    }
};