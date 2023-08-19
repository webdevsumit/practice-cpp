#include<iostream>
#include<vector>

using namespace std;

class ListNode{
    public:
        int val;
        ListNode *next;
};

ListNode* createLinkList(){
    ListNode * head = new ListNode();
    head->val = 1;
    head->next = new ListNode();
    head->next->val = 2;
    head->next->next = new ListNode();
    head->next->next->val = 3;
    head->next->next->next = new ListNode();
    head->next->next->next->val = 4;
    head->next->next->next->next = new ListNode();
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = new ListNode();
    head->next->next->next->next->next->val = 6;
    head->next->next->next->next->next->next = new ListNode();
    head->next->next->next->next->next->next->val = 7;
    head->next->next->next->next->next->next->next = new ListNode();
    head->next->next->next->next->next->next->next->val = 8;
    head->next->next->next->next->next->next->next->next = new ListNode();
    head->next->next->next->next->next->next->next->next->val = 9;
    return head;
}

void displayList(ListNode *head){
    ListNode *temp = head;

    while(temp!=NULL){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

// code starts from here.....

ListNode* startAfterK(ListNode* head, int k) {
    ListNode *startPtr = head;
    int count = 0;
    while(startPtr!=NULL && count<k){
        startPtr = startPtr->next;
        count++;
    }
    return startPtr;
}

bool gapIsValid(ListNode* start, ListNode* end, int k) {
    ListNode *tempPtr = start;
    int count = 0;
    for(int i=0; i<k; i++){
        if(tempPtr==NULL){
            return false;
        }
        tempPtr = tempPtr->next;
    }
    return true;
}

ListNode* reverseK(ListNode* start, int k) {
    if(start==NULL){
        return start;
    }
    if(k==2){
        ListNode *ptr1 = start->next;
        start->next = NULL;
        ptr1->next = start;
        return ptr1;
    }
    if(k==1){
        start->next = NULL;
        return start;
    }
    ListNode *ptr1 = start;
    ListNode *ptr2 = start->next;
    ListNode *ptr3 = start->next->next;
    for(int i=0; i<k-1; i++){
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
    }
    ptr2->next = ptr1;
    return ptr2;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k==0 || k==1) return head;
    ListNode *result = NULL;
    ListNode *resultEnd = NULL;
    ListNode *start = head;
    ListNode *end = head;
    while(end!=NULL){
        end = startAfterK(end, k);
        // cout<<"end : "; 
        // displayList(end);
        if(gapIsValid(start, end, k)){
            // cout<<"result : "; 
            // displayList(result);
            if(result==NULL){
                result = reverseK(start, k);
                resultEnd = startAfterK(result, k-1);
            }else{
                resultEnd->next = reverseK(start, k);
                resultEnd = startAfterK(resultEnd, k);
                cout<<"result : "; 
                displayList(resultEnd);
            }
            start = end;
        }else{
            resultEnd->next = start;
        }
    }
    return result;
    
} 

ListNode* reverseKGroup2(ListNode* head, int k) {
    if(k==0 || k==1 || head==NULL || head->next==NULL) return head;
    ListNode *lastEnd = NULL;
    ListNode *lastEndPtr = head;
    ListNode *nextStartPtr = head;
    ListNode *nextStart = head;
    bool nextStartBatch = true;
    int count = 0;
    while(count<k && nextStartPtr!=NULL){
        nextStartPtr = nextStartPtr->next;
        count++;
    }
    nextStart = nextStartPtr;
    if(count<k) return head;
    
    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = head;

    while (nextStartBatch){
        while(current!=nextStart){
            next = next->next;
            current->next = prev;
            prev = current;
            current=next;
            if(nextStartPtr!=NULL) nextStartPtr = nextStartPtr->next;
            else nextStartBatch = false;
        }

        if(lastEnd==NULL){
            lastEnd=prev;
            head = prev;
        }else{
            lastEnd->next = prev;
        }

        lastEnd = lastEndPtr;
        lastEndPtr = current;
        prev = NULL;
        nextStart = nextStartPtr;
        
    }
    cout<<"lastEnd : ";
    displayList(lastEnd);
    cout<<"current : ";
    displayList(current);
    lastEnd->next = current;
    return head;
}
// code end here..... 


int main(){
    ListNode *head = createLinkList();
    displayList(head);
    ListNode *result = reverseKGroup2(head, 2);
    cout<<"End Result : ";
    displayList(result);
    return 0;
}