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
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int> b;
    int sum = 0;
    for(int i=0; i<k; i++){
        sum+=a[i];
    }
    b.push_back(sum);
    for(int i=k; i<n; i++){
        sum = sum - a[i-k] + a[i];
        b.push_back(sum);
    }
    vector<int> c(n-k+1);
    c[n-k] = b[n-k];
    for(int i=n-k-1; i>=0; i--){
        c[i] = max(c[i+1], b[i]);
    }
    int ans = 0, idx = 0;
    for(int i=0; i<n-2*k+1; i++){
        if(ans < b[i] + c[i+k]){
            ans = b[i] + c[i+k];
            idx = i;
        }
    }
    int idx2 = idx+k;
    for(int i = idx2; i<n-k+1; i++){
        if(ans == b[idx] + b[i]){
            idx2 = i;
            break;
        }
    }
    cout<<idx+1<<" "<<idx2+1<<endl;
    return 0;
}
