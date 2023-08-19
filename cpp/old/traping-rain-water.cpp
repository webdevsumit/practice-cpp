#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;


int trap(vector<int>& height) {
    int tWater = 0;
    int maxi = height[0];
    int maxiIndex = 0;
    for(int i=0; i<height.size(); i++){
        if(height[i]>maxi){
            maxiIndex = i;
            maxi = height[i];
        }
    }
    tWater = maxi * height.size();
    cout<<"water : "<<tWater<<endl;
    int s = 0;
    int e = height.size()-1;
    int leftMaxi = 0;
    int rightMaxi = height.size()-1;
    while(s<maxiIndex && e>maxiIndex){
        if(height[leftMaxi]<height[s]){
            leftMaxi = s;
        }
        tWater -= ((height[maxiIndex] - height[leftMaxi]) + height[s]);
        cout<<"water : "<<((height[maxiIndex] - height[leftMaxi]) + height[s])<<endl;
        cout<<"height[maxiIndex] : "<<height[maxiIndex]<<" , height[leftMaxi] : "<<height[leftMaxi]<<" height[s] : "<< height[s]<<endl;
        s++;

        if(height[rightMaxi]<height[e]){
            rightMaxi = e;
        }
        tWater -= ((height[maxiIndex] - height[rightMaxi]) + height[e]);
        cout<<"water : "<<((height[maxiIndex] - height[rightMaxi]) + height[e])<<endl;
        cout<<"height[maxiIndex] : "<<height[maxiIndex]<<" , height[rightMaxi] : "<<height[rightMaxi]<<" height[e] : "<< height[e]<<endl;
        e--;
    }
    cout<<"loop-2"<<endl;
    while(s<maxiIndex){
        if(height[leftMaxi]<height[s]){
            leftMaxi = s;
        }
        tWater -= ((height[maxiIndex] - height[leftMaxi]) + height[s]);
        cout<<"water : "<<((height[maxiIndex] - height[leftMaxi]) + height[s])<<endl;
        cout<<"height[maxiIndex] : "<<height[maxiIndex]<<" , height[leftMaxi] : "<<height[leftMaxi]<<" height[s] : "<< height[s]<<endl;
        s++;
    }
    cout<<"loop-3"<<endl;
    while(e>maxiIndex){
        if(height[rightMaxi]<height[e]){
            rightMaxi = e;
        }
        tWater -= ((height[maxiIndex] - height[rightMaxi]) + height[e]);
        cout<<"water : "<<((height[maxiIndex] - height[rightMaxi]) + height[e])<<endl;
        cout<<"height[maxiIndex] : "<<height[maxiIndex]<<" , height[rightMaxi] : "<<height[rightMaxi]<<" height[e] : "<< height[e]<<endl;
        e--;
    }
    cout<<"water : "<<tWater<<endl;
    tWater -= height[maxiIndex];
    return tWater;
}

int main(){

    vector<int> h;
    h.push_back(4);
    h.push_back(2);
    h.push_back(3);
    // h.push_back(2);
    // h.push_back(1);
    // h.push_back(0);
    // h.push_back(1);
    // h.push_back(3);
    // h.push_back(2);
    // h.push_back(1);
    // h.push_back(2);
    // h.push_back(1);

    cout<<trap(h)<<endl;

    return 0;
}