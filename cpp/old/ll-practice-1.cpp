#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};


// Node *create_list(Node *start);
// void display(struct node *start);
// void count(struct node *start);
// void search(struct node *start, int data);
// struct node *addAtBeg(struct node *start, int data);
// Node *addAtEnd(Node *start, int data);
// struct node *addAtAfter(struct node *start, int data, int item);
// struct node *addAtBefore(struct node *start, int data, int item);
// struct node *addAtPos(struct node *start, int data, int pos);
// struct node *del(struct node *start, int data);
// struct node *reverse(struct node *start);


Node *create_list(Node *start){
    Node *newNode = new Node();
    newNode->data = 1;
    start = newNode;
    return start;
}

void display(Node *start){
    Node *tempStart = start;
    while(tempStart!=NULL){
        cout<<tempStart->data<<" -> ";
        tempStart = tempStart->next;
    }
    cout<<"NULL"<<endl;
}

void count(Node *start){
    Node *tempStart = start;
    int countValue = 0;
    while(tempStart!=NULL){
        countValue++;
        tempStart = tempStart->next;
    }
    cout<<"Count : "<<countValue<<endl;
}

Node *addAtEnd(Node *start, int data){

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if(start==NULL){
        start = newNode;
        return start;
    }
    
    Node *tempStart = start;

    while(tempStart->next!=NULL){
        tempStart = tempStart->next;
    } 

    tempStart->next = newNode;
    return start;
}


Node *reverse(Node *start){

    if(start==NULL) return start;

    if(start->next==NULL) return start;

    Node *prev = start;

    if(start->next->next==NULL){
        start = start->next;
        start->next = prev;
        prev->next = NULL; 
        return start;
    }

    Node *current = start->next;
    Node *next = start->next->next;

    if(next->next==NULL){
        current->next = prev;
        next->next = current;
        prev->next = NULL;
        start = next;
        return start;
    }

    while(next->next!=NULL){
        current->next = prev;
        prev = current;
        current = next;
        next = next->next;
    }
    start->next = NULL;
    current->next = prev;
    next->next = current;
    start = next;
    return start;

}


int main()
{
    Node *start = NULL;
    int choice, data, item, pos;
    while(1){
        cout<<" 1. Create List"<<endl;
        cout<<" 2. Display List"<<endl;
        cout<<" 3. Count"<<endl;
        cout<<" 4. Search"<<endl;
        cout<<" 5. Add to Empty List / Add at beginning"<<endl;
        cout<<" 6. Add at end"<<endl;
        cout<<" 7. Add after node"<<endl;
        cout<<" 8. Add before node"<<endl;
        cout<<" 9. Add at position"<<endl;
        cout<<"10. Delete"<<endl;
        cout<<"11. Reverse"<<endl;
        cout<<"12. Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            count(start);
            break;
        // case 4:
        //     cout<<"Enter the element to be searched : ";
        //     cin>>data;
        //     search(start, data);
        //     break;
        // case 5:
        //     cout<<"Enter the element to be inserted : ";
        //     cin>>data;
        //     start = addAtBeg(start, data);
        //     break;
        case 6:
            cout<<"Enter the element to be inserted : ";
            cin>>data;
            addAtEnd(start, data);
            break;
        // case 7:
        //     cout<<"Enter the element to be inserted : ";
        //     cin>>data;
        //     cout<<"Enter the element after which to insert : ";
        //     cin>>item;
        //     start = addAtAfter(start, data, item);
        //     break;
        // case 8:
        //      cout<<"Enter the element to be inserted : ";
        //     cin>>data;
        //     cout<<"Enter the element before which to insert : ";
        //     cin>>item;
        //     start = addAtBefore(start, data, item);
        //     break;
        // case 9:
        //     cout<<"Enter the element to be inserted : ";
        //     cin>>data;
        //     cout<<"Enter the position at which to insert : ";
        //     cin>>pos;
        //     start = addAtPos(start, data, pos);
        //     break;
        // case 10:
        //     cout<<"Enter the element to be deleted : ";
        //     cin>>data;
        //     start = del(start, data);
        //     break;
        case 11:
            start = reverse(start);
            break;
        case 12:
            exit(1);
            break;
        
        default:
            cout<<"Wrong choice!"<<endl;
            break;
        }
    }

    return 0;
}