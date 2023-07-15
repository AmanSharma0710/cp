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


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int idx;
    cin>>idx;
    idx--;
    string s;
    cin>>s;
    vector<int> v(n, 0);
    int ans = 0;
    for(int i=0; i<n/2; i++){
        int diff = abs(s[i]-s[n-i-1]);
        diff = min(diff, 26-diff);
        v[i] = diff;
        ans += diff;
    }
    int l = -1, r = -1;
    for(int i=0; i<n; i++){
        if(v[i] != 0){
            r = i;
            if(l == -1){
                l = i;
            }
        }
    }
    if(l == -1){
        cout<<ans<<endl;
        return 0;
    }
    if(idx>((n-1)/2)){
        idx = n-idx-1;
    }
    if(idx<=l || idx>=r){
        ans += max(abs(idx-l), abs(idx-r));
    }
    else{
        ans += min(abs(idx-l), abs(idx-r)) + abs(r-l);
    }
    cout<<ans<<endl;
    return 0;
}
