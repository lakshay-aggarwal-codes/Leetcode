class Solution {
public:
    int minBitFlips(int start, int goal) {
     int ans = 0;
     int x = start^goal;
     while(x){
        x &= x-1;
        ans++;
     }return ans;
    }
};