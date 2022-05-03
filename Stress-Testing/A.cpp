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

vector<vector<int>> table;


void solve(){
    int n, k;
    cin>>n>>k;
    int maxbit = log2(k);
    table.assign(maxbit+1, vector<int>(n, 0));
    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 0);
    for(int i=0; i<n/2; i++){
        table[0][i] = seq[2*i];
    }
    for(int i=n/2; i<n; i++){
        table[0][i] = seq[2*(i-n/2)+1];
    }
    for(int i=1; i<=maxbit; i++){
        for(int j=0; j<n; j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
    for(int i=0; i<=maxbit; i++){
        if(k&(1<<i)){
            vector<int> temp(n);
            for(int j=0; j<n; j++){
                temp[j] = table[i][seq[j]];
            }
            seq = temp;
        }
    }
    for(int i=0; i<n; i++){
        cout<<seq[i] +1 <<" ";
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
