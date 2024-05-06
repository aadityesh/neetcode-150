class Solution {
public:
    // bool isPalindrome(string s) {

    //     int i = 0;
    //     int j = s.length() - 1;

    //     while (i < j) {
    //         if (s[i] != s[j])
    //             return false;
    //         i++;
    //         j--;
    //     }

    //     return true;
    // }

    string longestPalindrome(string s) {

        int n = s.length();
        int currLen = 0;

        string res = "";

        // if (n <= 2) {
        //     return s.substr(0, 1);
        // }

        for (int i = 0; i < n; i++) {

            int left = i;
            int right = i;

            while ((left >= 0 && right < n) && (s[left] == s[right])) {

                if (right - left + 1 > currLen) {
                    currLen = right - left + 1;
                    res = s.substr(left, currLen);
                }

                left--;
                right++;
            }
            left = i;
            right = i + 1;
            while ((left >= 0 && right < n) && (s[left] == s[right])) {

                if (right - left + 1 > currLen) {
                    currLen = right - left + 1;
                    res = s.substr(left, currLen);
                }

                left--;
                right++;
            }
        }

        return res;
    }
};