//{ Driver Code Starts
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include <cstring>

using namespace std;

class Stack {
    public:
        int *arr;
        int top;
        int size;

        Stack(int size){
            this -> size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int ele){
            if(size - top){
                top++;
                arr[top] = ele;
            }else{
                cout<<"Stack overflow."<<endl;
            }
        }

        void pop(){
            if(top >= 0){
                top--;
            }else{
                cout<<"Stack is empty."<<endl;
            }
        }

        int peek(){
            if(top >= 0){
                return arr[top];
            }else{
                cout<<"Stack is empty."<<endl;
                return -1;
            }
        }

        bool empty(){
            return top == -1;
        }

        ~Stack(){
            delete arr;
        }
        
};

class Node {
    public:
    int data;
    Node * next;
    Node(int n){
        this -> data = n;
        next = NULL;
    }
};

class Stack2 {
    public:
        Node *head;
        Node *top;
        int size;
        int maxSize;

        Stack2(int size){
            head = NULL;
            top = NULL;
            this -> size = 0;
            maxSize = size;
        }

        void push(int ele){
            if(size<maxSize){
                Node * temp = new Node(ele);
                if(head == NULL) head = temp;
                else top -> next = temp;
                top = temp;
                size++;
            }
        }

        void pop(){
            
        }

        int peek(){
        }

        bool empty(){
        }

        ~Stack2(){
        }
        
};

int main(){

    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);

    st.pop();
    st.pop();
    st.pop(); 

    cout<< st.peek() <<endl;

    return 0;
}