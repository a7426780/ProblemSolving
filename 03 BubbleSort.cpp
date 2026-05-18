#include<iostream>
using namespace std;

int main(){
	int cs[5];
	int i, temp;
	
	cout<<"Enter the Values: ";
	for(i=0; i<5; i++){
		cin>>cs[i];
	}	
	
	cout<<"\nValues before Sort";
	for(i=0; i<5; i++){
		cout<<cs[i]<<"   ";
	}	
	
	for(int a=0; a<5; a++)
	{
		for(int x=0; x<4; x++)
		{
			if(cs[x] > cs[x+1])
			{
				   temp = cs[x];
				  cs[x] = cs[x+1];
				cs[x+1] = temp;
				
			}
		}	
	}
	
	cout<<"\n\nValues After Sorting";
	for(i=0; i<5; i++){
		cout<<cs[i]<<"   ";
	}	
	
	return 0;
}
