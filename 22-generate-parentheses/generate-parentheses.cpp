class Solution {
private:
    void helper(vector<string>& res, string s, int open, int close, int n) {

        if (s.length() == 2 * n) {
            res.push_back(s);
            return;
        }

        if (open < n) {
            helper(res, s + '(', open + 1, close, n);
        }

        if (close < open) {
            helper(res, s + ')', open, close + 1, n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        helper(res, "", 0, 0, n);

        return res;
    }
};