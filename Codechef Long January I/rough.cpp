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

void printVector(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]+1<<" ";
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> seq(n);
        iota(seq.begin(), seq.end(), 0);
        for(int j=0; j<k; j++){
            vector<int> temp(n);
            for(int i=0; i<n/2; i++){
                temp[i] = seq[2*i];
            }
            for(int i=n/2; i<n; i++){
                temp[i] = seq[2*(i-n/2)+1];
            }
            seq = temp;
        }
        printVector(seq);
    }
    return 0;
}
