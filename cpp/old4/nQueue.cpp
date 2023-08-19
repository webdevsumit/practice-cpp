#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include <cstring>

using namespace std;

class KQueue{
    public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;

    KQueue(int n, int k){
        this -> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];

        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        
        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        arr = new int[n];
        freeSpot = 0;
    }

    void push(int data, int qn){
        // overflow 
        if(freeSpot == -1){
            cout<< "Overflow"<<endl;
            return;
        }

        // find first free index;
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // check whether frist emement or not
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            // link new element to the prev element 
            next[rear[qn-1]] = index;
        }

        next[index] = -1;

        rear[qn-1] = index;
        arr[index] = data;

    }

    


    int pop(int qn){
        // underflow
        if(front[qn-1] == -1){
        cout<< "Underflow"<<endl;
        return -1;
        }

        // find index to pop
        int index = front[qn-1];

        // front ko aage badao
        front[qn-1] = next[index];

        // freeSpot ko mnage karo
        next[index] = freeSpot;

        freeSpot = index;
        return arr[index];
    }
};

int main(){

    // KQueue q;
    // q.push(12);
    // q.push(44);
    // // q.push(42);
    // cout<< "Front : " << q.gfront() <<endl;
    // q.pop();
    // cout<< "Front : " << q.gfront() <<endl;
    // q.pop();
    // // q.empty();
    // cout<< "Size : " << q.gsize() <<endl;
    
    return 0;
}