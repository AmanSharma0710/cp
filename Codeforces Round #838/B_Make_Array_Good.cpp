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


int next_factor(int x, int lower){
    if(x==lower) return x;
    int upper = 2*lower;
    int l = 1, r = ((int)1e18)/x;
    int ans = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(x*mid>=lower && x*mid<=upper){
            ans = x*mid;
            r = mid-1;
        }
        else if(x*mid<lower){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}


void solve(){
    int n;
    cin>>n;
    vii a(n);
    for(int i=0; i<n; i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    cout<<n<<endl;
    int minn = a[0].first;
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        minn = next_factor(minn, a[i].first);
        int add = minn-a[i].first;
        ans[a[i].second] = add;
    }
    for(int i=0; i<n; i++){
        cout<<i+1<<" "<<ans[i]<<endl;
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
