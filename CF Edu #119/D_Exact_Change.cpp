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



void solve(){
    int n;
    cin>>n;
    set<int> s;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    vector<int> v(s.begin(), s.end());
    for(int i=v.size()-1; i>0; i--){
        v[i] -= v[i-1];
    }
    int ones=0, twos=0, threes=0;
    for(int i=0; i<v.size(); i++){
        threes += v[i]/3;
        v[i] %= 3;
        twos += v[i]/2;
        v[i] %= 2;
        ones += v[i];
    }
    if(twos>1){
        threes += twos/3;
        twos %= 3;
        if(twos==0){
            twos = 1;
            threes--;
            ones++;
        }
    }
    if(ones>1){
        threes += ones/3;
        ones %= 3;
        if(ones==0){
            ones = 1;
            threes--;
            twos++;
        }
    }
    if(twos>1){
        threes += twos/3;
        twos %= 3;
        if(twos==0){
            twos = 1;
            threes--;
            ones++;
        }
    }
    cout<<(threes+twos+ones)<<endl;
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
