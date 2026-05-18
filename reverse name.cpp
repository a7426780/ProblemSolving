#include<iostream>
using namespace std;
class stack
{ private:
int top;
  char array[20];
public:
  stack()
  {top=-1;
  }
  void push(char a[])
  {if(top==19)
  {cout<<"stack overflow"<<endl;
     return;}
     for(int j=0; a[j]!='\0'; j++)
  { top++;
   array[top]=a[j];}
  }

  void display()
  {if(top==-1)
  {cout<<"stack is empty"<<endl;
  }
  else
  {cout<<"stack elements:";
   for(int i=top; i>=0; i--)
   {cout<<array[i]<<" ";
   }
  }
  }
};
int main()
{ stack s;
  char name[20];
  cout<<"enter name:";
  cin>>name;
  s.push(name);
  s.display();
  return 0;
}