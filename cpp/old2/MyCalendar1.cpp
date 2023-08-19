#include<iostream>
// #include<string>
#include<vector>
#include<algorithm>
// #include<map>
// #include<unordered_set>

using namespace std;


bool findInt(int n, vector<int>& arr){
    int s = 0;
    int e = arr.size()-1;
    int mid = s + (e-s)/2;
    while(s<e){
        
        cout<<"mid : "<<mid<<endl;
        cout<<"mid s : "<<s<<endl;
        cout<<"mid n : "<<n<<endl;
        cout<<"mid e : "<<e<<endl;

        if(arr[mid]==n) return true;
        
        if(arr[mid]<n){
            s=mid;
        }else{
            e=mid;
        }

        mid = s + (e-s)/2;
    }
    return false;
}

int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    vector<int> temp = {};
    sort(restricted.begin(), restricted.end());
    temp.push_back(0);
    int rSize = restricted.size();
    bool val1, val2;
    
    for(auto &x: edges){

        cout<<"x : "<<(&x)<<endl;

        if( !findInt(x[0], restricted) && !findInt(x[0], restricted) ){
            
            val1 = find(temp.begin(), temp.end(), x[0]) != temp.end();
            val2 = find(temp.begin(), temp.end(), x[0]) != temp.end();
            
            if( val1 && !val2 ){
                temp.push_back(x[1]);
            }
            if( !val1 && val2 ){
                temp.push_back(x[0]);
            }
            
        }
    }
    return temp.size();
}

int main(){
    vector<vector<int>> arr = {{0,1},{0,2},{0,5},{0,4},{3,2},{6,5}};
    vector<int> rs = {4,2,1};
    int ans = reachableNodes(7, arr, rs);
    cout<<"ANS : "<<ans<<endl;
    
    return 0;
}