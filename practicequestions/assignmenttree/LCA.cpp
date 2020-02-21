#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int val){
        left=NULL;
        right=NULL;
        this->val=val;
    }
};
void display(TreeNode*);
TreeNode* createlevel(vector<int>&);

TreeNode * LCA_node=NULL;
bool helper(TreeNode* node,int x,int y){
    if (node == NULL)
            return false;

        bool selfDone = node->val == x || node->val== y;

        bool left = helper(node->left, x, y);
        if (LCA_node != NULL)
            return true;

        bool right = helper(node->right,x, y);
        if (LCA_node != NULL)
            return true;

        if ((left && right) || (left && selfDone) || (right && selfDone)) {
            LCA_node = node;
            return true;
        }

        return left || right || selfDone;

}






void solve(TreeNode* root,int x,int y){
    LCA_node=NULL;
helper(root,x,y);
cout<<LCA_node->val;

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

    int x,y;
    cin>>x>>y;
    TreeNode* root=createlevel(arr);
    // display(root);
    solve(root,x,y);

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
    s+="->"+to_string(root->val)+"<-";
    s+=root->right?to_string(root->right->val):".";
    cout<<s<<endl;
    display(root->left);
    display(root->right);
}