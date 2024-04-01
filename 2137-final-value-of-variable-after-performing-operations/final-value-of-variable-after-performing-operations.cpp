class Solution {
public:
    int finalValueAfterOperations(vector<string>& inp) {

        int x = 0;
        for (auto i : inp) {
            if (i == "X++" || i == "++X")
                x++;
            else
                x--;
        }
        return x;
    }
};