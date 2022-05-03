#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
//Maximise X-Y  =>  Maximise 2X-k
//Second person taking a number doesnt contribute to X at all
vi v;
vector<vi> dpmax, dpmin;

int solve(int l, int r, int toMax){
    if(toMax==1){
        if(dpmax[l][r]!=-1){
            return dpmax[l][r];
        }
        int ans = max(v[l] + solve(l+1, r, 0), v[r] + solve(l, r-1, 0));
        return dpmax[l][r] = ans;
    }
    if(toMax==0){
        if(dpmin[l][r]!=-1){
            return dpmin[l][r];
        }
        int ans = min(solve(l+1, r, 1), solve(l, r-1, 1));
        return dpmin[l][r] = ans;
    }
    assert(0);
    return INT_MAX;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    v.resize(n);
    dpmax.assign(n, vector<int>(n, -1));
    dpmin.assign(n, vector<int>(n, -1));
    for(auto &i:v){
        cin>>i;
    }
    for(int i=0; i<n; i++){
        dpmax[i][i] = v[i];
        dpmin[i][i] = 0;
    }
    int maxx = solve(0, n-1, 1);
    cout<< (2*maxx - accumulate(v.begin(), v.end(), 0ll)) <<endl;
    return 0;
}
