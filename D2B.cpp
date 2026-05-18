#include <iostream>
using namespace std;

class bscs{
	private:
		int top;
		int arr[10];
	public:
		bscs(){
			top = -1;
		}
		
		void d2b(int value){
			int remainder;
			
			while(value > 0){
				remainder = value%2;			
				top++;
				arr[top] = remainder;
				value = value/2;
			}			
		}
	
		void print(){
			
			if(top == -1){
				cout<<"Stack is Empty"<<endl;
				return;
			}
			for(int x=top; x>=0; x--){			
				cout<<arr[x]<<endl;
			}			
		}	
};

int main() {
	bscs a;
	
	int d_val;
	
	cout<<"Enter the Decimal Number: ";
	cin>>d_val;
	
	a.d2b(d_val);
	
	a.print();	
	
	return 0;
}

