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
unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
    unsigned result = 1;
    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);
        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }
    return result;
}

bool isPrime(unsigned n) {
    if (n < 2)
        return false;
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;
    for (unsigned a : {2, 7, 61}) {
        unsigned x = mod_pow(a % n, d, n);
        if (x <= 1 || x == n - 1)
            continue;
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);
        if (x != n - 1)
            return false;
    }
    return true;
}

int check1(int l, int r, int count){
    int l1 = l<<(count-2);
    if(l1*2<=r) return 1;
    return 0;
}

int check2(int l, int r, int count){
    int l1 = l<<(count-2);
    if(l1*3<=r){
        return 1;
    }
    return 0;
}


void solve(){
    int l, r;
    cin>>l>>r;
    int count = 1, l1=l*2;
    while(l1<=r){
        count++;
        l1 = l1*2;
    }
    cout<<count<<" ";
    if(count==1){
        cout<<(r-l+1)<<endl;
        return;
    }
    int ans = 0;
    int low = l, high = r, mid, ans1, ans2;
    int three = check2(l, r, count);
    if(three){
        //binary search for upper limit of l
        while(low<=high){
            mid = (low+high)/2;
            if(check2(mid, r, count)){
                ans1 = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        ans+= (ans1-l+1)*(count);
        ans%=998244353;
        low = ans1+1, high = r;
    }
    int two = check1(low, r, count);
    if(two){
        while(low<=high){
            mid = (low+high)/2;
            if(check1(mid, r, count)){
                ans2 = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        if(!three) ans += (ans2-l+1);
        else ans+= (ans2-ans1);
        ans%=998244353;
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
