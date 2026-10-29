class Solution {
public:
    int strStr(string haystack, string needle) { 
        int x = needle.size();
        if(haystack.size() < x)return -1;
        for(int i=0;i<= haystack.size() - x;i++){
            string curr = haystack.substr(i,x);
            if(curr== needle){
                return i;
            }
        }
        return -1;
    }
};