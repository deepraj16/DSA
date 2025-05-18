class Solution {
public:
    vector<string> letterCombinations(string digits) {
         if (digits.empty()) return {};

        vector<string> phoneMap = {
            "",     "",     "abc",  "def", "ghi", "jkl",
            "mno",  "pqrs", "tuv",  "wxyz"
        };

        vector<string> result;
        string path;

        backtrack(digits, 0, phoneMap, path, result);
        return result;
    }

private:
    void backtrack(const string &digits, int index, const vector<string> &phoneMap,
                   string &path, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        string letters = phoneMap[digits[index] - '0'];
        for (char ch : letters) {
            path.push_back(ch);
            backtrack(digits, index + 1, phoneMap, path, result);
            path.pop_back();
        }
    }
};
