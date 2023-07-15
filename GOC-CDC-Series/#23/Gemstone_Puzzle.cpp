#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n, c;
    cin>>n>>c;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<int> sv = v;
    sort(sv.begin(), sv.end());
    int l=1, r=n;
    int ans = -1;
    auto check = [&](int x){
        int elem = sv[x-1];
        int e = 0, ne = 0;
        for(int i=0; i<c; i++){
            if(v[i]>=elem) e++;
            else ne++;
        }
        if(e>ne) return true;
        for(int i=c; i<n; i++){
            if(v[i]>=elem) e++;
            else ne++;
            if(v[i-c]>=elem) e--;
            else ne--;
            if(e>ne) return true;
        }
        return false;
    };
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout<< n - ans + 1 <<endl;
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
