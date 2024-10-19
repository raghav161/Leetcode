class Encrypter {
public:
    unordered_map<char, string> m;
    unordered_map<string, int> dict;
    Encrypter(vector<char>& k, vector<string>& v, vector<string>& d) {
        int n = k.size();
        for (int i = 0; i < n; i++)
            m[k[i]] = v[i];
        n = d.size();
        for (int i = 0; i < n; i++)
            dict[encrypt(d[i])]++;  
    }

    string encrypt(string s) {
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (m.find(s[i]) == m.end()) 
                return "";
            ans += m[s[i]];
        }
        return ans;
    }

    int decrypt(string s) {
        if (dict.find(s) == dict.end()) 
            return 0;
        return dict[s];
    }
};


/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */