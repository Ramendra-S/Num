#include <stdio.h>
#include <stdlib.h>
#include<math.h>
float yval[20],err[20],Yn[50],Y1[20],Y2[20];
int i;
float f(float x){
float y;
y=2-2*x+4*(pow(x,2))-4*(pow(x,3))-4*(pow(x,4));
//printf("\n y=%f",y);
return y;
}
/*float g(float x){
float y;
 y=2*x-(pow(x,2)+(4/3)*(pow(x,3))-1*(pow(x,4))-(4/5)*(pow(x,5))+1;
return y;
}*/
void Adam(float x,float y,float h,float Y[] ){
float x0,x1,x2,x3;
int N;
N=(y-x)/h;
x0=x-3*h;
x1=x-2*h;
x2=x-1*h;
x3=x;
Y[0]=1;
for(i=1;i<=N;++i){
 Y[i]=Y[i-1]+(h/24)*(55 * (f(x3))-(59 * (f(x2)))+(37 * (f(x1)))-(9*(f(x0))));

x1=x1+h;
x0=x0+h;
x2=x2+h;
x3=x3+h;
}
}

void Rk4(float x,float y,float h,float rfyval[],float rfeL[])
{
	float a,b,c,d,esum,k1,k2,k3,k4,kf,k,x1;
	int  i,N;
	float L=4;
	a=L-x;
	N=a/h;
	x1=x;
	esum=0;
	rfyval[0]=y;
	for(i=1;i<=N;++i){
		k1=h*f(x);
		x=x+0.5*h;
		y=y+0.5*k1;
		k2=h*f(x);
		y=y-0.5*k1+0.5*k2;
		k3=h*f(x);
		x=x+0.5*h;
		y=y-0.5*k2+k3;
		k4=h*f(x);
		k=k1+2*k2+2*k3+k4;
		kf=k/6;
		y=y-k3;
		rfyval[i]=y+kf;
			y=rfyval[i];
	}
	for(i=0;i<=N;++i){
		c=rfyval[i];
		b=rfyval[i];//-g(x1);
		rfeL[i]=b;
	//	printf("\n%f\t\t%f\t\t%f",rfyval[i],rfeL[i],g(x1));
		x1=x1+h;
	}
}
int main()
{
	FILE *f1=fopen("file1.txt","w");
	FILE *f2=fopen("file2.txt","w");
	FILE *f3=fopen("file3.txt","w");
Adam(0,1,0.01,Y1);
printf("For h = 0.01\n");
for(i=0;i<=100;++i){
printf("\n%f",Y1[i]);
fprintf(f1,"\n%f",Y1[i]);
}
printf("\n\n\n");
printf("For h = 0.02\n");
Adam(0,1,0.02,Y2);	
for(i=0;i<=50;++i){
printf("\n%f",Y2[i]);
fprintf(f2,"\n%f",Y2[i]);
}
printf("\n\n\n");
printf("For h = 0.1\n");
Rk4(0,1,0.1,yval,err);
Adam(0,1,0.1,Yn);
for(i=0;i<=10;++i){
printf("\n%f",Yn[i]);
fprintf(f3,"\n%f",Yn[i]);
}
   // printf("Hello world!\n");
    return 0;
}
