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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size(); 
        ListNode* dummy = new ListNode(0);

        vector<int>data;
        for(auto list:lists){
            while(list!=NULL){
                data.push_back(list->val);
                list=list->next;
            }
        }
         sort(data.begin(), data.end());
     
        ListNode* curr = dummy;

        for (int val : data) {
            curr->next = new ListNode(val);
            curr = curr->next;  // Move curr forward
        }

        return dummy->next;  //
    }
};
