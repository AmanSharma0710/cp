#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> gifts(n), boxes(m);
    for(int i=0; i<n; i++){
        cin >> gifts[i].first;
    }
    for(int i=0; i<n; i++){
        cin >> gifts[i].second;
    }
    for(int i=0; i<m; i++){
        cin >> boxes[i].first;
    }
    for(int i=0; i<m; i++){
        cin >> boxes[i].second;
    }
    sort(gifts.begin(), gifts.end());
    sort(boxes.begin(), boxes.end());
    set<int> s;
    int box = m-1;
    for(int gift = n-1; gift>=0 && box>=0; gift--){
        for(box=box; box>=0; box--){
            if(gifts[gift].first <= boxes[box].first){
                s.insert(boxes[box].second);
            }
            else{
                break;
            }
        }
        auto it = s.lower_bound(gifts[gift].second);
        if(it == s.end()){
            cout << "No" << endl;
            return 0;
        }
        s.erase(it);
    }
    cout << "Yes" << endl;
    return 0;
}
