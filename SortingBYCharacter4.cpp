#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<string> s;
    cout<<"Enter the number of names to be inserted: "<<endl;
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
    { 
    	string name;
    	cin>>name;
    	s.insert(name);
    }
    cout<<"After Sorting: "<<endl;
    for(auto it:s)
    {
    	cout<<it<<endl;
    }
	return 0;
}