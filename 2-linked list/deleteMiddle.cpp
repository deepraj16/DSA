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
    ListNode* find_Middle(ListNode* head){
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }

        ListNode* slow=head; 
        ListNode* fast=head; 
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next; 
            fast=fast->next;
            if(fast->next!=NULL){
                 fast=fast->next;
            }
           
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return NULL;
        }
        ListNode* middle=find_Middle(head); 
        ListNode* temp=head; 
        while(temp!=NULL){
            if(temp->next==middle){
                temp->next=middle->next;
            }
            temp=temp->next;
        }
        return head;
    }
};
