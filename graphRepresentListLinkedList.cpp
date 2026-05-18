#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* adrs;

    Node(int x) {
        data = x;
        adrs = NULL;
    }
};

class Graph {
    int vertices;
    Node* head[10];

	public:
    Graph(int v) {
        vertices = v;
        for(int i = 0; i < vertices; i++) {
            head[i] = NULL;
        }
    }

	void addEdge(int s, int d){
	    Node* newNode = new Node(d);
	    if(head[s] == NULL){
	        head[s] = newNode;
	    }else{
	        Node* temp = head[s];
	        while(temp->adrs != NULL){
	            temp = temp->next;
	        }
	        temp->next = newNode;
	    }	
	    
	    Node* newNode2 = new Node(s);
	    if(head[d] == NULL){
	        head[d] = newNode2;
	    }else{
	        Node* temp = head[d];
	        while(temp->adrs != NULL){
	            temp = temp->adrs;
	        }
	        temp->next = newNode2;
	    }
	}
	
    void addEdges(int s, int d) {
        Node* newNode = new Node(d);
        newNode->adrs = head[s];
        head[s] = newNode;

        Node* newNode2 = new Node(s);
        newNode2->adrs = head[d];
        head[d] = newNode2;
    }

    void showGraph() {
        for(int i = 0; i < vertices; i++) {
            cout<<"Vertex "<<i<<" -> ";
            Node* temp = head[i];
            while(temp != NULL) {
                cout<<temp->data<<" ";
                temp = temp->adrs;
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.showGraph();
    
    return 0;
}

