#include <iostream>
using namespace std;

class Linear_Queue{
	int Que_Arr[5], front, rear, size;
	
	public:
		Linear_Queue(){
			front = rear = -1;
			size = 5;	
		}	
		
		void enqueue(int value){
			if(rear == size-1){	
				cout<<"Circular Queue is Full"<<endl;
				return;
			}			
			Que_Arr[rear] = value;			
			
			if(front == -1){
				front = 0;
			}			
		}
		
		void dequeue(){
			if(front == -1){
				cout<<"Circular Queue is Empty"<<endl;
				return;
			}			
			Que_Arr[front] = 0;
			front++;
			
			if(front > rear){
				front = rear = -1;
			}
		}
		
		void display(){
			if(front == -1){
				cout<<"Queue is Empty"<<endl;
				return;
			}
			cout<<"Current Values in the Queue:"<<endl;
			for(int i = front; i <= rear; i++){					
				cout<<Que_Arr[i]<<endl;
			}			
		}	
};

int main(){
	Linear_Queue obj;
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
