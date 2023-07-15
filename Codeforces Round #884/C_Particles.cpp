#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int> o, e;
    for(int i=0; i<n; i++){
        if(i%2==0) e.push_back(a[i]);
        else o.push_back(a[i]);
    }
    sort(e.begin(), e.end(), greater<int>());
    sort(o.begin(), o.end(), greater<int>());
    int ans1 = LLONG_MIN, ans2 = LLONG_MIN;
    for(int i=0; i<e.size(); i++){
        if(i==0) ans1 = e[i];
        else{
            if(e[i]>0) ans1 += e[i];
            else break;
        }
    }
    for(int i=0; i<o.size(); i++){
        if(i==0) ans2 = o[i];
        else{
            if(o[i]>0) ans2 += o[i];
            else break;
        }
    }
    cout<<max(ans1, ans2)<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
