class LFUCache {
private:
    int capacity;
    int minFreq;

    // key -> {value, freq}
    std::unordered_map<int, std::pair<int, int>> keyToValFreq;

    // freq -> keys with this freq, in LRU order
    std::unordered_map<int, std::list<int>> freqToKeys;

    // key -> iterator in freqToKeys[freq]
    std::unordered_map<int, std::list<int>::iterator> keyToIter;

    void updateFrequency(int key) {
        int freq = keyToValFreq[key].second;
        freqToKeys[freq].erase(keyToIter[key]);

        // If this was the last key in this frequency and it's the minFreq, update minFreq
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) {
                minFreq++;
            }
        }

        // Add key to next frequency list
        freq++;
        keyToValFreq[key].second = freq;
        freqToKeys[freq].push_back(key);
        keyToIter[key] = --freqToKeys[freq].end(); // point to new position
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end()) return -1;
        updateFrequency(key);
        return keyToValFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            // Key exists, just update value and frequency
            keyToValFreq[key].first = value;
            updateFrequency(key);
        } else {
            // Cache full -> need to evict
            if (keyToValFreq.size() >= capacity) {
                int keyToEvict = freqToKeys[minFreq].front();
                freqToKeys[minFreq].pop_front();
                if (freqToKeys[minFreq].empty()) {
                    freqToKeys.erase(minFreq);
                }
                keyToValFreq.erase(keyToEvict);
                keyToIter.erase(keyToEvict);
            }

            // Insert new key
            keyToValFreq[key] = {value, 1};
            freqToKeys[1].push_back(key);
            keyToIter[key] = --freqToKeys[1].end();
            minFreq = 1;
        }
    }
};
