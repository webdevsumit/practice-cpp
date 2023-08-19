#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
// #include<map>
// #include<unordered_set>

using namespace std;



// Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

// Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
// Each vowel 'a' may only be followed by an 'e'.
// Each vowel 'e' may only be followed by an 'a' or an 'i'.
// Each vowel 'i' may not be followed by another 'i'.
// Each vowel 'o' may only be followed by an 'i' or a 'u'.
// Each vowel 'u' may only be followed by an 'a'.

// Since the answer may be too large, return it modulo 10^9 + 7.



string chars = "aeiou";

bool isValidChar(char a, char b){

    cout<<"STR : "<<b<<" -> "<<a<<endl;

    char c1 = 'a';
    char c2 = 'e';
    char c3 = 'i';
    char c4 = 'o';
    char c5 = 'u';
    if((b==c3 && (a==c3))) return false;
    if(b==c3) return true;
    
    if( (b==c1 && (a==c2)) || (b==c2 && (a==c1 || a==c3)) || (b==c4 && (a==c3 || a==c5)) || (b==c5 && (a==c1)) 
    )return true;
    
    return false;
}

void countC(string output, int n, int &ans){

    if(output.length()>n) return;
    
    if(output.length()==n){
        ans++;
        return;
    }
    
    string temp = output;
    for(auto &x:chars){
        temp = output;
        if(temp=="" || isValidChar( temp[temp.size()-1], x)){
            cout<<"STR : True"<<endl;
            temp += x;
            countC(temp, n, ans);
        }else{
            cout<<"STR : False"<<endl;
        }
    }
    
}
                                            
int countVowelPermutation(int n) {
    int ans = 0;
    countC("", n, ans);
    return ans; 
}


int lengthOfLIS(vector<int>& nums) {
        
    if(nums.size()==1) return 1;
    
    int currentLength = 1;
    int maxLength = 1;
    
    for(int i=1; i<nums.size(); i++){

        // cout<<"currentLength : "<<currentLength<<endl;
        // cout<<"maxLength : "<<maxLength<<endl;
        cout<<"i : "<<i<<endl;

        if(nums[i-1]<nums[i]){
            currentLength++;
            cout<<"First True"<<endl;
        }else {
            cout<<"First False"<<endl;
            if(maxLength<currentLength){
                maxLength = currentLength;
                cout<<"Second True"<<endl;
            }
            currentLength = 1;
        }
    }
    
    return maxLength;
}

int main(){

    vector<int> nums = {10,9,2,5,3,7,101,18};

    int ans = lengthOfLIS(nums);
    cout<<"ANS : "<<ans<<endl;
    
    return 0;
}