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

vector<int> tree;


int maxx(int index, int start_index, int end_index, int query_start, int query_end){
    if(start_index>=query_start && query_end>=end_index){
        return tree[index];
    }
    if(start_index>query_end || query_start>end_index){
        return 0;
    }
    return max(maxx(index*2, start_index, (start_index+end_index)/2, query_start, query_end), maxx(index*2 + 1, (start_index+end_index)/2 + 1, end_index, query_start, query_end));
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, M;
    cin >> n >> m;
    M = m;
    vector<int> v(m);
    rep(i,0,m){
        cin >> v[i];
    }
    while(__builtin_popcount(m) != 1){
        v.push_back(0);
        m++;
    }
    tree.resize(2*m);
    for(int i=0; i<m; i++){
        tree[m+i] = v[i];
    }
    for(int i=m-1; i>0; i--){
        tree[i] = max(tree[2*i], tree[2*i+1]);
    }
    int q;
    cin >> q;
    for(int qq=0; qq<q; qq++){
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        y1--;
        y2--;
        if(y1>y2){
            swap(y1, y2);
            swap(x1, x2);
        }
        int max_height = maxx(1, 0, m-1, y1, y2) + 1;
        if(abs(x1-x2)%k != 0){
            cout << "NO" << endl;
            continue;
        }
        if(abs(y1-y2)%k != 0){
            cout << "NO" << endl;
            continue;
        }
        int max_pos = max(x1, x2);
        if(max_height>=max_pos){
            int diff = n - max_pos;
            int pos = max_pos + (diff/k)*k;
            if(pos<max_height){
                cout << "NO" << endl;
                continue;
            }
        }
        cout<<"YES"<<endl;
    }
    return 0;
}
