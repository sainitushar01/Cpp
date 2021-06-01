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
int main()
{
	int n;
	cout<<"Enter the size of the square matrix"<<endl;
	cin>>n;
	vector<vector<double>>a(n,vector<double>(n,0));
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>a[i][j];
	cout<<"Determinant of the matrix is: "<<determinant(a)<<endl;
}
