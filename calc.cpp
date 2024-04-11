#include <iostream>
using namespace std;

int main()
{
      while(true){
        cout<<"\npress 1 for addition,\n press 2 for subtraction,\n press 3 for muptiply ,\n press 4 for divide"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
          case 1:
          cout<<"enter numbers to add"<<endl;
          int a,b;
          cin>>a>>b;
          cout<<"sum is"<<a+b;
          break;
          case 2:
          cout<<"enter numbers to subtract"<<endl;
          int c,d;
          cin>>c>>d;
          cout<<"subtraction is"<<c-d;
          break;
          case 3:
          cout<<"enter numbers to multiply"<<endl;
          int e,f;
          cin>>e>>f;
          cout<<"product is"<<e*f;
          break;
          case 4:
          cout<<"enter numbers to divide"<<endl;
          int g,h;
          cin>>g>>h;
          cout<<"division is"<<g/h<<endl;
          break;
          default:
          cout<<"enter correct option"<<endl;
        }
          
      }
    return 0;
}
