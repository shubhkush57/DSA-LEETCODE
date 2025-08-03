class Solution {
public:
    bool solver(string &s, string &p, int i, int j, vector<vector<int>>& dp) {
        int n = s.size(), m = p.size();

        // Both strings finished
        if (i >= n && j >= m) return true;
        // Only pattern left: must be all '*' wildcards in proper positions
        if (i >= n) {
            // Pattern must allow matching empty string
            while (j+1 < m && p[j+1] == '*') j += 2;
            return j == m;
        }
        // Pattern finished but s has characters left: not a match
        if (j >= m) return false;

        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        // ---- CORRECTION STARTS HERE: Block handling '*'
        if (j+1 < m && p[j+1] == '*') {
            // Option 1: skip char+*, i.e., use zero of them
            ans = solver(s, p, i, j+2, dp);
            // Option 2: first character matches, use one or more
            if (s[i] == p[j] || p[j] == '.') {
                ans = ans || solver(s, p, i+1, j, dp);
            }
        } else {
            // Normal character match or '.'
            if (s[i] == p[j] || p[j] == '.') {
                ans = solver(s, p, i+1, j+1, dp);
            } else {
                ans = false;
            }
        }
        // ---- CORRECTION ENDS HERE

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        // Correction: Use n+1, m+1 for safe indexing
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solver(s, p, 0, 0, dp);
    }
};
