#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define MOD 1000000007

int n;
vector<vi> adj;
vi black, white;


//parentcolor = 0(parent is white)
//              1(parent is black)
int dfs(int x, int parent, int parent_color){
    //parent colour is white
    if(parent_color==0){
        //current node is white
        if(white[x]==-1){
            white[x]=1;
            for(auto &i:adj[x]){
                if(i!=parent){
                    white[x]*= dfs(i, x, 0);
                    white[x]%=MOD;
                }
            }
        }
        //current node is black
        if(black[x]==-1){
            black[x]=1;
            for(auto &i:adj[x]){
                if(i!=parent){
                    black[x]*=dfs(i, x, 1);
                    black[x]%=MOD;
                }
            }
        }
        return (white[x] + black[x])%MOD;
    }
    //parent colour is black
    //current node has to be white
    if(white[x]==-1){
        white[x]=1;
        for(auto &i:adj[x]){
            if(i!=parent){
                white[x]*= dfs(i, x, 0);
                white[x]%=MOD;
            }
        }
    }
    return white[x];
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    adj.assign(n, vector<int>(0));
    black.assign(n, -1);
    white.assign(n, -1);
    for(int i=0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<< dfs(0, -1, 0) <<endl;
    return 0;
}
