#include <bits/stdc++.h>
using namespace std;

/* DATA STRUCTURES */
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>

/* FUNCTIONS */
#define f(i, s, e) for(int i=s; i<e; i++)
#define rf(i, e, s) for(int i=e; i>=s; i--)
#define foreach(a) for(auto i: a)
#define sortVector(a) sort(a.begin(), a.end())
#define reverseSort(a) sort(a.begin(), a.end(), greater<int>())
#define pb push_back
#define eb emplace_back
#define endl '\n'

/* INPUT ARRAY */
#define input(a, n)            \
    for (int i = 0; i < n; ++i) \
    cin >> a[i]

/* PRINTS */
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
template<class T> void print(vector<T> &v) {for(auto x: v) cout << x << " "; cout << endl;}
template<class T> void print(T &val) { cout << val << endl;}

/* UTILITIES */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int mul(int a, int b){
    return (a%MOD*b%MOD)%MOD;
}

void solve(){
    int n, k, x;
    cin >> n >> k >> x;

    if(x!=1){
        cout << "YES" << endl;
        cout << n << endl;
        f(i,0,n) cout << 1 << " ";
        cout << endl;
    }else{
        vector<int> ans;
        bool flag = false;
        while(n>1){
             if(n<=k and n>0 and x!=n){
                ans.pb(n);
                flag = true;
                break;

            }
            n-=2;
            ans.pb(2);

           
        }
        if(!flag) no
        else{
            yes
            cout << ans.size() << endl;
            print(ans);
        }
    }
}

int32_t main(){
    fastIO();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    cerr<<"[Execution time "<<(float)clock()/CLOCKS_PER_SEC<<"s]"<<endl;
    return 0;
}