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
    ListNode* middleNode(ListNode* head) {
           ListNode* temp=head; 
           ListNode* fast=head;
           if(head==NULL){
            return NULL;
           }
           if(head->next==NULL){
            return head;
           }
           while(fast->next!=NULL){
            temp=temp->next; 
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            } 

           }
           return temp;
        
        
    }
    
};
