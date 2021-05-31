#include<bits/stdc++.h>
using namespace std;
#define ll long long
using namespace std;
int main(){
  ll n,m;
  cout<<"Enter the length of number 1 and number 2"<<endl;
  cin>>n>>m;
  ll a[n],b[m];
  for(ll i=0;i<n;i++)cin>>a[i];
  for(ll i=0;i<m;i++)cin>>b[i];
  ll i=n-1,j=m-1;
  ll rem=0;
  ll sum;
  vector<ll>v;
  while(i>=0 && j>=0)
  {
    sum=a[i]+b[j]+rem;
    rem=sum/10;
    v.push_back(sum%10);
    i--;
    j--;
  }
  if(i>=0)
  {
while(i>=0)
{
  sum=rem+a[i];
  rem=sum/10;
  v.push_back(sum%10);
  i--;
}
}
else if(j>=0)
{
  while(j>=0)
  {
    sum=rem+b[j];
    rem=sum/10;
    v.push_back(sum%10);
    j--;
  }
}
reverse(v.begin(),v.end());
for(ll i=0;i<(ll)v.size();i++)
cout<<v.at(i)<<" ";
}
