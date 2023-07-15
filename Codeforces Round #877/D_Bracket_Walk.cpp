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


//make two segment trees, one for minimum and one for maximum


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    set<int> s1, s2;
    //s1 stores indices such that s[i]=='(' && s[i+1]=='('
    //s2 stores indices such that s[i]==')' && s[i+1]==')'
    for(int i=0; i<n-1; i++){
        if(s[i]=='(' && s[i+1]=='('){
            s1.insert(i);
        }
        if(s[i]==')' && s[i+1]==')'){
            s2.insert(i);
        }
    }
    for(int i=0; i<q; i++){
        int pos;
        cin>>pos;
        pos--;
        if(n%2){
            cout<<"NO"<<endl;
            continue;
        }
        if(s[pos]=='('){
            s[pos]=')';
            if(pos<n-1){
                if(s[pos+1]==')'){
                    s2.insert(pos);
                }
                else{
                    s1.erase(pos);
                }
            }
            if(pos>0){
                if(s[pos-1]==')'){
                    s2.insert(pos-1);
                }
                else{
                    s1.erase(pos-1);
                }
            }
        }
        else{
            s[pos]='(';
            if(pos<n-1){
                if(s[pos+1]==')'){
                    s2.erase(pos);
                }
                else{
                    s1.insert(pos);
                }
            }
            if(pos>0){
                if(s[pos-1]==')'){
                    s2.erase(pos-1);
                }
                else{
                    s1.insert(pos-1);
                }
            }
        }
        //s1 stores indices such that s[i]=='(' && s[i+1]=='('
        //s2 stores indices such that s[i]==')' && s[i+1]==')'
        bool flag = true;
        if((s1.size()==0) ^ (s2.size()==0)){
            flag = false;
        }
        if(s1.size() && s2.size()){
            if(*s1.begin()>*s2.begin()){
                flag = false;
            }
            if(*s1.rbegin()>*s2.rbegin()){
                flag = false;
            }
        }
        if(s[0]==')' || s[n-1]=='('){
            flag = false;
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}