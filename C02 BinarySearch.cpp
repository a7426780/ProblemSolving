#include<iostream>
using namespace std;

int main(){
	int cs[10] = {05, 10, 15, 20, 25, 30, 35, 40, 45, 50};
	int se;
	int mid, first=0, last=9;
	int index = -1;

	cout<<"Enter the Searching Value: ";
	cin>>se;

	while(first < last){
		mid = (first+last)/2;
		
		if(cs[mid] == se)
		{
			index = mid;
			break;
		}
		else if(cs[mid] < se){
			first = mid + 1;
		}
		else{
			last = mid - 1;
		}
	}
	
	if(index == -1)
	{
		cout<<"Value is Not Found"<<endl;
	}
	else{
		cout<<"Value is Found at index: "<<index<<endl;	
	}
			
	return 0;
}
