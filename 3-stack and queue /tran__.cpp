class Solution {
public:
    vector<int> prevSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st; 
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                pse[i] = st.top(); 

        return pse;
    }

    vector<int> nextSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) 
                st.pop();
            if (!st.empty())
                nse[i] = st.top(); 
            st.push(i);
        }
        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmallerIndex(heights); 
        vector<int> prev = prevSmallerIndex(heights);
        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];
            int width = next[i] - prev[i] - 1;
            int area = height * width;
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
