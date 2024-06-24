class Solution {
private:
    void helper(vector<string>& res, string &s, int open, int close, int n) {

        if (s.length() == 2 * n) {
            res.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');
            helper(res, s, open + 1, close, n);
            s.pop_back();
        }

        if (close < open) {
            s.push_back(')');
            helper(res, s, open, close + 1, n);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        helper(res, curr, 0, 0, n);

        return res;
    }
};