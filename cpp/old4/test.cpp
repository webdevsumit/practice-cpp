#include<iostream>
#include<string>
using namespace std;


int main(){

    string s;
    cout<< "Enter : ";
    cin>>s;
    int l = s.length();
    for(int i=0; i<(l/2); i++){
        swap(s[i], s[l-1-i]);
    }
    cout<< s << endl;
    return 0;
}