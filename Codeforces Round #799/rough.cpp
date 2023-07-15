#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------//
#if __has_include("../files/GR47_debug.cpp")
#include "../files/GR47_debug.cpp"
#endif
#ifdef GR47_LOCAL
#define deb(x) {cerr << #x << " "; _print(x); cerr << "\n";}
#else
#define deb(x)
#endif
#define rep(i, a, b) for (int i = a; i < b; i++)
#define precision(a) cout << setprecision(a) << fixed
#define MSB(x) (63 - __builtin_clzll(x))
#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)
#define MP make_pair
#define all(a) a.begin(), a.end()
template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }
typedef vector<int> vi; typedef vector<vector<int>> vvi; typedef vector<long long> vl; typedef vector<vector<long long>> vvl; typedef vector<bool> vb; typedef vector<vector<bool>> vvb; typedef map<int, int> mii; typedef map<long long, long long> mll; typedef pair<int, int> pii; typedef pair<long long, long long> pll; typedef unsigned long long ull; typedef long double ld; typedef long long ll;
//------------------------------------------------//

const long long MOD = 1000000007;
const int MAX_N = 500001;

void solve()
{
    int n;
    cin>>n;
    map<int,int> hsh;
    vi inv_hash;
    vi a(n);
    rep(i,0,n)
    {
        cin>>a[i];
        if(hsh.find(a[i]) == hsh.end())
        {
            hsh[a[i]] = inv_hash.size();
            inv_hash.push_back(a[i]);
        }
        a[i] = hsh[a[i]];
    }

    vvi idx(inv_hash.size());
    rep(i,0,n)
    {
        idx[a[i]].push_back(i+1);
    }

    int ans = 1;
    int l = 1,r = 1,val = inv_hash[0];
    int myIdx = 0;

    for(auto& v : idx)
    {
        vector<pii> range;

        for(int i=0;i<v.size();i++)
        {
            int j;
            for(j=i+1;j<v.size();j++)
            {
                if(v[j] != v[j-1] + 1) break;
            }

            range.push_back(MP(v[i],v[j-1]));
            i = j-1;
        }

        vvi dp(range.size(),vi(2));

        dp[0][0] = range[0].second-range[0].first+1;
        for(int i=1;i<range.size();i++)
        {
            int cnt =  range[i].second-range[i].first + 1;
            dp[i][0] = cnt;
            dp[i][1] = max(dp[i-1][0],dp[i-1][1]) + cnt - (range[i].first-range[i-1].second -1);
        }
        int mx = -1;
        pii tp;
        for(int i=0;i<range.size();i++)
        {
            if(mx < dp[i][0])
            {
                mx = dp[i][0];
                tp = MP(i,0);
            }
            if(mx < dp[i][1])
            {
                mx = dp[i][1];
                tp = MP(i,1);
            }
        }
        if(mx > ans)
        {
            int L,R;
            if(tp.second == 0)
            {
                L = range[tp.first].first;
                R = range[tp.first].second;
            }
            else
            {
                L = range[tp.first].first;
                R = range[tp.first].second;
                int cur = tp.first-1;
                while (1)
                {
                    if(dp[cur][0] >= dp[cur][1]) 
                    {
                        L = range[cur].first;
                        break;
                    }
                    else cur--;
                }
            }
            ans = mx;
            l = L;
            r =R;
            val = inv_hash[myIdx];
        }
        myIdx++;
    }
    cout<<val<<" "<<l<<" "<<r<<"\n";
}

int32_t main()
{
// #define DEBUG_MODE
#ifndef DEBUG_MODE
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef GR47_LOCAL
    freopen("../files/input.txt", "r", stdin); freopen("../files/output.txt", "w", stdout); freopen("../files/error.txt", "w", stderr);
#endif
#else
#ifdef GR47_LOCAL
    freopen("../files/input.txt", "r", stdin);
#endif
#endif


    int tc = 1;
    cin >> tc;
    for (int loop = 1; loop <= tc; loop++)
    {
        // cout << "Case #" << loop << ": ";
        solve();
        // bool as = solve(); cout << (as ? "YES\n" : "NO\n");
        // int as = solve(); cout << as << "\n";
    }
    return 0;
}

/*
    Tue Jun 14 20:04:32 2022
    File : H.cpp
*/
