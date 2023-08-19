#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){

    unordered_map<string, int> m;

    m["what2"] = 1;
    m["what"] = 1;
    m["what3"] = 1;

    unordered_map<string, int> :: iterator it = m.begin();

    // while(it != m.end()){
    //     cout << it->first << " " << it->second << endl;
    //     it++;
    // }

    return 0; 
}