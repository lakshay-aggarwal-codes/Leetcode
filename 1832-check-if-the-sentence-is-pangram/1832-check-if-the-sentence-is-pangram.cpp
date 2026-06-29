    class Solution {
    public:
        bool checkIfPangram(string s) {
            vector<int>freq(26);
            for(int  i=0;i < s.size();i++){ 
                freq[s[i] -'a']++;
            }
            for(int x : freq){
                if(x == 0) return false;
            }
            return true;
        }
    };