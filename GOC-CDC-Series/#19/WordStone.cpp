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

int compute(vector<int> a){
    return accumulate(a.begin(), a.end(), 0LL);
}

int compute(vector<int> a, vector<int> b){
    int ans = 0;
    for(int i=0; i<26; i++){
        int temp = min(a[i], b[i]);
        ans += temp;
        a[i] -= temp;
        b[i] -= temp;
    }
    int ans1 = INT_MAX;
    ans1 = min(ans1, compute(a) + compute(b));
    return ans + ans1;
}

int compute(vector<int> a, vector<int> b, vector<int> c){
    int ans = 0;
    for(int i=0; i<26; i++){
        int temp = min(a[i], b[i]);
        temp = min(temp, c[i]);
        ans += temp;
        a[i] -= temp;
        b[i] -= temp;
        c[i] -= temp;
    }
    int ans1 = INT_MAX;
    ans1 = min(ans1, compute(a) + compute(b, c));
    ans1 = min(ans1, compute(b) + compute(a, c));
    ans1 = min(ans1, compute(c) + compute(a, b));
    return ans + ans1;
}

int compute(vector<int> a, vector<int> b, vector<int> c, vector<int> d){
    int ans=0;
    //Calculate maximum prefix
    for(int i=0; i<26; i++){
        int temp = min(a[i], b[i]);
        temp = min(temp, min(c[i], d[i]));
        ans += temp;
        a[i] -=temp;
        b[i] -=temp;
        c[i] -=temp;
        d[i] -=temp;
    }
    //pair of 1:3
    int ans1 = INT_MAX;
    ans1 = min(ans1, compute(a, b, c) + compute(d));
    ans1 = min(ans1, compute(a, c, d) + compute(b));
    ans1 = min(ans1, compute(a, d, b) + compute(c));
    ans1 = min(ans1, compute(b, c, d) + compute(a));
    //pair of 2:2
    ans1 = min(ans1, compute(a, b) + compute(c, d));
    ans1 = min(ans1, compute(a, c) + compute(b, d));
    ans1 = min(ans1, compute(a, d) + compute(b, c));
    return ans + ans1;
}


void solve(){
    string a, b, c, d;
    cin>>a>>b>>c>>d;
    vector<int> cnt1(26, 0), cnt2(26, 0), cnt3(26, 0), cnt4(26, 0);
    for(auto x: a) cnt1[x-'a']++;
    for(auto x: b) cnt2[x-'a']++;
    for(auto x: c) cnt3[x-'a']++;
    for(auto x: d) cnt4[x-'a']++;
    cout<<1+compute(cnt1, cnt2, cnt3, cnt4)<<endl;
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
