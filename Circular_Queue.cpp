#include <iostream>
using namespace std;

class Circular_Queue{
	int Cir_Que[5], front, rear, size;
	
	public:
		Circular_Queue(){
			front = rear = -1;
			size = 5;	
		}	
		
		void enqueue(int value){
			if(front == (rear + 1) % size){		
				cout<<"Circular Queue is Full"<<endl;
				return;
			}
			rear = (rear + 1) % size;		
			Cir_Que[rear] = value;			
			
			if(front == -1){
				front = 0;
			}			
		}
		
		void dequeue(){
			if(front == -1 && rear == -1){ 
				cout<<"Circular Queue is Empty"<<endl;
				return;
			}
			
			Cir_Que[front] = 0;		
			
			if(front == rear){
				front = rear = -1;
			}else{
				front = (front+1)%size;
			}
			cout<<"Front data is remove from the Circular Queue."<<endl;			
		}
		
		void display(){
			if(front == -1){
				cout<<"Queue is Empty"<<endl;
				return;
			}
			cout<<"Current Values in the Queue:"<<endl;
			int index = front;
			while(true){
				cout<<Cir_Que[index]<<endl;	
				
				if(index == rear){
					break;
				}					
				index = (index + 1) % size;	
			}			
		}	
};

int main(){
	Circular_Queue obj;
	int num, options;
	bool loop = 1;
	
	while(loop){
		cout<<"\nSelect one of these Choice: \n 01 for Enqueue_Data \n 02 for Dequeue_Data \n 03 for Display_Data \n 04 for Exit \n"<<endl;
		cin>>options;
		switch(options){
			case 1:
				cout<<"Enter the value that you want to Enqueue: ";
				cin>>num;
				obj.enqueue(num);
				break;
			case 2:
				obj.dequeue();
				break;
			case 3:
				obj.display();
				break;
			case 4:
				loop = 0;
				break;
			default:
				cout<<"Invalid Option"<<endl;
		}		
	}
	return 0;
}
