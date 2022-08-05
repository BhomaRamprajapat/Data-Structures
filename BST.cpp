#include<iostream>

using namespace std;

struct Node
{
 int val;
 Node* left;
 Node* right;
};

Node* makeNode(int n)
{
 Node* tmp=new Node;
 
 tmp->val=n;
 tmp->left=tmp->right=NULL;
 
 return tmp;
}

Node* insert(Node* root,int val)
{
 if(!root)
  root=makeNode(val);
 else if(val<root->val)
  root->left=insert(root->left,val);
 else 
  root->right=insert(root->right,val);
 return root;
}

void inOrder(Node* root)
{
 if(!root) return;
 inOrder(root->left);
 cout<<root->val<<" ";
 inOrder(root->right);
}

void preOrder(Node* root)
{
 if(!root) return;
 cout<<root->val<<" ";
 inOrder(root->left);
 inOrder(root->right);
}

void postOrder(Node* root)
{
 if(!root) return;
 inOrder(root->left);
 inOrder(root->right);
 cout<<root->val<<" ";
}

int main()
{
 Node* root=NULL;

 int arr[]={45, 36, 76, 23, 89, 115, 98, 39, 41, 56, 69, 48};
 int n=sizeof(arr)/sizeof(int);

 for(int i=0;i<n;i++)
  root=insert(root,arr[i]);

 cout<<"\nPreorder Traversal of BST   : ";
 preOrder(root);
 cout<<"\nInorder Traversal of BST    : ";
 inOrder(root);
 cout<<"\nPostorder Traversal of BST  : ";
 postOrder(root);
 
 cout<<endl;

 return 0;
}

Node* search(Node* root,int val)
{
 if(!root) 
  return root;
 else if(root->val==val) 
  return root;
 else if(val<root->val)
  return search(root->left,val);

  return search(root->right,val);
}




















