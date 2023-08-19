#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<set>

using namespace std;

int minimumOperations(vector<int>& nums) {
    set<int> st(nums.begin(), nums.end());
    int i=0;
    auto it = st.begin(); 
    while(it != st.end() && (*it)==0){
        ++it;
        ++i;
    }
    return st.size()-i;
}

int maximumGroups(vector<int>& grades) {
    sort(grades.begin(), grades.end());
    int l = grades.size();
    int s = 1;
    int e = l-1;
    int ans = 1;
    int mid = s+(e-s)/2;
    while(s<e){
        mid = s+(e-s)/2;
        cout<<"s : "<<s<<endl;
        cout<<"e : "<<e<<endl;
        cout<<"mid : "<<mid<<endl;
        if((mid*(mid+1)/2)>l){
            e=mid;
        }else{
            ans = mid;
            s=mid+1;
        }
    }
    return ans;
}

int main(){

    vector<int> arr = {47,2,16,17,41,4,38,23,47};

    cout<<maximumGroups(arr)<<endl;

    return 0;
}