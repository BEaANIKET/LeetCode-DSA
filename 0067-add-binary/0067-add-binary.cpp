class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = 0;
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        while (i < a.length() && i < b.length()) {
            if (a[i] == '1' && b[i] == '1') {
                if (carry == 1) {
                    ans.push_back('1');
                    carry = 1;
                } else {
                    ans.push_back('0');
                    carry = 1;
                }
            } else if (a[i] == '1' && b[i] == '0' ||
                       a[i] == '0' && b[i] == '1') {
                if (carry == 1) {
                    ans.push_back('0');
                    carry = 1;
                } else {
                    ans.push_back('1');
                }
            } else {
                if (carry == 1) {
                    ans.push_back('1');
                    carry = 0;
                } else {
                    ans.push_back('0');
                }
            }

            i++;
        }

        while (i < a.length()) {
            if (carry == 1) {
                if (a[i] == '1') {
                    ans.push_back('0');
                    carry = 1;
                } else {
                    ans.push_back('1');
                    carry = 0;
                }
            } else {
                ans.push_back(a[i]);
            }

            i++;
        }

        while (i < b.length()) {
            if (carry == 1) {
                if (b[i] == '1') {
                    ans.push_back('0');
                    carry = 1;
                } else {
                    ans.push_back('1');
                    carry = 0;
                }
            } else {
                ans.push_back(b[i]);
            }

            i++;
        }

        if (carry == 1) {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};