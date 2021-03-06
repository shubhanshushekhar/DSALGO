#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    TreeNode* rightnext;
    int val;
    TreeNode(int val){
        left=NULL;
        right=NULL;
        rightnext=NULL;
        this->val=val;
    }
};
void display(TreeNode*);
TreeNode* createlevel(vector<int>&);

TreeNode * getnextright(TreeNode * root){
    TreeNode * temp=root->rightnext;

    while(temp!=NULL){
        if(temp->left){
            return temp->left;
        }
        else if(temp->right){
            return temp->right;
        }
        else{
            temp=temp->rightnext;
        }
    }
    return NULL;
}
void solve(TreeNode * root){
TreeNode* curr=root;

while(curr!=NULL){
    TreeNode * itr=curr;
    while(itr!=NULL){
        if(itr->left){
            if(itr->right){
                itr->left->rightnext=itr->right;
                 itr->right->rightnext=getnextright(itr);
            }
            else{
                itr->left->rightnext=getnextright(itr);
            }
        }
        else if(itr->right){
            itr->right->rightnext=getnextright(itr);
        }
            itr=itr->rightnext;
    }

    if(curr->left){
        curr=curr->left;
    }
    else if(curr->right){
        curr=curr->right;
    }
    else{
        curr=getnextright(curr);
    }
}

}














int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }

 
    TreeNode* root=createlevel(arr);
    // display(root);
    solve(root);
    display(root);

}

TreeNode* createlevel(vector<int> &arr){
    int n=arr.size();
    vector<TreeNode*> root(n);
    for(int i=0;i<n;i++){
        if(arr[i]!=-1){
          root[i]=new TreeNode(arr[i]);
            if(i>0){
                int pi=(i-1)/2;
                if(2*pi+1==i){
                    root[pi]->left=root[i];
                }
                else{
                    root[pi]->right=root[i];
                }
            }
        }
    }
    return root[0];
}
void display(TreeNode* root){
    if(root==NULL)return;

    string s;
    s+=root->left?to_string(root->left->val):".";
    s+=" <= "+to_string(root->val)+" => ";
    s+=root->right?to_string(root->right->val):".";
    s+="["+ (root->rightnext!=NULL?to_string(root->rightnext->val):"null")+"]";
    cout<<s<<endl;
    display(root->left);
    display(root->right);
}