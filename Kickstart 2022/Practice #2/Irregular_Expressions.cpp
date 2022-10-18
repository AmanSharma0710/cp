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
    string s;
    cin>>s;
    int n=s.size();
    vector<int> prefix(n+1, 0);
    for(int i=0; i<n; i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            prefix[i+1]=prefix[i]+1;
        }
        else{
            prefix[i+1]=prefix[i];
        }
    }
    for(int l=0; l<n; l++){
        for(int r=l; r<n; r++){
            if(prefix[r+1]-prefix[l]!=2){
                continue;
            }
            int i=r+1;
            for(i=r+1; i<n; i++){
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    break;
                }
            }
            for(int l1 = i+1; l1<n; l1++){
                int r1 = l1 + r - l;
                if(r1>=n){
                    break;
                }
                if(prefix[r1+1]-prefix[l1]!=2){
                    continue;
                }
                for(i=0; i<(r1-l1+1); i++){
                    if(s[l1+i]!=s[l+i]){
                        break;
                    }
                }
                if(i==(r1-l1+1)){
                    cout<<"Spell!"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"Nothing."<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1, tc = 1;
    cin>>t;
    while (t--){
        cout<<"Case #"<<tc++<<": ";
        solve();       
    }
    return 0;
}
