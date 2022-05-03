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


bool partof(string &x, string &y){
    string a = x, b = y;
    if(a.size() > b.size()) return false;
    if(a==b) return true;
    int first = 0, second = 0;
    for(first=0; first<a.size(); first++){
        if(a[first]!='1'){
            break;
        }
    }
    for(second=0; second<b.size(); second++){
        if(b[second]!='1'){
            break;
        }
    }
    if(first==a.size() && second==b.size()){
        return true;
    }
    if(first==a.size()){
        return false;
    }
    if(second==b.size()){
        return false;
    }
    for(int i=first; i<a.size(); i++){
        if(a[i]!=b[second]){
            return false;
        }
        second++;
    }
    for(int i=second; i<b.size(); i++){
        if(b[i]!='1'){
            return false;
        }
    }
    return true;
}

bool calc(string &a, string &b){
    a.push_back('1');
    if(partof(a,b)) return true;
    reverse(a.begin(), a.end());
    if(partof(a,b)) return true;
    reverse(a.begin(), a.end());
    a.pop_back();
    while(a[a.size()-1] == '0'){
        a.pop_back();
    }
    if(partof(a,b)) return true;
    reverse(a.begin(), a.end());
    if(partof(a,b)) return true;
    return false;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x, y;
    cin>>x>>y;
    if(x==y){
        cout<<"YES"<<endl;
        return 0;
    }
    string a = bitset<64>(x).to_string();
    string b = bitset<64>(y).to_string();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while(a[a.size()-1] == '0'){
        a.pop_back();
    }
    while(b[b.size()-1] == '0'){
        b.pop_back();
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    cout<<(calc(a, b)?"YES":"NO")<<endl;

    return 0;
}
