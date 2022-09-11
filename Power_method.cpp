#include<stdio.h>
#include<math.h>
int A[5][5],b[5],i;
float X[5],Y[5];
float max(float *c){
float m=c[1];
int j;
for(j=1;j<5;++j){
if((c[j])>m){
m=c[j];
}
else{
	continue;
}
}
return m;
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
X[2]=5;
X[3]=1;
X[4]=7;

int k=1,mu,l;
float mx,p;
while(k<20){
mx=max(X);

for(i=1;i<5;++i){
X[i]=((X[i])/mx);

}
for(i=1;i<5;++i){
p=0;
for(l=1;l<5;++l){
p=p+((A[i][l])*(X[l]));
}

Y[i]=p;
}
for(i=1;i<5;++i){
	X[i]=Y[i];
}
k=k+1;
}
printf("the maximum eigen value is %f",mx); 
return 0;
}





































