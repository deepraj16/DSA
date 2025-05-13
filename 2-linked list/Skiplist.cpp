#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Skiplist {
private:
    static const int MAX_LEVEL = 16;       // Maximum number of levels
    float P = 0.5;                          // Probability for level increase

    struct Node {
        int val;
        std::vector<Node*> forward;

        Node(int val, int level) : val(val), forward(level, nullptr) {}
    };

    Node* head;
    int level;

    // Random level generator
    int randomLevel() {
        int lvl = 1;
        while ((float)rand() / RAND_MAX < P && lvl < MAX_LEVEL)
            lvl++;
        return lvl;
    }

public:
    Skiplist() {
        srand(time(0));  // Seed for randomness
        level = 1;
        head = new Node(-1, MAX_LEVEL);
    }

    bool search(int target) {
        Node* curr = head;
        for (int i = level - 1; i >= 0; --i) {
            while (curr->forward[i] && curr->forward[i]->val < target) {
                curr = curr->forward[i];
            }
        }
        curr = curr->forward[0];
        return curr && curr->val == target;
    }

    void add(int num) {
        std::vector<Node*> update(MAX_LEVEL, nullptr);
        Node* curr = head;

        for (int i = level - 1; i >= 0; --i) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }

        int newLevel = randomLevel();
        if (newLevel > level) {
            for (int i = level; i < newLevel; ++i) {
                update[i] = head;
            }
            level = newLevel;
        }

        Node* newNode = new Node(num, newLevel);
        for (int i = 0; i < newLevel; ++i) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    bool erase(int num) {
        std::vector<Node*> update(MAX_LEVEL, nullptr);
        Node* curr = head;

        for (int i = level - 1; i >= 0; --i) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }

        curr = curr->forward[0];
        if (!curr || curr->val != num) {
            return false;
        }

        for (int i = 0; i < level; ++i) {
            if (update[i]->forward[i] != curr) break;
            update[i]->forward[i] = curr->forward[i];
        }

        // Remove empty levels
        while (level > 1 && !head->forward[level - 1]) {
            level--;
        }

        delete curr;
        return true;
    }
};
