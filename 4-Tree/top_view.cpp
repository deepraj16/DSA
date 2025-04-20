vector<int> topView(Node *root) {
    vector<int> ans;
    if (root == NULL) return ans;

    map<int, map<int, int>> m;
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        Node* node = temp.first;
        int hd = temp.second.first;
        int lev = temp.second.second;

        // store only first node seen at that horizontal distance and level
        if (m[hd].find(lev) == m[hd].end()) {
            m[hd][lev] = node->data;
        }

        if (node->left) {
            q.push({node->left, {hd - 1, lev + 1}});
        }
        if (node->right) {
            q.push({node->right, {hd + 1, lev + 1}});
        }
    }

    for (auto& i : m) {
        ans.push_back(i.second.begin()->second); // topmost node at each column
    }

    return ans;
}
