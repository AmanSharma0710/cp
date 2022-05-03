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
    

    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k;
    cin>>k;
    if(k==0){
        cout<<"0"<<endl;
        return 0;
    }
    bitset<65> bs = k;
    bool first = false;
    for(int i=64; i>=0; i--){
        if(bs[i]){
            first = true;
            cout<<2;
        }
        else{
            if(first){
                cout<<0;
            }
        }
    }
    return 0;
}
