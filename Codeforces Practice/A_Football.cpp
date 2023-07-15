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


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    int n = s.length();
    int count = 1, maxx = 1;
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            count++;
            maxx = max(maxx, count);
        }
        else{
            count = 1;
        }
    }
    cout<<(maxx>=7?"YES":"NO")<<endl;
    return 0;
}
