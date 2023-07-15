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
vi a;
bool check(int x){
    int n = x;
    for(int i=0; i<a.size(); i++){
        if(x<a[i]){
            return false;
        }
        n-= (x - a[i]);
    }
    return n<=0;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    a.resize(n);
    rep(i,0,n) cin>>a[i];
    int l = 0, r = INT_MAX;
    int ans = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout<<ans;
    return 0;
}
