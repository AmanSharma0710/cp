#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    ans.push_back(a[(n-1)/2]);
    int idx = (n-1)/2 + 1, idx1 = 0;
    for(int i=1; i<n; i++){
        if(idx<n) ans.push_back(a[idx++]);
        if(idx1<(n-1)/2) ans.push_back(a[idx1++]);
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
