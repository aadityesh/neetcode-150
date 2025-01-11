
class Solution {
public:
    bool alphanumeric(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            return true;
        if (ch >= 'a' && ch <= 'z')
            return true;
        if (ch >= '0' && ch <= '9')
            return true;

        return false;
    }
    bool isPalindrome(string s) {

        int n = s.length();
        int L = 0;
        int R = n - 1;

        while (L < R) {

            char left = toupper(s[L]);
            char right = toupper(s[R]);

            if (!alphanumeric(left)) {
                L++;
                continue;
            }

            if (!alphanumeric(right)) {
                R--;
                continue;
            }

            if (left != right)
                return false;

            L++;
            R--;
        }

        return true;

        /*string temp = "";
        while (L <= R) {
            if (isalnum(s[L]))
                temp += tolower(s[L]);
            L++;
        }
        cout << temp << endl;
        string temp_cpy = temp;
        reverse(temp.begin(), temp.end());

        return temp_cpy == temp;*/
    }
};