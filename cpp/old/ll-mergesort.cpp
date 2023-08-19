#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

Node* createLinkList(){
    Node * head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 3;
    head->next->next = new Node();
    head->next->next->data = 4;
    head->next->next->next = new Node();
    head->next->next->next->data = 5;
    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 6;
    head->next->next->next->next->next = new Node();
    head->next->next->next->next->next->data = 8;
    head->next->next->next->next->next->next = new Node();
    head->next->next->next->next->next->next->data = 9;
    return head;
}

void displayList(Node *head){
    Node *temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}



// Node *findMid(Node *head){
//     Node *slowPtr = head;
//     Node *fast = head;

//     if()

//     while (fast->next->next!=NULL)
//     {
//         fast = fast->next->next;
//     }
    
// }



// Node *mergeSort(Node *head){
//     Node *mid = findMid(head);


//     return head;
// }


Node* removeNthFromEnd(Node* head, int n) {
    if(head==NULL) return head;

    Node *ptr1 = head;
    Node *ptr2 = head;
    Node *prev = NULL;

    int count=1;
    while(count!=n){
        if(ptr2==NULL) return head;
        count++;
        ptr2 = ptr2->next;
    }

    if(ptr2->next==NULL) return head->next;

    while(ptr2->next!=NULL){
        ptr2 = ptr2->next;
        prev = ptr1;
        ptr1 = ptr1->next;
    }

    if(prev==NULL && n==1) return prev;
    if(prev==NULL) return head;

    if(ptr1!=NULL){
        prev->next = ptr1->next;
    }else{
        prev->next = NULL;
    }
    
    delete ptr1;
    return head;
}

Node *mergeSorted(Node *ptr1, Node *ptr2){
    Node *result = NULL;
    Node *prev = NULL;

    if(ptr1==NULL) return ptr2;
    if(ptr2==NULL) return ptr1;
    
    while(ptr1!=NULL && ptr2!=NULL){
        cout<<"ptr 1 : ";
        displayList(ptr1);
        cout<<"ptr 2 : ";
        displayList(ptr2);
        if(ptr1->data<ptr2->data){
            if(result==NULL){
                result = ptr1;
                prev  = ptr1;
            }else{
                prev->next = ptr1;
                prev = prev->next;
            }
            ptr1 = ptr1->next;
        }else{
            if(result==NULL){
                result = ptr2;
                prev  = ptr2;
            }else{
                prev->next = ptr2;
                prev = prev->next;
            }
            ptr2 = ptr2->next;
        }
    }
    if(ptr1==NULL) prev->next = ptr2;
    else prev->next = ptr1;
    return result;
}

Node* mergeKLists(vector<Node*>& lists) {
    Node *head = NULL;
    Node *temp = NULL;
    
    for(int i=0; i<lists.size(); i++){
        temp = lists[i];
        head = mergeSorted(head, temp);
        cout<<"head in a function: ";
        displayList(head);
    }
    return head;
}



int main(){

    Node *head = createLinkList();
    Node *head2 = createLinkList();
    Node *head3 = createLinkList();
    // head = mergeSort(head);
    vector<Node*> lst;
    lst.push_back(head);
    lst.push_back(head2);
    lst.push_back(head3);
    displayList(head);

    // head = removeNthFromEnd(head, 2);
    Node *result = mergeKLists(lst);
    cout<<"End Result : ";
    displayList(result);

    return 0;
}