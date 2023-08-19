#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
using namespace std;


void TOH(int ndisk, char source, char temp, char dest){
    if(ndisk==1){
        cout<<"Move disk "<<ndisk<<" from "<<source<<" --> "<<dest<<endl;
        return; 
    }
    TOH(ndisk-1, source, dest, temp);
    cout<<"Move disk "<<ndisk<<" from "<<source<<" --> "<<dest<<endl;
    TOH(ndisk-1, temp, source, dest);
}

int main(){
    char source = 'A', temp = 'B', dest = 'C';
    int ndisk;
    cout<<"Enter the number of disk : ";
    cin>>ndisk;
    cout<<"Sequence is : "<<endl;
    TOH(ndisk, source, temp, dest);
}