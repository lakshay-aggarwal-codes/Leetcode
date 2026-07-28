class Solution {
public:
    void rev(string &s){
       int st = 0;
        int end = s.size() - 1;

        while (st <= end) {
           swap(s[st], s[end]);
            st++;
            end--;
        }   
    }
    string smallestPalindrome(string s) {
        string ans = "";
        vector<int>freq(26);
        for(char c: s){
            freq[c-'a']++;
        }
        string first = "";
        string mid = "";
        for(int i = 0 ;i< 26;i++){
            if(freq[i] %2 != 0){
                mid = 'a' + i;
            }
            freq[i] /=2;
            first += string(freq[i], 'a'+i);
        }

        string second = first;
        rev(second);
        ans = first + mid + second; 
        return ans;
    }
};