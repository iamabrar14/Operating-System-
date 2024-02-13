#include<bits/stdc++.h>
using namespace std;

struct process {
  int id;
  int AT,BT;
};

bool comp(struct process p1, struct process p2) {
//  if(p1.BT < p2.BT) return true;
//  else return false
//if(p1.BT==p2.BT){
//
//
//}
//else{
//    if(p1.BT<p2.BT) return true;
//    else return false;
//}
if(p1.AT<p2.AT) return true;
    else return false;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
  struct process p[n];
  for(int i=0;i<n;i++)
  {   cout<<"Enter id,at,bt of process "<<i+1<<": ";
      cin>>p[i].id>>p[i].AT>>p[i].BT;
  }
  for(int i=0;i<n;i++)
  {   cout<<p[i].id<<" "<<p[i].AT<<" "<<p[i].BT<<" "<<endl;
  }
  sort(p,p+n,comp);
  cout<<"Sorted : ";
  for(int i=0;i<n;i++)
  {   cout<<p[i].id<<" "<<p[i].AT<<" "<<p[i].BT<<" "<<endl;
  }
  return 0;
}
