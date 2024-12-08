class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0]));
        int suffix[] = new int[events.length];
        suffix[events.length - 1] = events[events.length - 1][2];

        int ans = 0;
        for(int i = events.length - 2; i >= 0 ; i --) {
            suffix[i] = Math.max(suffix[i + 1], events[i][2]); }

        for(int i = 0; i < events.length; i ++) {
            int left = i + 1, right = events.length - 1;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if(events[mid][0] <= events[i][1]) 
                    left = mid+1;
                else 
                    right = mid-1;
            }  
            if(right+1 < events.length)
                ans = Math.max(ans, events[i][2] + suffix[right+1]);  
            ans = Math.max(ans, events[i][2]);           
        }
        
        return ans;
    }
}
/*
Collaboration session - Raghav Bansal & Akshavya Aggarwal
wrong ans--haa aaya prompt mereko
// yeh h asli code mera
// purana toh gpt se poocha tha--achaa--haa
// dry run kra ?
// TLE aa rha h
// yaani looping statements mein issue hora h--han--lemme see
ye right bound galat ho sakta hai...imagine krke dekh
Maine sort toh maara tha waise....par start time ke base pr---ek kaam krta hu end time pr maarta hu sort

bhai random tukke thodi marenge ab hum
pehle algo bna uskoal dgrrun kr--algo mera yehi h binary search with answer waala
-- min start aur max strart leke check krra hu ke kis start time par max vcalue aa rha h---achaa
haa--shayad time ke bajaye value par maarna chahiye
--usse thoda sense bnjaye shyad--krke dekh try--wait --par usme wahi panga h na main toh apne ko overlapping intervals dhoodne h   

han voi toh logic sahi nhi hai bro tera
kaafi close hai bas ek cheez aur soch--Achaa--han
goddddddddddddd
toh aryan hi h
sach hi kehdia
tedi mun\U0001f923\U0001f923di \U0001f923\U0001f923\U0001f923\U0001f923\U0001f923\U0001f923
wrbongc aagya 

ye kya hua
pehle toh accept aya tha?

woh run krne par aaya tha
abh submit kra h wrongf aagya--kitne chale?
33/63--abey yr --:`)--test case daaal h abhi--acha--abh kr run
[[19,36,24],[70,90,11],[61,78,36],[38,38,70],[39,83,72],[8,46,5],[64,69,49],[88,89,39],[53,77,24],[35,76,26]]
yehle testcase--acha ruk

bhai tere logic hi theek nhi lg rha mujhe
ques kya hai vo bta
ruk call hi krta hu--:`)
*/