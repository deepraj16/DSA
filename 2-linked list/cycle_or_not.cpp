/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL){
            return NULL;
        }

        if(head->next==NULL){
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head; 
        int flag=0;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next; 
            fast=fast->next; 
            if(fast->next!=NULL){
                fast=fast->next;
            }

            if(slow==fast){
                flag=1; 
                break;
            }
        }

         if (fast == NULL || fast->next == NULL) {
            return NULL;
        }
        
        if(flag==1){
            slow=head; 
            while(slow!=fast){
                slow=slow->next; 
                fast=fast->next;
            }
            return slow;
        }

        return NULL;

    }
};
