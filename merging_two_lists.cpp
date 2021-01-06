#include<bits/stdc++.h>
using namespace std;

int* merging_two_list(int *a,int n1,int *b,int n2){
	int *merged_list;
	if(n1 == 0 && n2 == 0){
		return NULL;
	}
	if(n1 == 0){
		merged_list = new int[n2];
		for(int i=0;i<n2;i++){
			merged_list[i] = b[i];
		}
	}
	else if(n2 == 0){
		merged_list = new int[n1];
		for(int i=0;i<n1;i++){
			merged_list[i] = a[i];
		}
	}
	else{
		merged_list = new int[n1+n2];
		int i=0;
		int j=0;
		int k=0;
		while(i<n1 && j<n2){
			if(a[i]<=b[j]){
				merged_list[k] = a[i];
				k++;
				i++;
			}
			if(a[i]>b[j]){
				merged_list[k] = b[j];
				k++;
				j++;
			}
		}
		while (i < n1){
			merged_list[k++] = a[i++];
		}
        while (j < n2){
        	merged_list[k++] = b[j++]; 
	    }
	return merged_list;
}
}
void print_list(int *a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
}
int main(){
	int n1,n2;
	cout<<"Enter the size of lists you want"<<endl;
	cin>>n1>>n2;
	int *a = new int[n1];
	int *b = new int[n2];
	for(int i=0;i<n1;i++){
		cout<<"Enter "<<i<<" elements of list a"<<endl;
		cin>>a[i];
	}
	for(int i=0;i<n2;i++){
		cout<<"Enter "<<i<<" elements of list b"<<endl;
		cin>>b[i];
	}
	//print_list(a,n1);
	//cout<<endl;
	//print_list(b,n2);
	//cout<<endl;
	int *x = merging_two_list(a,n1,b,n2);
	print_list(x,n1+n2);
}