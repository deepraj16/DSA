class Solution {
private:
    vector<int> nextSmallerToRight(vector<int>& heights, int size) {
        stack<int> s;
        vector<int> ans(size);
        s.push(-1);

        for (int i = size - 1; i >= 0; i--) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            ans[i] = (s.top() == -1) ? size : s.top(); // if no smaller to right, use size
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerToLeft(vector<int>& heights, int size) {
        stack<int> s;
        vector<int> ans(size);
        s.push(-1);

        for (int i = 0; i < size; i++) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            ans[i] = s.top(); 
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = nextSmallerToLeft(heights, n);
        vector<int> right = nextSmallerToRight(heights, n);

        int area = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            area = max(area, currArea);
        }
        return area;
    }
};
