#include<iostream>
using namespace std;

class graph{
	private:
		int graphArr[10][10];
	public:
		void createGraph(){
			for(int r=0; r<10; r++){
				for(int c=0; c<10; c++){
					graphArr[r][c] = 0;
					cout<<graphArr[r][c]<<"    ";
				}
				cout<<endl;
			}
			cout<<"\n \n"<<endl;
		}
		
		int addEdge(int x, int y, int weight){
			if((x>=0 && x<10) && (y>=0 && y<10)){
				graphArr[x][y] = weight;
				graphArr[y][x] = weight;
			}			
		}
		
		int showGraph(){
			for(int r=0; r<10; r++){
				for(int c=0; c<10; c++){
					cout<<graphArr[r][c]<<"    ";
				}
				cout<<endl;
			}
			cout<<"\n \n"<<endl;
		}
		
};
int main(){
	graph obj;
	int weight;
	obj.createGraph();
	
	cout<<"Enter the weight: ";
	cin>>weight;
	
	obj.addEdge(3, 7, weight);
	obj.addEdge(4, 6, weight);
	obj.addEdge(8, 5, weight);
	
	obj.showGraph();
		
	return 0;
}
