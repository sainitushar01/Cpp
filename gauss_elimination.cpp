//gauss elimination
/* In forward eliination
 we make matrix a uppertriangular and starts the back substitution*/
 #include<bits/stdc++.h>
 using namespace std;
 void forward_elimination(vector< vector<double> >& a,vector<double>& b)
 {
   for(int k=0;k<a.size();k++)
   {
     for(int i=k+1;i<a.size();i++)
     {
       double factor=a[i][k]/a[k][k];
       for(int j=k+1;j<a.size();j++)
       {
         a[i][j]=a[i][j]-factor*a[k][j];
       }
       b[i]=b[i]-factor*b[k];
     }
   }
   return ;
 }
 vector<double> backward_substitution(vector< vector<double> >& a,vector<double>& b)
 {
   int n=b.size();
   vector<double>ans(n);
   ans.at(n-1)=b.at(n-1)/a[n-1][n-1];
   for(int i=n-2;i>=0;i--)
   {
    double sum=b.at(i);
     for(int j=i+1;j<n;j++)
     {
       sum=sum -ans.at(j)*a[i][j];
     }
     ans.at(i)=sum/a[i][i];
   }
   return ans;
 }
 int main()
 {
   int n;
   cin>>n;//number of equations/variables
   vector< vector<double> > a(n,vector<double>(n,0));
vector<double> b(n,0);
   cout<<"Enter the values of cofficients in matrix form"<<endl;
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<n;j++)
     {
       cin>>a[i][j];
     }
   }
   cout<<"Enter the value of the agumented matrix: "<<endl;
   for(int i=0;i<n;i++)
       cin>>b[i];
forward_elimination(a,b);
vector<double> ans=backward_substitution(a,b);
cout<<"Solution is:"<<endl;
for(int i=0;i<ans.size();i++)
cout<<"x"<<i+1<<": "<<fixed<<setprecision(6)<<ans.at(i)<<endl;
return 0;
 }
