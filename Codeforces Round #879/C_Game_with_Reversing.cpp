#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    string a, b;
    cin>>a>>b;
    int ans = INT_MAX;
    //case when bob makes even number of moves
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            cnt++;
        }
    }
    ans = min(ans, 2*cnt);
    if(cnt%2){
        ans--;
    }
    //case when bob makes odd number of moves
    cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i]!=b[n-1-i]){
            cnt++;
        }
    }
    int ans1 = 2*cnt;
    if(cnt%2==0 && cnt!=0){
        ans1--;
    }
    else if(cnt==0){
        ans1 = 2;
    }
    ans = min(ans, ans1);
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
