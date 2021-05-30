//find the solutions of linear equation ,here we break the matrix A =LU ,then AX=B
/* LY=B
Y=UX*/
#include<bits/stdc++.h>
using namespace std;
void lu_decomposition(vector<vector<double>>&a,vector<vector<double>>&lower,vector<vector<double>>&upper)
{
	int n=a.size();
	for (int i = 0; i < n; i++)
	{
		for (int k = i; k < n; k++)
		{
		double sum = 0;
			for (int j = 0; j < i; j++)
				sum += (lower[i][j] * upper[j][k]);
			upper[i][k] = a[i][k] - sum;
		}
		for (int k = i; k < n; k++)
		{
			if (i == k)
				lower[i][i] = 1;
			else
			{
			double sum = 0;
				for (int j = 0; j < i; j++)
					sum += (lower[k][j] * upper[j][i]);
				lower[k][i]
					= (a[k][i] - sum) / upper[i][i];
			}
		}
	}
	return ;
}
vector<double>forward_substitution(vector<vector<double>>&lower,vector<double>&b)
{
 int n=b.size();
	vector<double>ans1(n,0);
	ans1.at(0)=b.at(0);
	for(int i=1;i<n;i++)
	{
		double sum=b.at(i);
		for(int j=0;j<i;j++)
		{
			sum=sum-lower[i][j]*ans1.at(j);
		}
		ans1.at(i)=sum;
	}
	return ans1;
}
vector<double>backward_substitution(vector<vector<double>>&upper,vector<double>&ans1)
{
	 int n=ans1.size();
	vector<double>ans(n,0);
	ans.at(n-1)=ans1.at(n-1)/upper[n-1][n-1];
	for(int i=n-2;i>=0;i--){
		double sum=ans1.at(i);
		for(int j=i+1;j<n;j++)
		{
			sum=sum-upper[i][j]*ans.at(j);
		}
		ans.at(i)=sum/upper[i][i];
	}

	return ans;
}

int main()
{
  int n;
  cout<<"Enter the number of variables: ";
  cin>>n;
  vector<vector<double>> a( n , vector<double> (n,0)),lower( n , vector<double> (n,0)),upper( n , vector<double> (n,0));
  cout<<"Enter the values in the matrix form"<<endl;
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  cin>>a[i][j];
  vector<double>b(n,0);
  cout<<"Enter the value of agumented matrix: "<<endl;
   for(int j=0;j<n;j++)
  cin>>b[j];
  lu_decomposition(a,lower,upper);
  vector<double>ans1=forward_substitution(lower,b);
  vector<double>ans=backward_substitution(upper,ans1);
  cout<<"Solutions of the system is: "<<endl;
  for(int i=0;i<ans.size();i++)
  cout<<"x"<<i+1<<": "<<fixed<<setprecision(6)<<ans.at(i)<<endl;
  return 0;
}
