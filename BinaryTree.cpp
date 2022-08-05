#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int max(int a,int b)
{
 return a>b?a:b;
}

struct Node
{
 int val;
 Node* left;
 Node* right;
};

Node* makeNode(int val)
{
 Node* tmp=new Node;
 tmp->val=val;
 tmp->left=tmp->right=NULL;
 return tmp;
}

Node* createBinaryTree(Node* root,int l,int r,queue<Node*> &q)
{
 Node* tmp;

 if(!root)
 {
  root=tmp=makeNode(l);
  q.push(root); 
  }
 else
 {
  Node* ptr=q.front();
            q.pop();
  
  
  if(l!=-1)
  {
   tmp=makeNode(l);
   ptr->left=tmp;
   q.push(tmp);
  }

  if(r!=-1)
  {
   tmp=makeNode(r);
   ptr->right=tmp;
   q.push(tmp);   
  }
 }
 return root;
}

void inOrderRecursive(Node* root)
{
 if(!root)
  return;
 inOrderRecursive(root->left);
 cout<<root->val<<" ";
 inOrderRecursive(root->right);
}

void preOrderRecursive(Node* root)
{
 if(!root)
  return;
 cout<<root->val<<" ";
 preOrderRecursive(root->left);
 preOrderRecursive(root->right);
}

void postOrderRecursive(Node* root)
{
 if(!root)
  return;
 postOrderRecursive(root->left);
 postOrderRecursive(root->right);
 cout<<root->val<<" ";
}

void preOrderItr(Node *root)
{
 stack<Node*> s;

 while(root || !s.empty())
 {
  if(root)
  {
   cout<<root->val<<" ";
   s.push(root);
   root=root->left;
  }
  else
  {
   Node* tmp=s.top();
   s.pop();
   
   if(tmp->right)
    root=tmp->right;
  }
 }  
}

void inOrderItr(Node* root)
{
 stack<Node*> s;

 while(root || !s.empty())
 {
  if(root)
  {
   s.push(root);
   root=root->left;
  }
  else
  {
   Node* tmp=s.top();
   s.pop();

   cout<<tmp->val<<" ";
   
   if(tmp->right)
    root=tmp->right;
  }
 }
} 

void postOrderItr(Node* root)
{
 stack<Node*> s;

 while(root || !s.empty())
 {
  if(root)
  {
   s.push(root);
   root=root->left;
  }
  else
  {
   Node* tmp=s.top()->right;

   if(!tmp)
   {
    tmp=s.top();
    s.pop();

    cout<<tmp->val<<" ";

    while(!s.empty() && tmp==s.top()->right)
    {
     tmp=s.top();
     s.pop();
     cout<<tmp->val<<" ";    
    }
   }
   else
    root=tmp;
  }
 }
} 

void levelOrder(Node* root)
{
 queue<Node*> q;
 
 if(root)
 {
  cout<<root->val<<" ";
  q.push(root);
 
  while(!q.empty())
  {
   Node* tmp=q.front();
   q.pop();
   
   if(tmp->left)
   {
    cout<<tmp->left->val<<" ";
    q.push(tmp->left); 
   }
   if(tmp->right)
   {
    cout<<tmp->right->val<<" ";
    q.push(tmp->right);
   } 
  }
 }
}

int splitInorder(int *in,int val,int start,int last)
{
 for(int i=start;i<=last;i++)
  if(in[i]==val) return i;
 return -1;
}

Node* constructTreeFromInPre(int *pre,int *in,int start,int last)
{
 static int i=0;

 if(start>last) return NULL;	
 
 Node* tmp=makeNode(pre[i++]);

 if(start==last) return tmp;
 
 int splitIndex=splitInorder(in,tmp->val,start,last);

 tmp->left=constructTreeFromInPre(pre,in,start,splitIndex-1);
 tmp->right=constructTreeFromInPre(pre,in,splitIndex+1,last);

 return tmp;
}

int height(Node* root)
{
 if(!root) return -1;
 return max(height(root->left),height(root->right))+1;
}

void setLeft(int p,int x)
{
 queue<Node*> q;

 if(root)
 {
  q.push(root);
  while(!q.empty())
  {
   Node* tmp=q.front();
   q.pop();
   
   if(tmp->left)
    q.push(tmp->left);
   if(tmp->right)
    q.push(tmp->right);
 
   if(tmp->val==p)
   {
    Node* nd=makeNode(x);

    Node* lft=tmp->left;
    nd->left=lft;
    tmp->left=nd;
    return;
   }
  }
 }
}


int main()
{
 Node* root=NULL;
 queue<Node*> q; 

 root=createBinaryTree(root,1,-1,q);
 root=createBinaryTree(root,-1,2,q);
 root=createBinaryTree(root,3,-1,q);
 root=createBinaryTree(root,4,5,q);
 root=createBinaryTree(root,6,7,q);
 root=createBinaryTree(root,8,9,q);
 root=createBinaryTree(root,10,11,q);
 
 /*
                               Tree


                                1
                                 \
                                  2 
                                 /   
                                3    
                               / \
                              /   \ 
                             4     5
                            / \   / \
                           6   7 8   9
                          / \
                        10  11

 */

       
 setLeft(root,0,13);

 cout<<"\nPreorder Recursive Traversal  : ";
 preOrderRecursive(root);
 cout<<"\nInorder Recursive Traversal   : ";
 inOrderRecursive(root);
 cout<<"\nPostorder Recursive Traversal : "; 
 postOrderRecursive(root);

 cout<<"\nHeight of Tree is : "<<height(root)<<endl;
 
 

 /* Generating Tree From Inorder and PrOrder Traversal

  int pre[]={4,7,9,6,3,2,5,8,1};
  int  in[]={7,6,9,3,4,5,9,2,1};

  root=constructTreeFromInPre(pre,in,0,8);
  
  inOrderRecursive(root);

 */
 	
}





