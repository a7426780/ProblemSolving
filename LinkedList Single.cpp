#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* adrs;
		
		Node(int x){
			data = x;
			adrs = NULL;
		}
};

class LinkedList{
	Node* head;	
	
	public:
		LinkedList(){
			head = NULL;			
		}
		
		// Insert_Value 
		void insertData(int x){
			Node* newNode = new Node(x);			
			if(head == NULL){
				head = newNode;
			}
			else{
				Node* temp = head;
							
				while(temp->adrs != NULL){
					temp = temp->adrs;				
				}
				
				temp->adrs = newNode;
			}		
		}

		// Print_List
		void printData(){
			if(head == NULL){
				cout<<"list is empty"<<endl;
				return;
			}
			else{
				Node* temp = head;					
				while(temp != NULL){
					
					cout<<temp->data<<endl;
					temp = temp->adrs;				
				}
				cout<<endl;						
			}		
		}

		// Sort_list
		void sortData(){
			if(head == NULL){
				cout<<"list is empty"<<endl;
				return;
			}
			int c=0;
			Node* temp1 = head;
			while(temp1 != NULL){
				c++;
				temp1 = temp1->adrs;
			}
			
			for(int o=c; o>1; o--){
			
				Node* temp = head;			
				for(int i=1; i<o; i++){
					
					Node* pre = temp;
					temp = temp->adrs;
					
					if(pre->data > temp->data){
						int e_var = pre->data;
						pre->data = temp->data;
						temp->data = e_var;						
					}
				}
			}
			
			
		}
						
		// Serach_Value
		void searchData(int s){
			if(head == NULL){
				cout<<"List is Empty, So you can not search any Data"<<endl;
				return;
			}			
			Node* temp = head;
			while(temp != NULL){
				if(temp->data == s){
					cout<<"Data "<<s<<" is found in the list"<<endl;
					return;
				}
				temp = temp->adrs;														
			}
			cout<<"Data "<<s<<" is not found in the List"<<endl;					
		}	
		
		// Delete_Value
		void deleteData(int s){
			if(head == NULL){
				cout<<"List is Empty, So you can not Delete any Data"<<endl;
				return;
			}		
			
			if(head->data == s){
				Node* headDel = head;
				head = head->adrs;
				delete headDel;
				cout<<"Data "<<s<<" is Exist in the list, Now it will be deleted"<<endl;				
			}							
			
			Node* temp = head;
			Node* pre = NULL;
			while(temp != NULL && temp->data != s){
				pre = temp;
				temp = temp->adrs;
			}
			
			if(temp == NULL){
				cout<<"Data "<<s<<" is not found in the List you want to delete"<<endl;
				return;
			}
			
			pre->adrs = temp->adrs;
			delete temp;
			cout<<"Data "<<s<<" was found and deleted from the List."<<endl;			
		}				
};

int main(){
	LinkedList list;
	int insert_val, search_val, delete_val;
	
	for(int i=1; i<=3; i++){
		cout<<"Enter the value of Node is ";	
		cin>>insert_val;
		list.insertData(insert_val);
	}
	
	cout<<"\nThese values are in the List:"<<endl;
	list.printData();
		
	cout<<"\nEnter the value that you want to Search: "<<endl;
	cin>>search_val;
	list.searchData(search_val);

	cout<<"\nNow Data is sort in ascending order"<<endl;
	list.sortData();
	list.printData();
	
	cout<<"\nEnter the value that u want to Delete: "<<endl;
	cin>>delete_val;
	list.deleteData(delete_val);
	
	cout<<"\nThese values are in the List after Deletion: "<<endl;
	list.printData();
	
	return 0;
}
