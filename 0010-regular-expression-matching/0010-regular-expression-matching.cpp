class Solution {
public:
    bool isMatch(string s, string p) {
        
         unordered_map<string, bool> memo;

        return isMatchHelper(s, p, memo);
    }

private:
    bool isMatchHelper(const string& s, const string& p, unordered_map<string, bool>& memo) {
        // Check if the result has already been computed
        string key = s + "-" + p;
        if (memo.count(key))
            return memo[key];

        // Base case: pattern is empty
        if (p.empty())
            return s.empty();

        bool match = false;

        // Check if the second character of the pattern is '*'
        if (p.length() > 1 && p[1] == '*') {
            // Case 1: Skip the current pattern character and '*'
            match = isMatchHelper(s, p.substr(2), memo);

            // Case 2: Check if the current string character matches the pattern character (or the pattern is a dot)
            if (!match && !s.empty() && (s[0] == p[0] || p[0] == '.'))
                match = isMatchHelper(s.substr(1), p, memo);
        }
        else {
            // Check if the current string character matches the pattern character (or the pattern is a dot)
            if (!s.empty() && (s[0] == p[0] || p[0] == '.'))
                match = isMatchHelper(s.substr(1), p.substr(1), memo);
        }

        // Store the computed result in the memoization map
        memo[key] = match;

        return match;
    }
};