#include<stdio.h>
#include<math.h>
float A[6][6],b[6],r[6],a,B,X[6],d[6],Ad[6],s,y,Xo[6],R[6],Gerror[100],Cerror[20];
int i,j,n;
int main(){
	A[1][1]=0.2;
	A[1][2]=0.1;
	A[1][3]=1;
	A[1][4]=1;
	A[1][5]=0;
	A[2][2]=4;
	A[2][3]=-1;
	A[2][4]=1;
	A[2][5]=-1;
	A[3][3]=60;
	A[3][4]=0;
	A[3][5]=-2;
	A[4][4]=8;
	A[4][5]=4;
	A[5][5]=700;
	for(i=2;i<=5;++i){
		for(j=1;j<i;++j){
			A[i][j]=A[j][i];
		}
	}
	b[1]=1;
	b[2]=2;
	b[3]=3;
	b[4]=4;
	b[5]=5;
	for(i=1;i<=5;++i){
		X[i]=0;
	}
	
	for(i=1;i<=5;++i){
		s=0;
		for(j=1;j<=5;++j){
			s=s+((A[i][j])*(X[j]));
		}
		r[i]=((b[i])-s);
		d[i]=((b[i])-s);
	}
	int k=1;
	float c,l,m,p,q,tol,t;
	tol=1;
	c=pow(10,(-6));
	while(k<20&&tol>c){
		l=0;
    	m=0;
     	p=0;
    	q=0;
    	t=0;
		for(i=1;i<=5;++i){
			l=l+(pow((r[i]),2));
			t=0;
			for(j=1;j<=5;++j){
				t=t+((A[i][j])*d[j]);
				Ad[i]=t;
			}
			m=m+((d[i])*(Ad[i]));
		}
		a=(l/m);
		for(i=1;i<=5;++i){
			X[i]=X[i]+(a*(d[i]));
		}

		for(i=1;i<=5;++i){
			p=p+((d[i])*(r[i]));
		}
		for(i=1;i<=5;++i){
			r[i]=(r[i])-(a*(Ad[i]));
			q=q+(pow((r[i]),2));
		}
		B=(q/p);
		for(i=1;i<=5;++i){
			d[i]=((r[i])+(B*(d[i])));	
		}
		k=k+1;
		tol=pow(q,0.5);
		Cerror[k]=tol;
	}
	for(i=1;i<=5;++i){
		printf("x%d=%f\n",i,X[i]);
			
	}
	printf("Number of iteration by conjugate method is  %d\n\n\n",k);
	
	//
	//
	// code for gauss siedal method
	for(i=1;i<=5;++i){
		Xo[i]=0;
	}
	c=pow(10,-6);
	k=1;
	tol=1;
	n=5;
	while(k<99&&tol>c){
		for(i=1;i<=n;i++){
			s=0;
			for (j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				else{
					s=s+((A[i][j])*(Xo[j]));
				}
			}
			Xo[i]=(b[i]-s)/A[i][i];
		}
		tol=0;
		for(i=1;i<=n;i++){
			p=0;
			for(j=1;j<=n;j++){
				p=p+((A[i][j])*(Xo[j]));
			}
			R[i]=b[i]-s;
			tol=tol+pow((R[i]),2);
		}
		tol=pow(tol,0.5);
		k=k+1;
		Gerror[k]=tol;
	}
	for(i=1;i<=n;i++){
		printf("\nX%d=%f",i,Xo[i]);
	}
	 printf("\nNumber of iteration by Gauss siedal method is  %d",k);
	 
	return 0;
}
