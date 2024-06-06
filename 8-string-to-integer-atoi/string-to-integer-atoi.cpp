class Solution {
public:
    int recursiveAtoi(string s, int i, int neg, int res) {

        if (i >= s.length() || s[i] < '0' || s[i] > '9')
            return neg * res;

        int integer = s[i] - '0';
        if ((res > (INT_MAX / 10)) || (res * 10 > (INT_MAX - integer)))
            return neg > 0 ? INT_MAX : INT_MIN;

        res = recursiveAtoi(s, i + 1, neg, ((res * 10) + integer));

        return res;
    }
    int myAtoi(string s) {

        int n = s.length();
        int neg = 1;

        int i = 0;
        while (s[i] == ' ')
            i++;
        if (s[i] == '-') {
            neg = -1;
            i++;
        } else if (s[i] == '+')
            i++;

        int result = recursiveAtoi(s, i, neg, 0);
        // result = neg ? -result : result;

        cout << INT_MAX << endl;

        return result;
    }
};