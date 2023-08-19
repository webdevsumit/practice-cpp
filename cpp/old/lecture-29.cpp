#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>

using namespace std;


int main(){
    
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int **arr = new int*[n];

    for(int i=0; i<n; i++){
        arr[i] = new int[n];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"Enter ("<<i<<","<<j<<") : ";
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        delete []arr[i];
    }

    delete []arr;

    return 0;
}