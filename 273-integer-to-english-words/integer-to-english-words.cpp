class Solution {
public:
    // string findString(unordered_map<int, string>& umap, int a) {

    //     if (umap.find(a) != umap.end())
    //         return umap[a];

    //     string ans = "";
    //     ans += umap[(a / 10) * 10];
    //     ans += " ";
    //     ans += umap[a % 10];

    //     return ans;
    // }

    string getString(int n, unordered_map<int, string>& umap) {

        string res = "";
        int hundreds = n / 100;
        int last2Digits = n % 100;
        bool flag = 0;

        if (hundreds > 0) {
            res += (umap[hundreds] + " Hundred");
            flag = 1;
        }

        if (last2Digits == 0) {
            return res;
        }

        if (flag)
            res += " ";

        if (last2Digits <= 20) {
            res += (umap[last2Digits]);
        } else {

            flag = 0;
            int tens = last2Digits / 10;
            int ones = last2Digits % 10;

            if (tens) {
                res += umap[tens * 10];
                if (ones)
                    flag = 1;
            }

            if (flag)
                res += " ";

            if (ones)
                res += umap[ones];
        }

        return res;
    }
    
    string numberToWords(int num) {

        if (num == 0)
            return "Zero";

        unordered_map<int, string> umap;

        umap[1] = "One";
        umap[2] = "Two";
        umap[3] = "Three";
        umap[4] = "Four";
        umap[5] = "Five";
        umap[6] = "Six";
        umap[7] = "Seven";
        umap[8] = "Eight";
        umap[9] = "Nine";
        umap[10] = "Ten";

        umap[11] = "Eleven";
        umap[12] = "Twelve";
        umap[13] = "Thirteen";
        umap[14] = "Fourteen";
        umap[15] = "Fifteen";
        umap[16] = "Sixteen";
        umap[17] = "Seventeen";
        umap[18] = "Eighteen";
        umap[19] = "Nineteen";

        umap[20] = "Twenty";
        umap[30] = "Thirty";
        umap[40] = "Forty";
        umap[50] = "Fifty";
        umap[60] = "Sixty";
        umap[70] = "Seventy";
        umap[80] = "Eighty";
        umap[90] = "Ninety";

        vector<string> places = {"", " Thousand", " Million", " Billion"};

        string res = "";
        int digits = 0;
        int ind = 0;

        while (num) {

            digits = num % 1000;
            string temp = getString(digits, umap);

            if (temp.size() > 0) {
                if (res.size() == 0)
                    res = temp + places[ind];
                else {
                    temp = temp + places[ind];
                    res = temp + " " + res;
                }
            }

            num /= 1000;
            ind++;
        }

        return res;
    }
};