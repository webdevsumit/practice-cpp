#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int merge(vector<int> &nums, int st, int en){
    int mid = (st+en)/2;
    int ptr1 = st;
    int ptr2 = mid+1;
    int k =0;
    int ans=0;
    //checking which elements obey this given condition
    while(ptr1<=mid && ptr2<=en){
        if(nums[ptr1] > 2*(long long)nums[ptr2]){
            ans+=(en-ptr2+1);
            ptr1++;
        }
        else ptr2++;
    }
    ptr1 = st;
    ptr2 = mid+1;
    vector<int> temp(en-st+1);
    //and here we're finally merging simple as merge sort
    while(ptr1<=mid && ptr2<=en){
        if(nums[ptr1]>nums[ptr2]) temp[k++] = nums[ptr1++];
        else temp[k++] = nums[ptr2++];
    }
    while(ptr1<=mid) temp[k++] = nums[ptr1++];
    while(ptr2<=en) temp[k++] = nums[ptr2++];
    for(int &it : temp) nums[st++]=it;
    return ans;
}

int mergeSort(vector<int> &nums, int st, int en){
    if(st>=en) return 0;
    int mid = (st+en)/2;
    int ans = mergeSort(nums, st, mid);
    ans += mergeSort(nums, mid+1, en);
    //combining all the possibilities and summing them up
    return ans += merge(nums, st, en);
}

int reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size()-1);
}

int main(){

    vector<int> h;
    h.push_back(1);
    h.push_back(3);
    h.push_back(2);
    h.push_back(3);
    h.push_back(1);
    // h.push_back(1);
    // h.push_back(3);
    // h.push_back(1);
    // h.push_back(2);
    // h.push_back(1);
    // h.push_back(2);
    // h.push_back(1);

    cout<<reversePairs(h)<<endl;

    return 0;
}