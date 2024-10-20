class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        
        int i=0, count=s.length();
        while(i<count){
            if(s==goal){
                return true;
            }
            s.push_back(s[0]);
            s.erase(s.begin());
            i++;
        }

        return false;
    }
};