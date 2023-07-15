#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    int ansEven=0, ansOdd=0;
    int cntOdd[2] = {0}, cntEven[2] = {0};
    for(int i=0; i<s.size(); i++){
        ansOdd++;
        int x = s[i]-'a';
        if(i%2==0){
            ansOdd += cntEven[x];
            ansEven += cntOdd[x];
            cntEven[x]++;
        }
        else{
            ansOdd += cntOdd[x];
            ansEven += cntEven[x];
            cntOdd[x]++;
        }
    }
    cout<<ansEven<<" "<<ansOdd<<endl;
    return 0;
}
