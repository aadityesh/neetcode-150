class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;

        int i = 0;
        int n = s.length();

        int res = 0;
        while (i < n) {

            if (s[i] == 'I' && s[i + 1] == 'V') {
                res += 4;
                i += 2;
                continue;
            }

            if (s[i] == 'I' && s[i + 1] == 'X') {
                res += 9;
                i += 2;
                continue;
            }

            if (s[i] == 'X' && s[i + 1] == 'L') {
                res += 40;
                i += 2;
                continue;
            }

            if (s[i] == 'X' && s[i + 1] == 'C') {
                res += 90;
                i += 2;
                continue;
            }

            if (s[i] == 'C' && s[i + 1] == 'D') {
                res += 400;
                i += 2;
                continue;
            }
            if (s[i] == 'C' && s[i + 1] == 'M') {
                res += 900;
                i += 2;
                continue;
            }

            else {
                res += umap[s[i]];
                i++;
            }
        }
        return res;
    }
};