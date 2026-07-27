class Solution {
public:
    vector<int> arr = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        solve(0, turnedOn, 0, 0, ans);
        return ans;
    }

 void solve(int index, int rem, int hr, int min, vector<string>& ans) {
    if (rem < 0)
        return;
    if (hr > 11 || min > 59) {
        return;
    }
    if (index == 10 && rem == 0) {
        string s = to_string(hr) + ":" + to_string(min);
        if (min < 10) {
            s = to_string(hr) + ":0" + to_string(min);
        }
        ans.push_back(s);
        return;
    }
    if (index == 10) {
        if (rem != 0) {
            return;
        }
    }
    if (index < 4) {
        int newHr = arr[index] + hr;
        solve(index + 1, rem - 1, newHr, min,ans);
    } else if (index >= 4 && index <= 9) {
        int newMn = arr[index] + min;
        solve(index + 1, rem - 1, hr, newMn,ans);
    }

    solve(index + 1, rem, hr, min,ans);
}
};