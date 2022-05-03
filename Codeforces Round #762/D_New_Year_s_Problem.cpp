#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007



void solve(){
    int m, n;
    cin>>m>>n;
    int a[m][n];
    rep(i,0,m){
        rep(j,0,n){
            cin>>a[i][j];
        }
    }
    if(m<=n-1){
        vector<int> v(n, INT_MIN);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                v[i] = max(v[i], a[j][i]);
            }
        }
        cout<< *min_element(v.begin(), v.end())<<endl;
        return;
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
