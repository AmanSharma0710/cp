#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i=0; i<k; i++){
        pair<int, int> p1, p2;
        cin>>p1.first>>p1.second>>p2.first>>p2.second;
        p1.first--; p1.second--; p2.first--; p2.second--;
        a[p1.first][p1.second] += 1;
        a[p2.first][p2.second] += 1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j];
        }
        cout<<endl;
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
