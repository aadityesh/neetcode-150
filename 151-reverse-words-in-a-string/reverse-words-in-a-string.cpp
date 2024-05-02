class Solution {
public:
    string reverseWords(string str) {
        int n = str.length();
        int i = 0;
        int j = 0;
        string res;
        string sub;

        while (i < n) {

            while (i < n && str[i] == ' ')
                i++;
            if(i >= n) break;
            j = i+1;
            while (j < n && str[j] != ' ')
                j++;

            sub = str.substr(i, j - i);

            if (res.length() == 0)
                res = sub;
            else
                res = sub + " " + res;

            i = j+1;
        }

        return res;
    }
};