class Solution {
public:
    int myAtoi(string s) {

        int n = s.length();
        int i = 0;
        bool neg = false;
        long res = 0;

        while (i < n && s[i] == ' ')
            i++;
        if (s[i] == '-') {
            neg = true;
            i++;
        } else if (s[i] == '+')
            i++;

        while (i < n) {

            int value = s[i] - '0';

            if (value >= 0 && value <= 9) {

                res = res * 10 + value;
                i++;

                if (res > INT_MAX && neg)
                    return INT_MIN;
                else if (res > INT_MAX && !neg)
                    return INT_MAX;

            } else
                break;
        }

        if (neg)
            return -(int)res;

        return (int)res;
    }
};