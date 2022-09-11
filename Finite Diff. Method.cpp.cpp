#include <iostream>
#include <math.h>
#include<fstream>

using namespace std;

int main()
{
    int i,j,k,n=1000;
    double t0,t,h,alpha,beta,a,b,c,d,m,sum;
    double ai[n],bi[n],ci[n],di[n],A[n][n],B[n],L[n][n],U[n][n],y[n],x[n],p[3];
    t0 = 0;
    alpha = 0;
    beta = 1;
    p[0] = 10;
    p[1] = 100;
    p[2] = 1000;
    for(i=0;i<3;i++)
    {
    	n = p[i];
	    h = (beta - alpha)/n;
	
	    for(i=0;i<=n-1;i++)
	    {
	        t = t0 + ((i+1)*h);
	        ai[i] = 1 + ((h/2)*cos(t));
	        bi[i] = -h*h*exp(t);
	        ci[i] = 1 - ((h/2)*cos(t));
	        di[i] = -2 - (h*h*sin(t));
	    }
	    for(i=0;i<n-1;i++)
	    {
	        for(j=0;j<n-1;j++)
	        {
	            if(i==j)
	            {
	                A[i][j] = di[i];
	            }
	            else if(i==j+1)
	            {
	                A[i][j] = ai[i+1];
	            }
	            else if(j==i+1)
	            {
	                A[i][j] = ci[i];
	            }
	            else
	            {
	            	A[i][j] = 0;
				}
	        }
	    }
	
	    for(i=0;i<n-1;i++)
	    {
	        if(i==0)
	        {
	            B[i] = bi[i] - (ai[i]*alpha);
	        }
	        else if(i==n-2)
	        {
	            B[i] = bi[i] - (ci[i]*beta);
	        }
	        else
	        {
	            B[i] = bi[i];
	        }
	    }
	  
	    for(i=0;i<n-2;i++)					//LU factorization
		{
	        m = A[i+1][i]/A[i][i];
	        A[i+1][i] = m;
	        A[i+1][i+1] = A[i+1][i+1]-(m*A[i][i+1]);
	        
	    }
	    for(i=0;i<n-1;i++)
		{
	        for(int j=0;j<n-1;j++)
			{
	            if(i>j)
				{
	                L[i][j]=A[i][j];
	            }
	            else if(i==j)
				{
					L[i][j]=1;
	                U[i][j]=A[i][j];
	            }
	            else
				{
	                U[i][j]=A[i][j];
	            }
	        }
	    }
		
		for(i=0;i<n-1;i++)
	    { 
	    	if(i==0)
	    	{
	    		y[i] = B[i];
			}
			else
			{
				sum = 0;
				for(j=0;j<i;j++)
				{
					sum = sum + (L[i][j]*y[j]);
				}
				y[i] = B[i] - sum;
			}
	    }
		
		for(i=n-2;i>=0;i--)
	    {
	    	if(i==n)
	    	{
	    		x[i] = y[i]/U[i][i];
			}
			else
			{
				sum = 0;
				for(j=n-2;j>i;j--)
				{
					sum = sum + (U[i][j]*x[j]);
				}
				x[i] = (y[i] - sum)/U[i][i];
			}
		}
		fstream foutput;
		foutput.open("output.txt",ios::out);
		for(i=0;i<n-1;i++)
		{
			cout<<x[i]<<"\n";
			foutput<<x[i]<<"\n";
		}
		cout<<"\t\t";
		foutput<<"\t\t";
	}
	
}

