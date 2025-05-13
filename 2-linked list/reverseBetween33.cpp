/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if (!head || left == right) return head; // Edge case: No need to reverse

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        int count = 1;

        // Step 1: Move `prev` to the node before `left`
        while (count < left) { 
            prev = prev->next;
            count++;
        }

        // Step 2: Reverse the sublist from left to right
        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* first = curr;
        ListNode* last = prev;

        while (count >= left && count <= right) {
            next = curr->next;
            curr->next = last;
            last = curr;
            curr = next;
            count++;
        }

        // Step 3: Connect reversed part back
        prev->next = last;
        first->next = curr;

        return dummy->next;
        
    }
};
