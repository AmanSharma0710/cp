#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n;
    cin>>n;
    vector<int>a(n), b(n);
    for (auto &i:a) cin>>i;
    for (auto &i:b) cin>>i;
    int ans = 0;
    int l=0, r=0, sum=0;
    set<int> st;
    while(r<n){
        while(r<n && st.find(a[r]) != st.end()){
            st.erase(a[l]);
            sum -= b[l];
            l++;
        }
        st.insert(a[r]);
        sum += b[r];
        r++;
        ans = max(ans, sum);
    }
    cout<<ans<<endl;
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
