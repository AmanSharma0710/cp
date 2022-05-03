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

void solve(){
    int n;
    cin>>n;
    bitset<10> bs(n), pal(0);
    int cnt=9;
    while(bs[cnt]==0 && cnt>=0){
        cnt--;
    }
    for(int i=0; i<=cnt/2; i++){
        if(bs[i]==bs[cnt-i]==1){
            pal[i]=1;
            pal[cnt-i]=1;
            bs[i]=0;
            bs[cnt-i]=0;
        }
    }
    vector<int> nos;
    if(pal.to_ulong()>0){
        nos.push_back(pal.to_ulong());
    }
    for(int i=0; i<10; i++){
        if(bs[i]){
            if(i==0){
                nos.push_back(1);
                continue;
            }
            if(i==1){
                nos.push_back(1);
                nos.push_back(1);
                continue;
            }
            int a = 1<<(i-1);
            nos.push_back(a+1);
            nos.push_back(a-1);  
        }
    }
    cout<<nos.size()<<endl;
    for(int i=0; i<nos.size(); i++){
        cout<<nos[i]<<" ";
    }
    cout<<endl;
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


