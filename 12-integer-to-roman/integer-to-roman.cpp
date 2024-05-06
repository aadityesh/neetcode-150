class Solution {
public:
    string intToRoman(int num) {

        vector<pair<int, string>> vec = {
            {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
            {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
            {500, "D"}, {900, "CM"}, {1000, "M"}};

        int n = vec.size();
        string res = "";

        for (int i = n - 1; i >= 0; i--) {
            auto it = vec[i];
            if (num / it.first > 0) {
                int count = floor(num / it.first);
                while (count--)
                    res += it.second;
                num = num % it.first;
            }
        }

        return res;
    }
};