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

class Circular_LinkedList{
	Node* head;	
	
	public:
		Circular_LinkedList(){
			head = NULL;			
		}
		
		// Insert_Value 
		void insertData(int x){
			Node* newNode = new Node(x);			
			if(head == NULL){
				head = newNode;
				newNode->adrs = head;
				return;
			}			
			
			Node* temp = head;
									
			while(temp->adrs != head){
				temp = temp->adrs;				
			}				
			temp->adrs = newNode;
			newNode->adrs = head;
		}		

		// Print_List
		void printData(){
			if(head == NULL){
				cout<<"list is empty"<<endl;
				return;
			}
			
			Node* temp = head;					
			
			do{					
				cout<<temp->data<<"   ";
				temp = temp->adrs;				
			}while(temp != head);
				
			cout<<endl;				
		}		
						
		// Serach_Value
		void searchData(int s){
			if(head == NULL){
				cout<<"List is Empty, So you can not search any Data"<<endl;
				return;
			}			
			Node* temp = head;
			
			do{
				if(temp->data == s){
					cout<<"Data "<<s<<" is found in the list"<<endl;
					return;
				}
				temp = temp->adrs;														
			}while(temp != head);
			cout<<"Data "<<s<<" is not found in the List"<<endl;					
		}	
		
		// Delete_Value
		void deleteData(int s){
    		if(head == NULL){
        		cout<<"List is Empty, so you cannot delete any data"<<endl;
        		return;
    		}

		    Node* temp = head;
		    Node* prev = NULL;
		
		    // Special case: head node needs to be deleted
		    if(head->data == s){
		        // Find the last node to update its next pointer
		        Node* last = head;
		        while(last->adrs != head){
		            last = last->adrs;
		        }
		
		        // If only one node exists
		        if(head == head->adrs){
		            delete head;
		            head = NULL;
		            cout<<"Data "<<s<<" deleted. List is now empty."<<endl;
		            return;
		        }
		
		        // More than one node
		        Node* headDel = head;
		        head = head->adrs;      // Move head
		        last->adrs = head;      // Update last node's next
		        delete headDel;
		        cout<<"Data "<<s<<" was head and deleted successfully."<<endl;
		        return;
		    }
		
		    // For non-head nodes
		    prev = head;
		    temp = head->adrs;
		    do{
		        if(temp->data == s){
		            prev->adrs = temp->adrs;
		            delete temp;
		            cout<<"Data "<<s<<" found and deleted successfully."<<endl;
		            return;
		        }
		        prev = temp;
		        temp = temp->adrs;
		    }while(temp != head);
		
		    cout<<"Data "<<s<<" not found in the list."<<endl;
		}
		
};

int main(){
	Circular_LinkedList list;
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
	
	cout<<"\nEnter the value that u want to Delete: "<<endl;
	cin>>delete_val;
	list.deleteData(delete_val);
	
	cout<<"\nThese values are in the List after Deletion: "<<endl;
	list.printData();
	
	return 0;
}
