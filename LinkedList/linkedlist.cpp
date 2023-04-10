#include<iostream>
using namespace std;

class Node
{
    public:
     int data;
     Node* next;

     Node(int data)
     {
        this->data=data;
        this->next=NULL;
     }
};

void insertathead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
void insertattail(Node* tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
void insertatany(Node* head,int data,int position){
      Node* temp=head;
      int cnt=1;
      while(cnt!=position-1){
        temp=temp->next;
        cnt++;
      }

      Node* nodetoinsert=new Node(data);
      nodetoinsert->next=temp->next;
      temp->next=nodetoinsert;

}
void deletenode(Node* &head,int position){
      if(position==1){
        Node* temp=head;
         head=head->next;
         temp->next=NULL;
         delete temp;
      }
      else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
      }
}

void print(Node* &head){
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
         temp=temp->next;
    }
    
}


int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    insertathead(head,30);
    insertathead(head,40);
    insertattail(tail,5);
    insertatany(head,35,2);
    deletenode(head,1);
    print(head);
   

}