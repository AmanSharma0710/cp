#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPrefix(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPrefix(root->left);
    printPrefix(root->right);
    return;
}
void printInfix(struct Node* root){
    if(root==NULL){
        return;
    }
    printInfix(root->left);
    cout<<root->data<<" ";
    printInfix(root->right);
    return;
}
void printPostfix(struct Node* root){
    if(root==NULL){
        return;
    }
    printPostfix(root->left);
    printPostfix(root->right);
    cout<<root->data<<" ";
    return;
}

int search(int infix[], int start, int end, int val){
    for(int i=start; i<=end; i++){
        if(infix[i] == val){
            return i;
        }
    }
    return -1;
}

struct Node* buildTree1(int prefix[], int infix[], int start, int end){
    if(start>end){
        return NULL;
    }
    static int index = 0;
    int val = prefix[index++];
    struct Node* new_node = new Node(val);
    int current = search(infix, start, end, val);
    new_node->left = buildTree1(prefix, infix, start, current-1);
    new_node->right = buildTree1(prefix, infix, current+1, end);
    return new_node;
}
struct Node* buildTree2(int infix[], int postfix[], int start, int end){
    if(start>end){
        return NULL;
    }
    static int index = end;
    int val = postfix[index--];
    struct Node* new_node = new Node(val);
    int current = search(infix, start, end, val);
    new_node->right = buildTree2(infix, postfix, current+1, end);
    new_node->left = buildTree2(infix, postfix, start, current-1);
    return new_node;
}

void levelTraversal(struct Node* root){
    queue<struct Node*> q;
    if(root==NULL){
        return;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node= q.front();
        q.pop();
        if(node != NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int sumAtKLevel(struct Node* root, int k){
    int sum=0, level=0;
    queue<struct Node*> q;
    if(root==NULL){
        return -1;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node= q.front();
        q.pop();
        if(node != NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int nodeCount(Node* root){
    if(root==NULL){
        return 0;
    }
    return nodeCount(root->left) + nodeCount(root->right) + 1;
}

int nodeSum(Node* root){
    if(root==NULL){
        return 0;
    }
    return nodeSum(root->left) + nodeSum(root->right) + root->data;
}

int treeHeight(Node* root){
    if(root->left==NULL && root->right==NULL){
        return 0;
    }
    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

int treeDiameter(Node *root){
    if(root==NULL){
        return 0;
    }
    int diameter_current = treeHeight(root->left) + treeHeight(root->right) + 1;
    return max(diameter_current, max(treeDiameter(root->left), treeDiameter(root->right)));
}

int treeDiameterOptimised(Node* root, int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0, rh=0;
    int lDiameter = treeDiameterOptimised(root->left, &lh);
    int rDiameter = treeDiameterOptimised(root->right, &rh);
    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currDiameter, max(lDiameter, rDiameter));
}

void sumReplace(Node* root){
    if(root==NULL){
        return;
    }   
    sumReplace(root->left);
    sumReplace(root->right);
    if(root->left){
        root->data += root->left->data;
    }
    if(root->right){
        root->data += root->right->data;
    }
    return;
}

bool treeBalanced(Node* root, int* height){
    int lh = 0, rh=0;
    if(root==NULL){
        *height = 0;
        return true;
    }
    if(!treeBalanced(root->left, &lh)){
        return false;
    }
    if(!treeBalanced(root->right, &rh)){
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh)<=1){
        return true;
    }
    return false;
}

int maxDepth(Node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}


int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    printPrefix(root);
    cout<<endl;
    printInfix(root);
    cout<<endl;
    printPostfix(root);
    cout<<endl;
    int prefix[] = {1, 2, 4, 5, 3, 6, 7};
    int infix[] = {4, 2, 5, 1, 6, 3, 7};
    int postfix[] = {4, 5, 2, 6, 7, 3, 1};
    struct Node* root1 = buildTree1(prefix, infix, 0, 6);
    printPostfix(root1);
    cout<<endl;
    struct Node* root2 = buildTree2(infix, postfix, 0, 6);
    printPostfix(root2);
    cout<<endl;
    levelTraversal(root);
    cout<<endl;
    levelTraversal(root1);
    cout<<endl;
    levelTraversal(root2);
    cout<<endl;
    int height = 0;
    sumReplace(root2);
    levelTraversal(root2);
    cout<<endl;
    cout<<treeHeight(root)<<endl;
    cout<<maxDepth(root)<<endl;


    
    return 0;


}