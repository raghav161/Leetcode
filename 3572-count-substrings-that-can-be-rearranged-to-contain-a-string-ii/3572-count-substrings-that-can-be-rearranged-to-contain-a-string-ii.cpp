class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> mp1(26), mp2(26);
        int count=0;
        for(auto c:word2)
            mp1[c-'a']++;
        for(int i=0;i<26;i++)
        {
            if(mp1[i]>0)
                count+=mp1[i];
        }
        long long ans=0;
        int left=0;
        for(int right=0;right<word1.length();right++)
        {
            mp2[word1[right]-'a']++;
            if(mp1[word1[right]-'a']>0 and mp2[word1[right]-'a']<=mp1[word1[right]-'a'])
                count--;
            while(count==0)
            {
                ans+=word1.length()-right;
                if(mp1[word1[left]-'a']>0 and mp2[word1[left]-'a']<=mp1[word1[left]-'a'])
                    count++;
                mp2[word1[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};