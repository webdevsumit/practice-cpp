#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include <cstring>

using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node(int n){
        value = n;
        next = NULL;
    }
};

class queue{
    Node *front;
    Node *rear;
    int size;
public:
    queue(){
        front = rear = NULL;
        size = 0;
    }
    void push(int n){
        if(rear == NULL){
            front = new Node(n);
            rear = front;
        }else{
            rear->next = new Node(n);
            rear = rear->next;
        }
        size++;
    }
    int pop(){
        if(front == NULL) return - 1;
        Node *temp = front;
        int ans = temp->value;
        if(front == rear){
            front = rear = NULL;
            size = 0;
        }else{
            front = front->next;
            size --;
        }

        temp->next = NULL;
        delete temp;
        return ans;
    }
    int gfront(){
        if(front == NULL) return -1;
        return front->value;
    }
    int gsize(){
        return size;
    }
    bool empty(){
        bool ans = front == NULL;
        return ans;
    }
};

int main(){

    queue q;
    q.push(12);
    q.push(44);
    // q.push(42);
    cout<< "Front : " << q.gfront() <<endl;
    q.pop();
    cout<< "Front : " << q.gfront() <<endl;
    q.pop();
    // q.empty();
    cout<< "Size : " << q.gsize() <<endl;
    return 0;
}