/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void InsertNode(Node* &head, Node* &tail,int data){
        Node * newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
            return ;
        }
        else{
            tail->next=newnode; 
            tail=newnode;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* clonehead=NULL; 
        Node* clonetail=NULL; 
        Node* temp=head;
        while(temp!=NULL){
            InsertNode(clonehead,clonetail,temp->val); 
            temp=temp->next;
        }

        unordered_map<Node* ,Node*>old_to_new ; 
        Node* orginalNode=head; 
        Node* cloneNode=clonehead; 
        while(orginalNode!=NULL){
            old_to_new[orginalNode]=cloneNode;
            orginalNode=orginalNode->next; 
            cloneNode=cloneNode->next; 
        }
        cloneNode=clonehead; 
        orginalNode=head; 
        while(orginalNode!=NULL){
            cloneNode->random=old_to_new[orginalNode->random]; 
            orginalNode=orginalNode->next; 
            cloneNode=cloneNode->next; 
        }
        
        return clonehead;
    }
};
