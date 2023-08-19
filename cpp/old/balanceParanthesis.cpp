#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool isValid(string s) {

    string st = "";
    
    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        cout<<"i : "<<i<<endl;
        cout<<"ch : "<<ch<<endl;

        if((ch == '(') || (ch == '{') || (ch == '[')){
            st.push_back(ch);
            cout<<"ch pushed : "<<ch<<endl;
        }else{
            if(st.length()!=0){
                char c = st[st.length()-1];
                cout<<"c : "<<c<<endl;
                if((c == '[' && ch == ']') || (c == '{' && ch == '}') || (c == '(' && ch == ')')){
                    st.erase(st.length()-1,1);
                    cout<<"c erased : "<<c<<endl;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    cout<<"loop : "<<st<<endl;
    if(st.length()==0){
        return true;
    }else{
        return false;
    }
}

int main(){

    string s = "()";
    cout<<isValid(s)<<endl;

    return 0;
}