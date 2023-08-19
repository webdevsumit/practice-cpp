#include<iostream>
#include<string>

using namespace std;

bool isValidChar(char a){
    if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9')){
        return true;
    }
    return false;
}

char toLoweCasae(char a){
    if((a>='a' && a<='z') || (a>='0' && a<='9')) return a;
    return (a - 'A' + 'a');
}

bool checkPalindrome(string s)
{
    
    string tempStr = "";
    
    for(int i=0; i<s.size(); i++){
        if(isValidChar(s[i])) tempStr.push_back(s[i]);
    }

    cout<<tempStr<<endl;
    
    for(int i=0; i<s.size(); i++){
        tempStr[i] = toLoweCasae(tempStr[i]);
    }
    cout<<tempStr<<endl;

    int start = 0;
	int end = tempStr.size()-1;
    
    while(start<end){
        cout<<tempStr[start]<<endl;
        cout<<tempStr[end]<<endl;
        if(tempStr[start]!=tempStr[end]) return false;
        start++;
        end--;
    }
	
	return true;
}

int main(){

    string s = "c1 O$d@eeD o1c";

    cout<<checkPalindrome(s)<<endl;

    return 0;
}