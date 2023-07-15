#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    double ans = 0;
    for(int i=0; i<n; i++){
        double p = (double)n/(n-i);
        ans += v[i]*p;
    }
    cout<<ans<<endl;
    return 0;
}