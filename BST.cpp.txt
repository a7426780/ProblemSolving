#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

class BST{
	private:
		Node* head;
	public:
		BST(){
			head = NULL;
		}
		
		void addNode(int value){
			Node* newNode = new Node(value);
			
			if(head == NULL){
				head = newNode;
				return;
			}
			
			Node* temp = head;
			Node* parent = NULL;
			
			while(temp != NULL){
				parent = temp;
				if(temp->data == value){
					cout<<"Same value in not allow"<<endl;
					return;
				}
				if(temp->data > value){
					temp = temp->left;
				}
				else{
					temp = temp->right;
				}
			}
				
			if(parent->data > value){
				parent->left = newNode;
			}else{
				parent->right = newNode;
			}		
		}
		
		void inorder(Node* head){
			if(head != NULL){			
				inorder(head->left);
				cout<<head->data<<"  ";
				inorder(head->right);
			}
		}
		
		void showTree(){
        	inorder(head);
        }				
};

int main(){
	BST obj;
	int arr[] = {67, 86, 93, 20, 13, 99, 105, 21, 110, 47};

	for(int i=0; i<10; i++){
		obj.addNode(arr[i]);
	}
	
	obj.showTree();
		
	return 0;
}
