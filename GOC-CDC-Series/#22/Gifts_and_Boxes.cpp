#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    int n, m;
    cin>>n>>m;
    set<pair<int, int>>a;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        a.insert({x, y});
    }
    vector<pair<int, int>>b(m);
    for (auto &i:b) cin>>i.first>>i.second;
    sort(b.begin(), b.end());
    bool ok = true;
    for(auto i:b){
        auto it = a.lower_bound({i.first, 0});
        if (it == a.end()){
            ok = false;
            break;
        }
        auto it2 = a.lower_bound({it->first, i.second});
        if (it2 == a.end()){
            ok = false;
            break;
        }
        assert((it2->first >= i.first) && (it2->second >= i.second));
        a.erase(it2);
    }
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
