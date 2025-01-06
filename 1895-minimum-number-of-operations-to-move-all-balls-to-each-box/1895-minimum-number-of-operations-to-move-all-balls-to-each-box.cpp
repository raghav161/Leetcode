class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        for(int i=0;i<boxes.size();i++){
            int pointer=0, count=0;
            while(pointer<boxes.size()){
                if(boxes[pointer]=='1') 
                    count += abs(pointer-i);
                pointer++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};