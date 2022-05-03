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

int findmex(vector<int> &v){
    vector<bool> present(v.size()+1, false);
    for(auto i : v){
        if(!present[i]){
            present[i] = true;
        }
    }
    for(int i=0; i<present.size(); i++){
        if(!present[i]){
            return i;
        }
    }
    return -1;
}

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(auto &i:v) 
        cin>>i;
    vi ans;
    for(int j=0; j<2*n; j++){
        int mex = findmex(v);
        int index=0;
        for(index=0; index<n; index++){
            if(v[index]!=index)
                break;
        }
        if(index==n){
            break;
        }
        if(mex <n){
            ans.push_back(mex);
            v[mex] = mex;
            continue;
        }
        for(int i=index; i<n; i++){
            if(v[i]==index){
                v[i] = mex;
                ans.push_back(i);
                break;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto &i:ans)
        cout<<i+1<<" ";
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
