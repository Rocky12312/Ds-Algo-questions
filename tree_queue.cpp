#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*lchild;
    node*rchild;
    node(int d){
        data = d;
        lchild = NULL;
        rchild = NULL;
    }
};
class stack_s{
    public:
    int size;
    int top;
    node**a;
    stack_s(int sz){
        size = sz;
        top = -1;
        a = new node*[sz];
    }
};
void push(stack_s *a,node*b){
    node*b = new node(1);
    if(b==NULL){
        cout<<"Stack is full"<<endl;
    }
    a->top = a->top + 1;
    a->a[a->top] = b;
}
node* pop(stack_s *a){
    if(a->top = -1){
        cout<<"stack is empty"<<endl;
    }
    a->top = a->top - 1;
    return a->a[a->top];
}
int isempty(stack_s *a){
    if(a->top == -1){
        return 1;
    }else{
        return 0;
    }
}
node* insert(node*root,int x){
    if(!root){
        return new node(x);
    }if(root->data>x){
        root->lchild = insert(root->lchild,x);
    }else{
        root->rchild = insert(root->rchild,x);
    }
    return root;
}
void IInorder(node *root)
{
    stack_s stk(20);
    while(root || !isempty(&stk)){
        if(root)
        {
            push(&stk,root);
            root=root->lchild;
            }
        else
        {
            root=pop(&stk);
            cout<<root->data<<endl;
            root=root->rchild;
            }
        }
}
void Inorder(node *root) 
{ 
    if(root == NULL) 
    { 
        return; 
    } 
    cout << root->data << endl;
    Inorder(root->lchild);  
    Inorder(root->rchild); 
} 
int main(){
    node*root = new node(5);
    insert(root,100);
    insert(root,3);
    insert(root,1);
    insert(root,15);
    insert(root,100);
    //IInorder(root);
}