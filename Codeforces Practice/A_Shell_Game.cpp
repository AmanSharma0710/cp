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
    fstream input("input.txt", ios::in);
    fstream output("output.txt", ios::out);
    int index;
    input>>index;
    for(int i=0; i<3; i++){
        int a, b;
        input>>a>>b;
        if(a==index){
            index=b;
        }
        else if(b==index){
            index=a;
        }
    }
    output<<index<<endl;
    input.close();
    output.close();
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    //cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
