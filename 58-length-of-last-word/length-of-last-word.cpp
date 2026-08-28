class Solution {
public:
    int lengthOfLastWord(string s) {
     int n = s.size();int ans =0;
     for(int i = n-1;i>=0;i--){
        if(s[i] != ' '){
            ans++;
        }
        if(ans>0 && s[i] == ' '){
            return ans;
        }
     }   
     return ans;
    }
};