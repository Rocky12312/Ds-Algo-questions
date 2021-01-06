#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node*left;
	node*right;
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};
void preorder(node*root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right);
}
void inorder(node*root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}
void postorder(node*root){
	if(root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<endl;
}
void levelorder(node*root){
	queue<node*> q;
	node*temp = root;
	while(temp){
		cout<<temp->data<<endl;
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
		temp = q.front();
		q.pop();
	}
}
int height(node*root){
	node*temp = root;
	if(temp == NULL){
		return 0;
	}
	return 1+max(height(temp->left),height(temp->right));
}
int height1(node*root){
	node*temp = root;
	if(temp == NULL){
		return 0;
	}
	else{
		int lheight = height1(root->left);
		int rheight = height1(root->right);
		if(lheight>rheight){
			return lheight+1;
		}
		else{
			return rheight+1;
		}
	}
}
int diameter(node*root){
	node*temp = root;
	if(temp == NULL){
		return 0;
	}
	int lheight = height1(root->left);
	int rheight = height1(root->right);
	int ldiameter = diameter(root->left);
	int rdiameter = diameter(root->right);

	return max(lheight+rheight+1,max(ldiameter,rdiameter));
}
//LCA on a simple binary tree
node*lowest_common_ancestor_bst(node*root,int a,int b){
	node*temp = root;
	while(temp!=NULL){
		if(temp->data > a && temp->data > b){
			temp = temp->left;
		}
		else if(temp->data < a && temp->data < b){
			temp = temp->right;
		}
		else{
			break;
		}
	}
	return temp;
}

void iterativepreorder(node*root){
	if(root == NULL){
		return;
	}
	stack<node*> s;
	s.push(root);
	while(s.empty() == false){
		node*temp = s.top();
		cout<<temp->data<<endl;
		s.pop();
		if(temp->right){
			s.push(temp->right);
		}
		if(temp->left){
			s.push(temp->left);
		}
	}
}

void iterativepostorder(node*root){
	node*temp = root;
	if(temp == NULL){
		return;
	}
	stack<node*> s;
	stack<node*> s1;
	s.push(temp);
	while(s.empty() == false){
		node*px = s.top();
		s1.push(s.top());
		s.pop();
		if(px->left){
			s.push(px->left);
		}
		if(px->right){
			s.push(px->right);
		}
	}
	while(s1.empty() == false){
		node*fp = s1.top();
		cout<<fp->data<<endl;
		s1.pop();
	}
}

void iterativeinorder(node*root){
	node*temp = root;
	if(temp == NULL){
		return;
	}
	stack<node*> s;
	while(s.empty() == false || temp != NULL){
		if(temp != NULL){
			s.push(temp);
			temp = temp->left;
		}else{
			temp = s.top();
			s.pop();
			cout<<temp->data<<endl;
			temp = temp->right;
		}
	}
}

int path_sum(node*root){
	node*temp = root;
	if(temp == NULL){
		return 0;
	}
	else{
		int lsum = temp->data+path_sum(temp->left);
		int rsum = temp->data+path_sum(temp->right);
		if(lsum>rsum){
			return lsum;
		}
		else{
			return rsum;
		}
	}
}

int maximum_path_sum_binary_tree(node*root){
	if(root == NULL){
		return 0;
	}
	int llsum = path_sum(root->left);
	int rrsum = path_sum(root->right);
	int ls = maximum_path_sum_binary_tree(root->left);
	int rs = maximum_path_sum_binary_tree(root->right);

	return max(llsum+rrsum+root->data,max(ls,rs));
}

void print_top_view_of_binary_tree(node*root){
	node*temp = root;
	if(temp == NULL){
		return;
	}
	while(temp){
		cout<<temp->data<<endl;
		temp = temp->left;
	}
	temp = root->right;
	while(temp){
		cout<<temp->data<<endl;
		temp = temp->right;
	}
}

void print_all_leaf_nodes(node*root){
	node*temp = root;
	if(temp == NULL){
		return;
	}
	print_all_leaf_nodes(temp->left);
	if(temp->left == NULL && temp->right == NULL){
		cout<<temp->data<<endl;
	}
	print_all_leaf_nodes(temp->right);
}

int heights_for_vec(node*root){
	node*temp = root;
	if(temp == NULL){
		return 0;
	}
	else{
		int lh = heights_for_vec(temp->left);
		int rh = heights_for_vec(temp->right);
		if(lh>rh){
			return lh+1;
		}else{
			return rh+1;
		}
	}
}

vector<vector<string>> print_binary_tree(node*root){
	int x = heights_for_vec(root);
	//Number of strings per vector
	int nospv = 1*pow(2,x)-1;
	vector<int> v;
	queue<node*> q;
	q.push(root);
	while(q.empty() == false){
		node*tempx = q.front();
		v.push_back(tempx->data);
		q.pop();
		if(tempx->left){
			q.push(tempx->left);
		}
		if(tempx->right){
			q.push(tempx->right);
		}
	}
	vector<vector<string>> vs;
	vector<string> vss;
	for(int i=1;i<x+1;i++){
		for(int j=0;j<i;j++){
			vss.push_back(to_string(v[j]));
		}
		vs.push_back(vss);
	}
	return vs;
}

int main(){
	node*root = new node(4);
	root->left = new node(5);
	root->right = new node(6);
	root->left->left = new node(7);
	root->left->right = new node(8);
	root->right->left = new node(9);
	root->right->right = new node(10);
	root->left->left->left = new node(11);
	root->left->left->right = new node(12);
	preorder(root);
	inorder(root);
	postorder(root);
	levelorder(root);
	int h = height(root);
	int h1 = height1(root);
	cout<<h<<endl;
	cout<<h1<<endl;
	int d = diameter(root);
	cout<<d<<endl;
	node*tempx = lowest_common_ancestor_bst(root,10,11);
	cout<<tempx->data<<endl;
	iterativeinorder(root);
	int a = path_sum(root);
	cout<<a<<endl;
	int mpsbt = maximum_path_sum_binary_tree(root);
	cout<<mpsbt<<endl;
	print_top_view_of_binary_tree(root);
	print_all_leaf_nodes(root);
	vector<vector<string>> sx;
	sx = print_binary_tree(root);
}