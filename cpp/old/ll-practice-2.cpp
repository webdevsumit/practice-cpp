#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node *next;

    Node(){

    };

    Node(int val1, Node* ptr){
        val = val1;
        next = ptr;
    }
};

void displayList(Node *head){
    Node *temp = head;

    while(temp!=NULL){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


Node *createList(Node *head){
    Node *start = new Node();

    start->val = 4;
    start->next = new Node();

    start->next->val = 5;
    start->next->next = new Node();

    start->next->next->val = 4;
    start->next->next->next = new Node();

    start->next->next->next->val = 2;
    start->next->next->next->next = new Node();

    start->next->next->next->next->val = 2;
    start->next->next->next->next->next = NULL;

    head = start;
    return head;
}


Node* addTwoNumbers(Node* l1, Node* l2) {
    Node *ans=NULL;
    Node *ansHead=NULL;
    Node *temp = NULL;
    int carry = 0;
    while(l1!=NULL && l2!=NULL){

        int num = l1->val+l2->val+carry;
        carry = 0;
        if(num>9){
            
            carry = num/10;
            num = num % 10;
        }
        
        temp = new Node(num, NULL);


        cout<<"temp : ";
        displayList(temp);
        cout<<"l1 : ";
        displayList(l1);
        cout<<"l1 : ";
        displayList(l2);
        cout<<"ans : ";
        displayList(ans);


        if(ans==NULL){
            cout<<"ans is null "<<endl;
            ans = temp;
            ansHead = ans;
        }else{
            ansHead->next = temp;
            ansHead = ansHead->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    if(l1!=NULL){
        ans->next = l1;
    }
    if(l2!=NULL){
        ans->next = l2;
    }
    return ans;
}

int main(){

    Node *l1 = NULL;
    l1 = createList(l1);
    l1 = addTwoNumbers(l1, l1);
    displayList(l1);

    return 0;
}