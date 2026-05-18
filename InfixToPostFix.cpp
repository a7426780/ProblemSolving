#include<iostream>
using namespace std;

int preference(char);

class expPost{
	private:
		char exp_Stack[50];
		int top;
		
	public:
		expPost(){
			top = -1;
		}			
		void read(char []);
		void push(char);
		char pop();
};

int main(){
	expPost obj;
	
	char expression[50];	
	cout<<"Enter Infix Expression: ";
	cin>>expression;
	
	obj.read(expression);	
	
	return 0;	
}

void expPost::read(char str_exp[])
{				
	char ch, output[80], temp;
	int c = 0;
	
	for(int i=0; str_exp[i] != '\0'; i++)
	{		
		ch = str_exp[i];
		
		if(isalpha(ch) || isdigit(ch)){
			output[c] = ch;
			c++;
		}
		
		else if(ch == '('){
			push(ch);
		}
		
		else if(ch == ')'){
			temp = pop();
			while(temp != '('){
				output[c] = temp;
				c++;
				temp = pop();
			}
		}
		
		else if(ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
		{
			if (top == -1){
				push(ch);
			}		
			else{
				int op_ch;
				op_ch = preference(ch);
				while(preference(exp_Stack[top]) >= op_ch && top != -1){
					temp = pop();
					output[c] = temp;
					c++;				
				}	
				push(ch);							
			}		
		}
	}
	
	int j;
	for(j=c; top>=0; j++){
		output[j] = pop();
	}
	output[j] = '\0';
	cout<<"PostFix Exp: "<<output;
}
			
void expPost::push(char x){				
		top++;
		exp_Stack[top] = x;						
}

char expPost::pop(){
	char r;
	r =	exp_Stack[top];	
	top--;
	return r;						
}
			
int preference(char op){
	switch(op)
	{
		case '^':
			return 4;
			break;
			
		case '/':
		case '*':
			return 3;
			break;
			
		case '+':
		case '-':
			return 2;
			break;
			
		default:
			return 0;
	}
}
