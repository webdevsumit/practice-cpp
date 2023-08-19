#include<iostream>
#include<vector>
using namespace std;


int main(){
    
    vector v = {2,7,11,15};
    int target = 9;
    
    for(auto &a:v){
        cout<<a<< " ";
    }

    return 0;
}