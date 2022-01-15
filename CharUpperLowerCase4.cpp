#include<iostream>
using namespace std;
class Findchar
{
public:
   char cs;
   Findchar(char a)
   {
      this->cs=a;
   }
  void CheckChar()
  {
  	if(this->cs>='a'&&this->cs<='z')
  		cout<<"Lower Case"<<endl;
  	else if(this->cs>='A'&&this->cs<='Z')
  		cout<<"Upper Case"<<endl;
  	else if(this->cs>='0'&&this->cs<='9')
  		cout<<"Digits"<<endl;
  	else
  		cout<<"Special Character"<<endl;
  }
};
int main()
{
	char a;
	cout<<"Enter the Character: "<<endl;
	cin>>a;
	Findchar c(a);
	c.CheckChar();
	return 0;
}