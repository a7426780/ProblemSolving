#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* adrsP;
	Node* adrsN;
	
	Node(int x){
		data = x;
		adrsP = NULL;
		adrsN = NULL;
	}		
};

class DoubleLinkedList{
	Node* head;
		
	public:
	DoubleLinkedList(){
		head = NULL;
	}
	
	void addNode_last(int value){		
		Node* newNode = new Node(value);
		if(head == NULL){
			head = newNode;
			return;
		}		
		Node*  temp = head;		
		while(temp->adrsN != NULL){
			temp = temp->adrsN;
		}
		temp->adrsN = newNode;
		newNode->adrsP = temp;		
	}
	
	void searchNode(int search_val){
		if(head == NULL){
			cout<<"List is Empty"<<endl;
			return;
		}			
		Node* temp = head;			
		while(temp != NULL){
			if(temp->data == search_val){
				cout<<"Searching value "<<search_val<<" is found"<<"\n"<<endl;
				return;
			}
			temp = temp->adrsN;
		}
		cout<<"Searching value "<<search_val<<" is not found"<<"\n"<<endl;
	}


	void deleteNode(int del_val){
		if(head == NULL){
			cout<<"List is Empty"<<endl;
			return;
		}			
		Node* temp = head;			
		while(temp != NULL){
			if(temp->data == del_val){
				// if delete the head 			
				if(temp == head){		
					head = temp->adrsN;
					if(head != NULL){
						head->adrsP = NULL;
					}				
				}
				// if delete the last node
				else if(temp->adrsN == NULL){
						temp->adrsP->adrsN = NULL;
				}
				// if delete the middle node
				else{
					temp->adrsP->adrsN = temp->adrsN;
					temp->adrsN->adrsP = temp->adrsP;					
				}				
				delete temp;
				cout<<"Value "<<del_val<<" is successfully deleted"<<"\n"<<endl;
				return;
			}
			temp = temp->adrsN;
		}
		cout<<"Value "<<del_val<<" is not found"<<"\n"<<endl;
	}
		
	void showList(){
		if(head == NULL){
			cout<<"List is Empty";
			return;
		}	 
		Node* temp = head;
		while(temp != NULL){
			cout<<temp->data<<"   ";
			temp = temp->adrsN;			
		}
		cout<<"\n"<<endl;
	}
	
	void showListReverse(){
		if(head == NULL){
			cout<<"List is Empty";
			return;
		}	 
		Node* temp = head;
		while(temp->adrsN != NULL){
			temp = temp->adrsN;			
		}			
		while(temp != NULL){
			cout<<temp->data<<"   ";
			temp = temp->adrsP;			
		}
		cout<<"\n"<<endl;		
	}	
};

int main(){
	DoubleLinkedList obj;
	int search_val, del_val;
	
	obj.addNode_last(64);
	obj.addNode_last(54);
	obj.addNode_last(74);
	obj.addNode_last(44);
	obj.addNode_last(94);
	obj.addNode_last(24);
	obj.showList();
	
	cout<<"Enter the searching Node value: ";
	cin>>search_val;	
	obj.searchNode(search_val);
	
	cout<<"Enter the Node value that u want to Delete: ";
	cin>>del_val;	
	obj.deleteNode(del_val);
	
	obj.showListReverse();
		
	return 0;
}
