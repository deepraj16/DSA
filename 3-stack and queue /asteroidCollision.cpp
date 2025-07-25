class Solution {
public:
   vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int a : asteroids) {
        bool destroyed = false;

        while (!st.empty() && a < 0 && st.top() > 0) {
            if (st.top() < -a) {
                st.pop(); // smaller right-moving asteroid explodes
                continue;
            } else if (st.top() == -a) {
                st.pop(); // both explode
            }
            destroyed = true; // current left-moving asteroid is destroyed
            break;
        }

        if (!destroyed) {
            st.push(a);
        }
    }

    // Convert stack to vector (in reverse)
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        result[i] = st.top();
        st.pop();
    }

    return result;
}
};
