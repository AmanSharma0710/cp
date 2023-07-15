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

string s;
int n, m;
vector<string> v;
vector<int>dp;

int solve(int bitmask){
    int ans = INT_MAX;
    //if all characters are present
    if(bitmask == (1<<n)-1) return 0;
    //if already calculated
    if(dp[bitmask] != -1) return dp[bitmask];
    for(int i=0; i<m; i++){
        //try to put characters from v[i] in s
        queue<char> q;
        for(int j=0; j<v[i].length(); j++){
            q.push(v[i][j]);
        }
        int temp = bitmask;
        for(int j=0; j<n; j++){
            //if jth bit is not set
            if(!(bitmask & (1<<j))){
                int qsize = q.size();
                for(int k = 0; k<qsize; k++){
                    if(q.front() == s[j]){
                        q.pop();
                        temp |= (1<<j);
                        break;
                    }
                    else{
                        q.push(q.front());
                        q.pop();
                    }
                }
            }
        }
        //if character was added, recurse for remaining characters
        if(temp != bitmask){
            ans = min(ans, 1 + solve(temp));
        }
    }
    return dp[bitmask] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>s;
    n = s.length();
    sort(s.begin(), s.end());
    cin>>m;
    v.resize(m);
    rep(i,0,m){
        cin>>v[i];
    }
    dp.resize(1<<n, -1);
    int ans = solve(0);
    if(ans == INT_MAX) cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
    return 0;
}
