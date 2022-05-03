#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007


void solve(){
    int n, k;
    cin>>n>>k;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    vi postsum(n+1, 0);
    postsum[n-1] = v[n-1];
    rrep(i,n-2,0){
        postsum[i] = postsum[i+1] + v[i];
    }
    int minn = v[0];
    int sum = accumulate(v.begin(), v.end(), 0ll);
    if(sum<=k){
        cout<<0<<endl;
        return;
    }
    int steps = INT_MAX;
    for(int i=n; i>0; i--){
        int x = (k + postsum[i]+minn - sum)/(n-i+1);
        if(k+postsum[i]+minn-sum<0 && ((k+postsum[i]+minn-sum)%(n-i+1))!=0){
            x--;
        }
        steps = min(steps, minn-x + n-i);
    }
    cout<<steps<<endl;
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
