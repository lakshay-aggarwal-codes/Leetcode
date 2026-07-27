class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
    vector<string> res;
        for(int h =0 ;h <12;h++){
            for(int min =0 ;min< 60;min++){
                if(__builtin_popcount(h) + __builtin_popcount(min) == turnedOn){
                    res.push_back(to_string(h) + (min<10 ? ":0" : ":") + to_string(min));
                }
            }
        }
        return res;
    }
};