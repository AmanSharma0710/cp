#include<bits/stdc++.h>
using namespace std;
#define int long long int

int ans;

void calc(int x){
    int sum=0;
    while(x){
        sum+= x%10;
        x/=10;
    }
    if(sum/10 == 0){
        return;
    }
    ans++;
    calc(sum);
    return;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    if(s.length()==1){
        cout<<"0"<<endl;
        return 0;
    }
    int sum=0;
    for(int i=0; i<s.length(); i++){
        sum += s[i]-'0';
    }
    if(sum/10 == 0){
        cout<<"1"<<endl;
        return 0;
    }
    ans=2;
    calc(sum);
    cout<<ans<<endl;
    return 0;
}
