class Solution {
public:
    bool rotateString(string p, string q) {

        int n = p.length();
        int m = q.length();

        if (n != m)
            return false;

        p += p;
        n = p.length();

        int i = 0;
        while (i < n) {
            string sub = p.substr(i, m);
            if (sub == q)
                return true;

            i++;
        }
        return false;
    }
};