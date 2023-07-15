#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007



void solve(){
    int n, k;
    cin>>n>>k;
    vi v;
    int x;
    cin>>x;
    v.push_back(x);
    for(int i=0; i<n-1; i++){
        cin>>x;
        if(x!=v.back()){
            v.push_back(x);
        }
    }
    n = v.size();
    vector<vector<int>> g(n);
    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            int x = v[i]/j;
            if(g[i].empty()){
                g[i].push_back(x);
            }
            else{
                if(g[i].back()!=x){
                    g[i].push_back(x);
                }
            }
            if(x==0){
                break;
            }
        }
        sort(g[i].begin(), g[i].end());
    }
    int ans = INT_MAX;
    for(int mn = 0; mn<=v[n-1]; mn++){
        int mx = INT_MIN;
        bool flag = true;
        for(int i=0; i<n; i++){
            auto it = lower_bound(g[i].begin(), g[i].end(), mn);
            if(it==g[i].end()){
                flag = false;
                break;
            }
            mx = max(mx, *it);
        }
        if(flag){
            ans = min(ans, mx-mn);
        }
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
