//Every matrix whose determinant is non zero ,there exists an inverse(i.e. for all non singular matrices)
#include<bits/stdc++.h>
using namespace std;
void complete_elimination( vector<vector<double>>&a, vector<double>&b)//every element is made 0 except diagonal elements
{
  int n=a.size();
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      double factor=a[j][i]/a[i][i];
      for(int k=i;k<n;k++)
      {
        a[j][k]=a[j][k]-factor*a[i][k];
      }
      b[j]=b[j]-factor*b[i];
    }
    for(int j=n-i-2;j>=0;j--)
    {
      double factor=a[j][n-1-i]/a[n-1-i][n-1-i];
      for(int k=n-1-i;k>=0;k--)
      {
        a[j][k]=a[j][k]-factor*a[n-1-i][k];
      }
      b[j]=b[j]-factor*b[n-1-i];
    }
  }
  return ;
}
 vector<double>little_substitution(vector<vector<double>>&a, vector<double>&b)
 {
 	int n=b.size();
   vector<double>ans(n);
   for(int i=0;i<n;i++)
   ans.at(i)=b.at(i)/a[i][i];
   return ans;
 }
int main()
{
  int n;
  cout<<"Enter the number of variables"<<endl;
  cin>>n;
 vector<vector<double>>a(n,vector<double>(n,0));
 vector<double>b(n);
 cout<<"Enter the values in the matrix form for A"<<endl;
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
 cin>>a[i][j];
 cout<<"Enter the values in the matrix form for B only column matrix"<<endl;
 for(int j=0;j<n;j++)
 cin>>b[j];
 complete_elimination(a,b);
 vector<double>ans=little_substitution(a,b);
 cout<<"Solution of this system is:"<<endl;
 for(int i=0;i<(int)ans.size();i++)
 {
   cout<<"x"<<i+1<<": "<<fixed<<setprecision(6)<<ans.at(i)<<endl;
 }
 return 0;
}
