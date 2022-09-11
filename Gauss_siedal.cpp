#include<iostream>
#include<cmath>	
#include<stdlib.h>
#include<fstream>
#define tol pow(10,6)
#define itmax 1000
using namespace std;
long double aa[101][101],bb[101];
int main(){
long double err,t,re[101],x[101];  
int i,j,k,n=100,a,b,ind;
long double L,maxx,temp;
// loading data files
ifstream ra;
ra.open("dataA.txt");
ifstream rai;
rai.open("dataB.txt");
for(i=0;i<n;i++)// guess
{
	x[i]=0;
}
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		ra>>t;
		aa[i][j]=t;
	}
	rai>>t;
	bb[i]=t;
}
	do{
		for(i=0;i<n;i++)
		{
			maxx=fabs(aa[i][i]);
			for(a=i+1;a<n;a++)
			{
				if( fabs(aa[a][i]) >maxx)
				{
					maxx=fabs(aa[a][i]);
					ind=a;
				}
			}
			if(maxx!=fabs(aa[i][i]))
			{
				for(b=0;b<n;b++)
				{
					temp=aa[i][b];
					aa[i][b]=aa[ind][b];
					aa[ind][b]=temp;	
				}
				temp=bb[i];
				bb[i]=bb[ind];
				bb[ind]=temp;
			}
			L=0;
			for(j=0;j<n;j++)
			{
				if(j!=i)
				{
					L=L+aa[i][j]*x[j];
				}
				
			}
			x[i]=(bb[i]-L)/aa[i][i];
		}
		err=0;
		for(i=0;i<n;i++)
		{
			L=0;
			for(j=0;j<n;j++)
			{
				L=L+aa[i][j]*x[j];	
			}
			re[i]=bb[i]-L;
		err=err+re[i]*re[i];
		}
		
		err=sqrt(err);
		k=k+1;
		
	}while(k<itmax && err>tol);
	for(i=0;i<n;i++)
	cout<<x[i]<<endl;
return 0;
}
