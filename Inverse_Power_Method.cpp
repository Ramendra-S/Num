#include<stdio.h>
#include<math.h>
float A[5][5],B[5][5],b[5];
float X[5],Y[5],Ax[5],qi,my,lmd,R[5];
int j,i,l,ind,index;
int max(float *c){
float m=abs(c[1]);
ind=1;
for(j=1;j<5;++j){
if((abs(c[j]))>m){
m=abs(c[j]);
ind=j;
}
else{
	continue;
}
}
return ind;
}

int main(){

A[1][1]=5;
A[1][2]=4;
A[1][3]=1;
A[1][4]=1;
A[2][1]=4;
A[2][2]=5;
A[2][3]=1;
A[2][4]=1;
A[3][1]=1;
A[3][2]=1;
A[3][3]=4;
A[3][4]=2;
A[4][1]=1;
A[4][2]=1;
A[4][3]=2;
A[4][4]=4;
X[1]=1;
X[2]=1;
X[3]=1;
X[4]=1;


float qd=0,qn=0,q;
for(i=1;i<5;++i){
	qd=qd+((X[i])*(X[i]));
}
for(i=1;i<5;++i){
qi=0;
for(l=1;l<5;++l){
qi=qi+((A[i][l])*(X[l]));
}
Ax[i]=qi;
}
for(i=1;i<5;++i){
	qn=qn+((X[i])*(Ax[i]));
}
q=qn/qd;
q=0;

for(i=1;i<5;++i){
	for(j=1;j<5;++j){
		B[i][j]=A[i][j];
	}
}
for(i=1;i<5;++i){
	A[i][i]=A[i][i]-q;
}
int g=1;
while(g<100){

//*************************************************************************
//Gauss siedal method to solve equation

int k,n;
float tol,s,p,Xo[5];
for(i=1;i<=4;++i){
		Xo[i]=0;
		b[i]=X[i];
		
	}
	
	k=1;
	tol=1;
	n=4;
	while(k<100){
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
	
	}
	

	 for(i=1;i<5;++i){
	 	Y[i]=Xo[i];
	 	
	 }

//*********************************************************************

index=max(Y);
my=Y[index];
for(i=1;i<5;++i){
Y[i]=((Y[i])/my);
X[i]=Y[i];

}
g=g+1;
}

lmd=(q+(1/my));
printf("The smallest eigen value is %f ",lmd);

return 0;
}




