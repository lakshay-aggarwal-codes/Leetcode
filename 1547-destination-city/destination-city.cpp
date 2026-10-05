class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans = "";
        unordered_set<string> m;
        int n = paths.size();
        if(n==1){
            return paths[0][1];
        }
        for (int i = 0; i < n; i++) {
            m.insert(paths[i][0]);
        }
        for(int i = 0; i < n; i++){
            if(m.find(paths[i][1]) == m.end()){
                return (paths[i][1]);
            }
        }
        return "";
    }
};