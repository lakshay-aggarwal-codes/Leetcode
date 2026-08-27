class Solution {
public:
    static bool comparator(string a, string b) {
        int sp1 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == ' ') {
                sp1 = i;
                break;
            }
        }
        string s1 = "";
        for (int i = 1 + sp1; i < a.size(); i++) {
            s1 += a[i];
        }

        int sp2 = 0;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] == ' ') {
                sp2 = i;
                break;
            }
        }
        string s2;
        for (int i = 1 + sp2; i < b.size(); i++) {
            s2 += b[i];
        }

        if (s1 != s2) {
            return s1 < s2;
        }

        string c = "";
        string d = "";
        for (int i = 0; i < sp1; i++) {
            c += a[i];
        }
        for (int i = 0; i < sp2; i++) {
            d += b[i];
        }
        return c < d;
    }

 vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> letter;
    vector<string> digit;
    int n = logs.size();

    for (int i = 0; i < n; i++) {
        string s1 = logs[i];
        if (isdigit(s1[s1.size() - 1])) {
            digit.push_back(s1);
        } else
            letter.push_back(s1);
    }

    vector<string> ans;
    ans = letter;
    sort(ans.begin(), ans.end(), comparator);
    for (int i = 0; i < digit.size(); i++) {
        ans.push_back(digit[i]);
    }
    return ans;
}
}
;