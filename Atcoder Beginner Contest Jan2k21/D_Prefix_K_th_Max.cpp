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
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    vector<bool> exist(n+1, false);
    for(int i=0; i<k; i++){
        exist[a[i]] = true;
    }
    int cnt = 0, kmax;
    for(int j=n; j>0; j--){
        if(exist[j]){
            cnt++;
        }
        if(cnt==k){
            kmax = j;
            break;
        }
    }
    cout<<kmax<<endl;
    for(int i=k; i<n; i++){
        exist[a[i]] = true;
        if(a[i]<kmax){
            cout<<kmax<<endl;
            continue;
        }
        kmax++;
        while(!exist[kmax]){
            kmax++;
        }
        cout<<kmax<<endl;
    }
    return 0;
}
