#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int maxx=INT_MIN, posmaxx=0;
    for(int i=0; i<n; i++){
        if(v[i]>maxx){
            maxx=v[i];
            posmaxx=i;
        }
    }
    int minx = INT_MAX, posminx=0;
    for(int i=0; i<n; i++){
        if(v[i]<=minx){
            minx=v[i];
            posminx=i;
        }
    }
    int ans = posmaxx + n - 1 - posminx;
    if(ans>n-2){
        ans--;
    }
    cout<<ans<<endl;
    return 0;
}