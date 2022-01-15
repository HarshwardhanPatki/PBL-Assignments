#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char,int > m;
    char ch;
    cout<<"Enter the string to be inserted: "<<endl;
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++)
    {
        ch=a[i];
        m[ch]++;
    }
    cout<<"Frequency of each character in the string is: "<<endl;
    for(auto it:m)
    {
        cout<<it.first<<" --> "<<it.second<<endl;
    }
    return 0;
}
