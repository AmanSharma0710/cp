#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
#define mod 1000000007

bool isVowel(char c){
    if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
        return true;
    }
    return false;
}

void solve(){
    string s, v="", c="";
    cin>>s;
    int length=0, nvowels=0, nconsonants=0, vmaxcount = 0, cmaxcount=0;
    int arr[26]={0};
    while(s[length]!='\0'){
        if(isVowel(s[length])){
            nvowels++;
        }
        else{
            nconsonants++;
        }
        arr[s[length]-'A']++;
        length++;
    }
    vmaxcount = max(vmaxcount, arr[0]);
    vmaxcount = max(vmaxcount, arr[4]);
    vmaxcount = max(vmaxcount, arr[8]);
    vmaxcount = max(vmaxcount, arr[14]);
    vmaxcount = max(vmaxcount, arr[20]);
    rep(i, 0, 26){
        if(i==0 || i==4 || i==8 || i==14 || i==20){
            continue;
        }
        cmaxcount = max(cmaxcount, arr[i]);
    }

    cout<<min(nvowels + 2*(nconsonants - cmaxcount), nconsonants + 2*(nvowels - vmaxcount))<<endl;

    

}


signed main(){
    int t, count = 1;
    cin>>t;
    while (t--){
        printf("Case #%d: ", count++);
        solve();       
    }
    return 0;
}
