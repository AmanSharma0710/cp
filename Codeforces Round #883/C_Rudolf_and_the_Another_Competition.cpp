#include<bits/stdc++.h>
using namespace std;
#define int long long int



void solve(){
    int n, m, h;
    cin>>n>>m>>h;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>a[i][j];
    }
    vector<pair<int, int>> b(n);
    for(int i=0; i<n; i++){
        sort(a[i].begin(), a[i].end());
        for(int j=1; j<m; j++) a[i][j]+=a[i][j-1];
        int sum=0;
        for(int j=0; j<m; j++){
            sum += a[i][j];
            if(a[i][j]<=h){
                b[i].first = j+1;
                b[i].second = sum;
            }
        }
    }
    pair<int, int> p = b[0];
    auto cmp = [&](pair<int, int> x, pair<int, int> y){
        if(x.first==y.first) return x.second<y.second;
        return x.first>y.first;
    };
    sort(b.begin(), b.end(), cmp);
    for(int i=0; i<n; i++){
        if(b[i].first==p.first && b[i].second==p.second){
            cout<<i+1<<endl;
            return;
        }
    }
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
