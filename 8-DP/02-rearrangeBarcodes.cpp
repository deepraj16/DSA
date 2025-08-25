#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> freq;
        for (int b : barcodes) {
            freq[b]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for (auto &p : freq) {
            pq.push({p.second, p.first});
        }
        
        vector<int> result;
        
        while (pq.size() > 1) {
            auto [cnt1, num1] = pq.top(); pq.pop();
            auto [cnt2, num2] = pq.top(); pq.pop();
            
            result.push_back(num1);
            result.push_back(num2);
            
            if (--cnt1 > 0) pq.push({cnt1, num1});
            if (--cnt2 > 0) pq.push({cnt2, num2});
        }
        
        if (!pq.empty()) {
            result.push_back(pq.top().second);
        }
        
        return result;
    }
};
