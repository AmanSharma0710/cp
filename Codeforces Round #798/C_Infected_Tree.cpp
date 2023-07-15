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
int power(int x, int y, int p){
    int res = 1; 
    x = x % p;  
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
    unsigned result = 1;
    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);
        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }
    return result;
}

bool isPrime(unsigned n) {
    if (n < 2)
        return false;
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;
    for (unsigned a : {2, 7, 61}) {
        unsigned x = mod_pow(a % n, d, n);
        if (x <= 1 || x == n - 1)
            continue;
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);
        if (x != n - 1)
            return false;
    }
    return true;
}

class Node{
public:
    int data, dp=-1;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

vector<vector<int>> adj;
Node* make_tree(int node, int parent){
    int children = 0;
    for(int i=0; i<adj[node].size(); i++){
        if(adj[node][i] != parent){
            children++;
        }
    }
    if(children == 0){
        return new Node(1);
    }
    if(children == 1){
        int child = -1;
        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i] != parent){
                child = adj[node][i];
            }
        }
        Node* child_node = make_tree(child, node);
        return new Node(1, child_node, NULL);
    }
    if(children == 2){
        int child1 = -1, child2 = -1;
        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i] != parent){
                if(child1 == -1){
                    child1 = adj[node][i];
                }
                else{
                    child2 = adj[node][i];
                }
            }
        }
        Node* child1_node = make_tree(child1, node);
        Node* child2_node = make_tree(child2, node);
        return new Node(1, child1_node, child2_node);
    }
    assert(false);
    return NULL;
}

void fill_tree(Node* root){
    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(root->left != NULL){
        fill_tree(root->left);
        root->data += root->left->data;
    }
    if(root->right != NULL){
        fill_tree(root->right);
        root->data += root->right->data;
    }
    return;
}

vector<int> dp;

int dfs(Node* root){
    if(root->dp!=-1){
        return root->dp;
    }
    if(root->left == NULL && root->right == NULL){
        root->dp = 0;
        return 0;
    }
    if(root->left != NULL && root->right != NULL){
        return root->dp = max(dfs(root->left) + root->right->data - 1, dfs(root->right) + root->left->data - 1);
    }
    if(root->left != NULL){
        return root->dp = root->left->data - 1;
    }
    if(root->right != NULL){
        return root->dp = root->right->data - 1;
    }
    assert(false);
    return -1;
}


void solve(){
    int n;
    cin>>n;
    adj.assign(n, vector<int>());
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Node* root = make_tree(0, -1);
    fill_tree(root);
    dfs(root);
    cout<<root->dp<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
