class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int n = s.size();
        map<char, int> mp; 
        int max_length = 0;

        while (r < n) {
            if (mp.count(s[r])) {
                l = max(l, mp[s[r]] + 1); // move left if duplicate
            }
            mp[s[r]] = r; // update last seen index
            max_length = max(max_length, r - l + 1);
            r++;
        }
        return max_length;
    }
};
