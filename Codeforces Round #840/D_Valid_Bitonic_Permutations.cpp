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
int power(int x, int y, int p){
    int res = 1; 
    x = x % p;  
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

vector<int> factorial(105, 1);

int nCr(int n, int r, int p){
    if (r==0)
        return 1;
    if(n<r)
        return 0;
    if(r<0 || n<0)
        return 0;
    return (factorial[n]*power(factorial[r], p-2, p)%p*power(factorial[n-r], p-2, p)%p)%p;
}


void solve(){
    int n, i, j, x, y;
    cin>>n>>i>>j>>x>>y;
    int ans = 0;
    if((x==n && i==1)||(y==n && j==n)){
        cout<<0<<endl;
        return;
    }
    if(x==n){
        int ways = 1;
        ways *= nCr(y-1, n-j, MOD);
        ways *= nCr(n-y-1, j-i-1, MOD);
        ways %= MOD;
        cout<<ways<<endl;
        return;
    }
    if(y==n){
        int ways = 1;
        ways *= nCr(x-1, i-1, MOD);
        ways *= nCr(n-x-1, j-i-1, MOD);
        ways %= MOD;
        cout<<ways<<endl;
        return;
    }
    for(int k=2; k<=n-1; k++){
        if(k==i || k==j)
            continue;
        int ways = 1;
        if(k<i){
            if(x<y) continue;
            ways *= nCr(y-1, n-j, MOD);
            ways *= nCr(x-y-1, j-i-1, MOD);
            ways %= MOD;
            ways*=nCr(n-x-1, i-k-1, MOD);
            ways %= MOD;
            ans += ways;
            ans%=MOD;
            continue;
        }
        if(k>j){
            if(x>y) continue;
            ways *= nCr(x-1, i-1, MOD);
            ways *= nCr(y-x-1, j-i-1, MOD);
            ways %= MOD;
            ways*=nCr(n-y-1, k-j-1, MOD);
            ways %= MOD;
            ans += ways;
            ans%=MOD;
            continue;
        }
        if(x<y){
            ways *= nCr(x-1, i-1, MOD);
            ways *= nCr(y-x-1, n-j-x+i, MOD);
            ways %= MOD;
            if((k-i-1)<(y-1-i-n+j)) ways = 0;
            int left = n-y-1;
            ways *= nCr(left, j-k-1, MOD);
            ways %= MOD;
            ans += ways;
            ans%=MOD;
            continue;
        }
        if(x>y){
            ways *= nCr(y-1, n-j, MOD);
            ways *= nCr(x-y-1, n-j-y+i, MOD);
            ways %= MOD;
            if((j-k-1)<(x-1+j-n-i)) ways = 0;
            int left = n-x-1;
            ways *= nCr(left, k-i-1, MOD);
            ways %= MOD;
            ans += ways;
            ans%=MOD;
            continue;
        }
    }
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=1; i<105; i++){
        factorial[i] = (factorial[i-1]*i)%MOD;
    }
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
