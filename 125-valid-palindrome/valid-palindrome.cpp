
class Solution {
public:
    bool isPalindrome(string s) {

        int n = s.length();
        int L = 0;
        int R = n - 1;

        /* while (L < R) {

             char left = toupper(s[L]);
             char right = toupper(s[R]);

             if (!isalnum(left)) {
                 L++;
                 continue;
             }

             if (!isalnum(right)) {
                 R--;
                 continue;
             }

             if (left != right)
                 return false;

             L++;
             R--;
         }

         return true;*/

        string temp = "";
        while (L <= R) {
            if (isalnum(s[L]))
                temp += tolower(s[L]);
            L++;
        }
        cout << temp << endl;
        string temp_cpy = temp;
        reverse(temp.begin(), temp.end());

        return temp_cpy == temp;
    }
};