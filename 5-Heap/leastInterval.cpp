class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxCount = count(freq.begin(), freq.end(), maxFreq);

        int partCount = maxFreq - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int remainingTasks = tasks.size() - maxFreq * maxCount;
        int idles = max(0, emptySlots - remainingTasks);

        return tasks.size() + idles;
    }
};
