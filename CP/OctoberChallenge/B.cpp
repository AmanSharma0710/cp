#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){ //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}


void solve(){
    int n, k;
    cin>>n>>k;
    vi v(k);
    for(int i=0; i<k; i++){
        cin>>v[i];
        v[i] = n - v[i];
    }
    int m=0;
    sort(v.begin(),v.end());
    int time = n, i=0;
    while(time && i<k){
        if(v[i]<time){
            time-=v[i];
            m++;
        }
        i++;
    }
    cout<<m<<endl;

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