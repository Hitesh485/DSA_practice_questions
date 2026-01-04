class Solution {
public:
    // include exclude method
    void solve(vector<string> &ans, int n, int open, int close, string output)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(output);
            return;
        }

        // consider valid index of open bracket
        if (open > 0)
        {
            output.push_back('(');
            solve(ans, n, open-1, close, output);
            // backtrack
            output.pop_back();
        }

        // if at first time open > close, then in second time close > open definitly.
        if (close > open)
        {
            output.push_back(')');
            solve(ans, n, open, close-1, output);
            // backtrack
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n;
        int close = n;
        string output = "";
        solve(ans, n, open, close, output);
        return ans;
    }
};