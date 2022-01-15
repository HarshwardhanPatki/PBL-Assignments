#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Employee
{
    public:
    int emp_id,age;
    float salary;
    string name;
    string department;
    void getData()
    {
    cout<<"Enter the emp_id: ";
    cin>>this->emp_id;
    cout<<"Enter the NAME: ";
    cin>>this->name;
    cout<<"Enter the AGE: ";
    cin>>this->age;
    cout<<"Enter the DEPARTMENT: ";
    cin>>this->department;
    cout<<"Enter the SALARY: ";
    cin>>this->salary;
    }
    void showData()
    {
    cout<<"Name: "<<this->name<<endl;
    cout<<"age: "<<this->age<<endl;
    cout<<"Employee ID: "<<this->emp_id<<endl;
    cout<<"Department: "<<this->department<<endl;
    cout<<"Salary: "<<this->salary<<endl;
   }
    void InsertintoFile()
    {
       ofstream fout;
       fout.open("EmployeeDatabase.txt",ios::out|ios::binary|ios::app);
       getData();
       fout.write((char*)this,sizeof(*this));
       fout.close();
    }
    void ShowDataFromFile()
    {
        ifstream fin;
        fin.open("EmployeeDatabase.txt",ios::in|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(fin)
      {
        showData();
        fin.read((char*)this,sizeof(*this));
        cout<<endl;
      }
     fin.close();
    }
    void SearchData(int emp)
    {
        ifstream fin;
        fin.open("EmployeeDatabase.txt",ios::in|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(fin)
        {
           if(this->emp_id==emp)
           {
            cout<<"Data found: "<<endl;
            showData();
           }
           fin.read((char*)this,sizeof(*this));
        }
     fin.close();
    }
    void update(int emp)
    {
        fstream file;
        file.open("EmployeeDatabase.txt",ios::in|ios::binary|ios::out|ios::ate);
        file.seekg(0);
        file.read((char*)this,sizeof(*this));
        while(file)
        {
            if(this->emp_id==emp)
            {
                getData();
                file.seekp(file.tellg()-sizeof(Employee));
                file.write((char*)this,sizeof(*this));
            }
            file.read((char*)this,sizeof(*this));
        }
        file.close();
    }
};
int main()
{
    Employee e;
    int n;
    e.ShowDataFromFile();
    cout<<endl;
    cout<<"Insert into the file: "<<endl;
    e.InsertintoFile();
    cout<<endl;
    cout<<"Displaying From files"<<endl;
    e.ShowDataFromFile();
    cout<<endl;
    cout<<"Enter the emp id to be sreached: "<<endl;
    cin>>n;
    e.SearchData(n);
    cout<<endl;
    cout<<"Enter the emp id to be updated: ";
    cin>>n;
    e.update(n);
    cout<<"-------------------------------------------";
    cout<<endl;
    e.ShowDataFromFile();
    cout<<"Thankyou"<<endl;
    return 0;
}
   
