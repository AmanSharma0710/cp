#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

signed main(){
    int H, W;
    cin >> H >> W;
    char grid[H][W];
    int ans[H][W];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>grid[i][j];
            ans[i][j]=0;
        }
    }
    ans[0][0]=1;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(grid[i][j]=='#'){
                ans[i][j]=0;
            }
            else{
                if(i>0){
                    ans[i][j] += ans[i-1][j];
                }
                if(j>0){
                    ans[i][j] += ans[i][j-1];
                }
            }
            ans[i][j]%=MOD;
        }
    }
    cout<<ans[H-1][W-1]<<endl;
}