#include <bits/stdc++.h>
using namespace std;
int main()
{
    int at[20],bt[20],i,j;
    int n;
    cout<<"How many process : ";
    cin>>n;
    cout<<"Enter Arrival time of process :";
    for(i=0;i<n;i++)
    {
        cin>>at[i];

    }
     sort(at, at + i);
     cout<<"Sorted : ";
    for(i=0;i<n;i++)
    {
        cout<<at[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter Bus time : ";j
        for(j=0;j<n;j++)
    {
        cin>>bt[j];

    }
    sort(bt, bt + j);
    cout<<"Sorted bus time : ";
    for(j=0;j<n;j++)
    {
        cout<<bt[j]<<" ";
    }
    return 0;
}
