#include<bits/stdc++.h>
using namespace std;
#define int long long int

set<int> precomp;

void solve(){
    int n;
    cin>>n;
    if(precomp.find(n)!=precomp.end()){
        cout<<"YES\n";
        return;
    }
    int l = 1e6, r = 1e9;
    while(l<=r){
        int mid = (l+r)/2;
        int val = 1+mid+mid*mid;
        if(1 + mid + mid*mid == n){
            cout<<"YES\n";
            return;
        }
        if(val>n) r = mid-1;
        else l = mid+1;
    }
    cout<<"NO\n";
    return;
}

const int INF = 1e18;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int k=2; k<=1e6 ; k++){
        int val = 1+k;
        int mul = k*k;
        while(1){
            val+=mul;
            if(val>INF) break;
            precomp.insert(val);
            if(mul>INF/k) break;
            mul*=k;
        }
    }
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
