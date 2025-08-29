class Solution {
public:
    vector<string> split(string& s) {
        vector<string> words;
        string word = "";
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word.push_back(c);
            }
        }
        if (!word.empty()) words.push_back(word);
        return words;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        vector<string> words1 = split(s1);
        vector<string> words2 = split(s2);

        for (string& w : words1) freq[w]++;
        for (string& w : words2) freq[w]++;

        vector<string> result;
        for (auto& [w, count] : freq) {
            if (count == 1) result.push_back(w);
        }
        return result;
    }
};
