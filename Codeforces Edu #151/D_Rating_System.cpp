#include<bits/stdc++.h>
using namespace std;
#define int long long int



void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1, 0);
    for(int i=0; i<n; i++){
        cin>>a[i+1];
    }
    vector<int> pre(n+1, 0);
    for(int i=1; i<=n; i++){
        pre[i] = pre[i-1] + a[i];
    }
    auto val = [&](int x){
        int ans = 0;
        bool flag = false;  //flag is true if the sum is at least x
        for(int i=0; i<=n; i++){
            ans += a[i];
            if(ans>=x){
                flag = true;
            }
            if(flag && ans<x){
                ans = x;
            }
        }
        return ans;
    };
    set<int> s;
    for(int i=0; i<n; i++){
        if(a[i]>=0 && a[i+1]<0){
            if(s.empty() || (pre[i] > pre[*s.rbegin()])){
                s.insert(i);
            }
        }
    }
    int k = 0, val1 = val(0);
    for(auto it: s){
        int temp = val(pre[it]);
        if(temp>val1){
            val1 = temp;
            k = pre[it];
        }
    }
    cout<<k<<endl;
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
