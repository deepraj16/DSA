class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
    
        string new_s = s + "#" + rev;
        int n = new_s.size();
    
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && new_s[i] != new_s[j]) {
                j = lps[j - 1];
            }
            if (new_s[i] == new_s[j]) {
                j++;
            }
            lps[i] = j;
        }
        
       
        int longest_prefix_len = lps[n - 1];
        
        return rev.substr(0, s.size() - longest_prefix_len) + s;
    }
};
