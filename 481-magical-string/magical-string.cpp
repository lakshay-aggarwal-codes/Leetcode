class Solution {
public:
    int magicalString(int n) {
        if (n <= 0)
            return 0;

        if (n <= 3)
            return 1;

        string s = "122";
        int count = 1;

        int no = 1;
        int y = 2;
        int length = 3;

        while (length < n) {

            int pos = s[y] - '0';

            if (pos == 2) {
 
                if (no == 1) {

                    if (length + 2 <= n) {
                        s.push_back('1');
                        s.push_back('1');
                        length += 2;
                        count += 2;
                    }
                    else {
                        s.push_back('1');
                        length++;
                        count++;
                    }

                    no = 2;
                }

                else {

                    if (length + 2 <= n) {
                        s.push_back('2');
                        s.push_back('2');
                        length += 2;
                    }
                    else {
                        s.push_back('2');
                        length++;
                    }

                    no = 1;
                }
            }

            else {
 
                if (no == 1) {
                    s.push_back('1');
                    length++;
                    count++;
                    no = 2;
                }

                else {
                    s.push_back('2');
                    length++;
                    no = 1;
                }
            }

            y++;
        }

        return count;
    }
};