#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>

using namespace std;

void merge(vector<int> &arr, int s, int mid, int e){
    int ptr1 = s;
    int ptr2 = mid+1;
    vector<int> ans;
    while(ptr1<=mid || ptr2<=e){
        if((arr[ptr1]>arr[ptr2] && ptr2<=e) || ptr1>mid){
            ans.push_back(arr[ptr2]);
            ptr2++;
        }else if((arr[ptr1]<arr[ptr2] && ptr1<=mid) || ptr2>e){
            ans.push_back(arr[ptr1]);
            ptr1++;
        }
    }
    for(auto &x: ans){
        arr[s] = x;
        s++;
    }
}

void mergeSort(vector<int> &arr, int s, int e){
    if(s>=e) return;
    int mid = s + (e-s)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, mid, e);
}

int partition(vector<int> &arr, int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for(auto &x: arr){
        if(x<pivot) cnt++;
    }
    swap(arr[s+cnt], arr[s]);
    int i = s;
    int j = e;
    while(i<s+cnt && j>s+cnt){
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        swap(arr[i++],arr[j--]);
    }
    return s+cnt;
}


void quickSort(vector<int> &arr, int s, int e){
    if(s>=e) return;
    int p = partition(arr, s, e);
    mergeSort(arr, s, p-1);
    mergeSort(arr, p+1, e);
}



/* // Getting wrong solutions need optimize the logic but the question is alredy done with Brute Force...*/
// int kthSmallest(vector<vector<int>>& matrix, int k) {
//     int s = matrix.size();
//     if(k==1) return matrix[0][0];
//     int numOfElementTC = s*(s+1)/2;
//     int digonal = s;
//     int nthDigonal = s;
//     // if((numOfElementTC-digonal)<k && numOfElementTC<k){
//     // }
//     while((numOfElementTC-digonal)<k && numOfElementTC<k){
//         numOfElementTC += --digonal;
//         nthDigonal++;
//     }
//     while((numOfElementTC-digonal)>=k && numOfElementTC>k){
//         numOfElementTC -= digonal--;
//         nthDigonal--;
//     } 
//     numOfElementTC -= digonal;
//     nthDigonal--;
//     int i=0,j=0;
//     cout<<" numOfElementTC : "<<numOfElementTC<<endl;
//     if(nthDigonal<s){
//         j = 0;
//         i = nthDigonal;
//     }else{
//         j = nthDigonal-(s-1);
//         i = s-1;
//     }
//     vector<int> lst;
//     while(i>=0 && j<s){
//         lst.push_back(matrix[i][j]);
//         i--;
//         j++;
//     }
//     sort(lst.begin(), lst.end());
//     for(auto &x: lst){
//         cout<<x<<" ";
//     }
//     cout<<endl; 
//     return lst[k-numOfElementTC-1]; 
// }

int main(){

    // // MergeSort......
    // vector<int> arr = {43,15,46,77,38,29};
    // mergeSort(arr, 0, arr.size()-1);
    // for(auto &x: arr){
    //     cout<<x<<" ";
    // }


    // Quick Sort.......
    vector<int> arr = {43,15,46,77,38,29};
    quickSort(arr, 0, arr.size()-1);
    for(auto &x: arr){
        cout<<x<<" ";
    }


    // // kthSmallest....
    // vector<vector<int>> matrix = {{1,3,5},{6,7,12},{11,14,14}};
    // cout<<" ans : "<<kthSmallest(matrix, 3)<<endl;

    return 0;
}