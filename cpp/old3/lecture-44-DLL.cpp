#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include <cstring>

using namespace std;


class Node{
    public:
    int data;
    Node * next;
    Node * prev;

    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<" memory is free for node with data "<< value <<endl;
    }

};

void InsertAtHead(Node* &head, int d){

    // creating new node
    Node * temp = new Node(d);
    temp -> next = head;
    head -> prev = temp; 
    head = temp;
}

void print(Node * temp){
    // Node* temp = head;
    while(temp!=NULL){
        cout<< temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void deleteNode(int pos, Node * &head){

    // deleteing first or start node
    if(pos==1){
        Node * temp = head;
        head = head -> next;
        head -> prev = NULL;
        // deleting memory of start Node
        temp -> next = NULL;
        temp -> prev = NULL;
        delete temp;
        return;
    }
    Node * prev = head;
    pos--;
    pos--;
    while(pos--){
        prev = prev -> next; 
    }
    Node * cur = prev -> next;

    prev -> next = cur -> next;
    cur -> next -> prev = prev;
    cur -> next = NULL;
    cur -> prev = NULL;
    delete cur;
 
}

int main(){

    Node * head = new Node(60);
    InsertAtHead(head, 50);
    InsertAtHead(head, 40);
    InsertAtHead(head, 30);
    InsertAtHead(head, 20);
    InsertAtHead(head, 10);
    print(head);
    deleteNode(2, head);
    print(head);

    return 0;    
}