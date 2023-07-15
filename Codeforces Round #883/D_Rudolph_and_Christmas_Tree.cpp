#include<bits/stdc++.h>
using namespace std;
#define int long long int



void solve(){
    int n, d, h;
    cin>>n>>d>>h;
    double area = (double)h*d/2;
    double ans = n*area;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    reverse(a.begin(), a.end());
    for(int i=1; i<n; i++){
        int diff = h-(a[i-1]-a[i]);
        double ratio = (double)diff/h;
        if(diff>0){
            double a1 = area*ratio*ratio;
            ans -= a1;
        }
    }
    cout<<setprecision(20)<<ans<<"\n";
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
