#include<bits/stdc++.h>
using namespace std;



int main(){
    int c, n, m;
    cin>>c>>n>>m;
    vector<int> v(n);
    for(auto &i:v){
        cin>>i;
    }
    for(int i=0; i<n; i++){
        if(v[i]>c){
            v.push_back(v[i]-c);
            n++;
            v[i]=c;
        }
    }
    vector<int> tobeadded(51);
    vector<int> farms(51);
    farms[0] = n;
    for(int i=0; i<n; i++){
        for(int j=1; j<51; j++){
            if(v[i]*(1<<j)>c){
                
            }
        }
    }

}