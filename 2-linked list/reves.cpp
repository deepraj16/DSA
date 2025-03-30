#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}



void insertat_tail(node *&head, int dat)
{
    if (head == NULL)
    {
        head = new node(dat);
        return;
    }
    node *k = head;
    while (k->next != NULL)
    {
        k = k->next;
    }
    node *temp = new node(dat);
    k->next = temp;
    temp->next = NULL;
}




void revershelper(node * &head,node* curr, node* pre){
    if(curr==NULL){
        head=pre;
        return ;
    }
    node * forword=curr->next ;
    revershelper(head,forword,curr); 
    curr->next=pre; 
}
node* revserhelper2(node* head){
    if(!head==NULL || head->next==NULL){
        return head;
    }
    node* chotohead= revserhelper2(head->next); 
    head->next->next=head;
    head->next=NULL;
    return chotohead;
}

void reves(node *&llist)
{ 
    node*curr=llist; 
    node * pre=NULL;
    revershelper(llist,curr,pre); 
    print(llist);
   node* temp2= revserhelper2(llist); 
   cout<<endl;
    print(temp2);
}
//--name sameple to working to geting the wording the 
//the form given code to geting the  code the code
// '

void return_middle_node(node* head ){
     if(head==NULL and head->next==NULL){
        return ;
     }
     

}


int main()
{

    node *head = new node(3);
    int dat;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the data: ";
        dat = i + 12;
        insertat_tail(head, dat);
        print(head);
        cout << endl;
    }
    reves(head);
    
    return 0;
}
