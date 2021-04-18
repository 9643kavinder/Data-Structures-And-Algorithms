#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
    node* build(){
        int d;
        cin>>d;
        if(d==-1){
            return NULL;
        }
        node* root = new node(d);
        root->left = build();
        root->right = build();
        return root;
    }
    void printPreOrder(node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        printPreOrder(root->left);
        printPreOrder(root->right);
        return;
    }
    void printInOrder(node* root){
        if(root==NULL){
            return;
        }
        printInOrder(root->left);
        cout<<root->data<<" ";
        printInOrder(root->right);
        return;
    }
    void LevelOrderTraversal(node* root){
        //Optimized Approach Using BFS
        queue<node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node* f = q.front();
            q.pop();
            if(f==NULL){
                if(!q.empty()){
                    cout<<endl;
                    q.push(NULL);
                }
                else{
                    cout<<endl;
                }
            }
            else{
                cout<<f->data<<" ";
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
    }
    int countNodes(node* root){
        if(root==NULL){
            return 0;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
    }

    int sumOfNodes(node* root){
        if(root==NULL){
            return 0;
        }
        return sumOfNodes(root->left)+sumOfNodes(root->right)+root->data;
    }
    int heightOfTree(node* root){
        if(root==NULL){
            return 0;
        }
        int h1 = heightOfTree(root->left);
        int h2 = heightOfTree(root->right);
        return max(h1,h2)+1;
    }
    int diameterOfTree(node* root){
        if(root==NULL){
            return 0;
        }
        int h1 = heightOfTree(root->left);
        int h2 = heightOfTree(root->right);
        int d1 = h1+h2+1;
        int d2 = diameterOfTree(root->left);
        int d3 = diameterOfTree(root->right);
        return max(d1,max(d2,d3));
    }
    //sum replacement function
    int sumReplacement(node* &root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL and root->right==NULL){
            return root->data;
        }
        int left = sumReplacement(root->left);
        int right = sumReplacement(root->right);
        int temp = root->data;
        root->data = left+right;
        return temp+left+right;
    }
    pair<int,bool> is_height_balanced_tree(node* root){
        if(root==NULL){
            return {0,true};
        }
        if(root->left==NULL and root->right==NULL){
            return {1,true};
        }
         pair<int,bool>left = is_height_balanced_tree(root->left);
         pair<int,bool>right = is_height_balanced_tree(root->right);
         pair<int,bool>p;
         p.first = max(left.first, right.first)+1;
         if(abs(left.first-right.first)<=1){
             p.second = true;
         }
         else{
             p.second = false;
         }
         return p;
    }

    // Creating Height Balanced Tree from An Array
    node* createBalanceTree(int *a,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid = (s+e)/2;
        node* root = new node(a[mid]);
        root->left = createBalanceTree(a, s,mid-1);
        root->right = createBalanceTree(a, mid+1, e);
        return root;
    }

    // Creating Tree Using Preorder And Inorder
    node* createTreeUsingPreAndIn(int *inorder,int *preorder,int s,int e){
        static int index = 0;
        if(s>e){
            return NULL;
        }
        int val = preorder[index];
        node* root = new node(preorder[index]);
        int mid = -1;
        for(int i=s;i<=e;i++){
            if(preorder[index]==inorder[i]){
                mid = i;
                break;
            }
        }
        index++;
        root->left = createTreeUsingPreAndIn(inorder, preorder, s, mid-1);
        root->right = createTreeUsingPreAndIn(inorder, preorder, mid+1, e);
        return root;
    }
    // Right View Of A Tree
    void printRightView(node* root, int current_level,int &max_level){
        if(root==NULL){
            return;
        }
        if(current_level>max_level){
            cout<<root->data<<" ";
            max_level = max(current_level, max_level);
        }
        printRightView(root->right, current_level+1, max_level);
        printRightView(root->left, current_level+1, max_level);
    }

    // Lowest Common Ancestor
    node* lowestCommonAncestor(node* root, int a,int b){
        if(root==NULL){
            return NULL;
        }
        if(root->data==a or root->data==b){
            return root;
        }
        node* left = lowestCommonAncestor(root->left, a, b);
        node* right = lowestCommonAncestor(root->right, a, b);
        if(left!=NULL and right!=NULL){
            return root;
        }
        if(left!=NULL and right==NULL){
            return left;
        }
        return right;
    }

    //search Node
    int searchNode(node* root,int a,int level){
        if(root==NULL){
            return -1;
        }
        if(root->data == a){
            return level;
        }
        int left = searchNode(root->left, a, level+1);
        if(left!=-1){
            return left;
        }
        return searchNode(root->right, a, level+1);
    }

    //Smallest distance from node to node
    int smallestDistanceFromNodeToNode(node* root, int a,int b){
        node* lca = lowestCommonAncestor(root, a, b);
        int left = searchNode(lca, a, INT_MIN);
        int right = searchNode(lca, b, INT_MIN);
        return left+right;
    }
    //Sample To Test : 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    
int main(){
    // Binary Tree
    node* root = build();
    // printPreOrder(root);
    // cout<<endl;
    // printInOrder(root);
    // LevelOrderTraversal(root);
    // int count = countNodes(root);
    // cout<<count<<endl;
    // int sum = sumOfNodes(root);
    // cout<<sum<<endl;
    // int height = heightOfTree(root);
    // cout<<height<<endl;
    // int diameter = diameterOfTree(root);
    // cout<<diameter<<endl;
    // sumReplacement(root);
    // cout<<nodesSumAfterReplacement<<endl;
    // LevelOrderTraversal(root);
    // pair<int,bool>p = is_height_balanced_tree(root);
    // if(p.second){
    //     cout<<"Tree is balanced"<<endl;
    // }
    // else{
    //     cout<<" Tree is Unbalanced"<<endl;
    // }
    // int max_level = INT_MIN;
    // printRightView(root, 0, max_level);

    // node* lca = lowestCommonAncestor(root, 3, 4);
    // cout<<lca->data<<endl;
    //------------------- Balanced Binary Tree Using Array------------------------//
    // int n;
    // cin>>n;
    // int a[n];
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // node* root = createBalanceTree(a,0,n-1);
    // LevelOrderTraversal(root);

    //------------------------------------------------------------------------------//

    //-------------------Binary Tree Using Preorder and Inorder----------------------//
    // int inorder[] = {4,2,5,1,6,3};
    // int preorder[] = {1,2,4,5,3,6};
    // node* root = createTreeUsingPreAndIn(inorder, preorder, 0, 5);
    // LevelOrderTraversal(root);
    //-------------------------------------------------------------------------------//
    


    return 0;
}