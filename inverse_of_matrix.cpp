#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<double>> getcofactor(vector<vector<double>>&a,int pi,int pj){
	int n=a.size();
	vector<vector<double>>temp(n-1,(vector<double>(n-1,0)));
	int i=0,j=0;
	for(int q=0;q<n;q++)
	{
		for(int w=0;w<n;w++)
		{
			if(q!=pi && w!=pj)
			{
				temp[i][j++]=a[q][w];
				if(j==n-1)
				{
					j=0;
					i++;
				}
			}
		}
	}
	return temp;
}
double determinant(vector<vector<double>>&a)
{
	int n=a.size();
	if(n==1)
	return a[0][0];
	if(n==2)
	return (a[0][0]*a[1][1]-a[1][0]*a[0][1]);

	int sign=1;
	double total_sum=0;
	int j=0;
	while(j<n)
	{
		vector<vector<double>>sub_matrix=getcofactor(a,0,j);
		double det=determinant(sub_matrix);
		total_sum+=(a[0][j]*det*sign);
		sign=-1*sign;
		j++;
	}
	return total_sum;
}
	vector<vector<double>> adjoint_matrix(vector<vector<double>>& a)
{
    int n=a.size();
  	vector<vector<double>>adj(n,vector<double>(n,0));
  if(n==1){
  adj[0][0]=1;
  return;
}
int sign=1;
for(int i=0;i<n;i++)
{
  for(int j=0;j<n;j++)
  {
    vector<vector<double>>sub_matrix=getcofactor(a,i,j);
    sign=(i+j)%2==0?1:-1;
    adj[j][i]=sign*determinant(sub_matrix);
  }
}
return adj;
}
void inverse_matrix(vector<vector<double>>& a )
{
    int n=a.size();
    	vector<vector<double>>inv(n,vector<double>(n,0));
  double det=determinant(a);
  if(det==0)
  {
    cout<<"Inverse not exist"<<endl;
    return;
  }
  else
  {
    	vector<vector<double>>adj=adjoint_matrix(a);
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
            inv[i][j]=(double)adj[i][j]/det;
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<inv[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main()
{
	int n;
	cout<<"Enter the size of the square matrix"<<endl;
	cin>>n;
	vector<vector<double>>a(n,vector<double>(n,0));
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>a[i][j];
  cout<<"Inverse of Matrix is:"<<endl;
  inverse_matrix(a);
  return 0;
}
