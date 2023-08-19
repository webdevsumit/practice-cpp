#include<iostream>
#include<string>

using namespace std;

char getMaxOccuringChar(string str){
    int arr[26] = {0};
    for(int i=0; i<str.length();i++){
        char a = str[i];
        if(a>='a' && a<='z'){
            arr[a-'a']++;
        }else{
            arr[a-'A']++;
        }
    }
    int index = 0;
    for(int i=1; i<26;i++){
        if(arr[i]>arr[index]) index = i;
    }
    return 'a'+index;
}

string replaceSpaces(string &str){
	for(int i=0; i<str.length(); i++){
        if(str[i]==' '){
            str = str.substr(0,i)+"@40"+str.substr(i+1,str.length());
        }
    }
    return str;
}

bool checkInclusion(string s1, string s2) {
    string temp = s1;
    int startIndex = 0;
    for(int i=0; i<s2.length(); i++){
        if(temp.find(s2[i])<temp.length()){
            temp.erase(temp.find(s2[i]),1);
        }else if(s2[startIndex]==s2[i] && temp.length()!=s1.length()){
            startIndex++;
        }else if(temp.length()!=0){
            while(temp.find(s2[i])>=temp.length() && temp.length()!=s1.length()){
                // cout<<" pushing : "<<s2[startIndex]<<" - "<<temp.find(s2[i])<<" - "<<temp.length()<<endl;
                temp.push_back(s2[startIndex]);
                startIndex++;
            }
            if(temp.find(s2[i])<temp.length()){
                temp.erase(temp.find(s2[i]),1);
            }else if(temp.length()==s1.length()){
                temp = s1;
                startIndex = i+1;
            }
        }
        if(temp.length()==0){
            return true;
        }
        // cout<<"CHECK : "<<s2[i]<<" - "<<temp.length()<<" - "<<temp<<endl;
    }
    if(temp.length()!=0) return false;
    return true;
}


int main(){
    // string s1 = "kuzntqeuvaszrspkgjvxrupwxwrexztptsowceibeewxbslvosbobmyymikdscshybtmanuxeqtanrjekbwirmhgvfmzipfiqxcilarfyasoayepgfzmdytlpjymeaztsyubkbmblepwozffxiitdhwaquozlfmnascomqczrbhxcnzugppddtudxrigfeaozzojpeamnobapgwksudbiwdedvprwonmzardsodhxmkgghqzfhorjaijdvwzsnfpdfklwibbsnwqsoajcpjisbgizgttlnmclawbgnhbmtcpuusuammvgxnopdngclxumgfgwjrinamevhirpmlkwtyxkrmoffrreotdosjghsrkgxyiyrytbbofgczndgmdalyvvoljczcztxitxelywqemjigtuanubpstndwzvtiejtoqvetaehvcuujyupncumjnkesmoadzyvkwvjqgqewvvvpheyyvkewefbjjqzajxnhouodanyruqpzdcjmgnxkmhsgqjhpcyviewmrkfioudzqivmmguxjxuxdmpsmkwnvbxcomifgxqmcovlkooptjpfxjllwtlkkoaayzduodgsusaogswmoqkznynwiukkrrxzkwcknwlazxnlmghybxmyvquzbdqlpfydhnnuvlmyjmixyzso";
    string s1 = "ky";
    string s2 = "ainwkckifykxlribaypk";
    // string s1 = "vxq";
    // string s2 = "asvvvvvdfvxq";
    cout<<checkInclusion(s1,s2)<<endl;
    return 0;
}