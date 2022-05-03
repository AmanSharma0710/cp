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
    vector<bool> vis(n+1, false);
    vector<int> a(n);
    int queries = 0;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        vector<int> v;
        cout<<"? "<<i<<endl;
        queries++;
        cout.flush();
        int first;
        cin>>first;
        int x;
        do{
            cout<<"? "<<i<<endl;
            queries++;
            cout.flush();
            cin>>x;
            v.push_back(x);
        }while(x!=first);
        for(int j=0; j<v.size(); j++){
            vis[v[j]] = true;
        }
        int s = v.size();
        for(int j=0; j<v.size(); j++){
            int from = (j+queries)%s;
            int to = (j+1+queries)%s;
            a[v[from]-1] = v[to];
        }
    }
    cout<<"! ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout.flush();
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
