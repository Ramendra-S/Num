#include<stdio.h>
#include<conio.h>
#include<math.h>
float Y[20],DY[20];

float g(float x,float y,float z){
	float a,b,c,d;
a=pow(x,3);
b=10+4*z;
c=2*y-b+2*a;

return (c);	
}

float f(float x,float y,float z){
	float a,b,c,d;
a=z;
return (a);	
}
void Rk4(float x,float y,float z,float h,float l,float yval[],float zval[])  //,float ely[],float elz[]
{
	float a,b,c,d,e,esumy,esumz,k1,k2,k3,k4,kf,k,L,L1,L2,L3,L4,Lf,x1;
	int  i,N;
	a=l-x;
	x1=x;
	esumy=0;
	esumz=0;
	N=a/h;
	yval[0]=y;
	zval[0]=z;
	for(i=1;i<=N;++i){
		k1=h*f(x,y,z);
		L1=h*g(x,y,z);
		x=x+0.5*h;
		y=y+0.5*k1;
		z=z+0.5*L1;
		k2=h*f(x,y,z);
		L2=h*g(x,y,z);
		y=y-0.5*k1+0.5*k2;
		z=z-0.5*L1+0.5*L2;
		k3=h*f(x,y,z);
		L3=h*g(x,y,z);
		x=x+0.5*h;
		y=y-0.5*k2+k3;
		z=z-0.5*L2+L3;
		k4=h*f(x,y,z);
		L4=h*g(x,y,z);
		k=k1+2*k2+2*k3+k4;
		L=L1+2*L2+2*L3+L4;
		kf=k/6;
		Lf=L/6;
		y=y-k3;
		z=z-L3;
		yval[i]=y+kf;
		zval[i]=z+Lf;
			y=yval[i];
			z=zval[i];		
	}
/*	for(i=0;i<=N;++i){
		c=zval[i]-v(x1);
		b=yval[i]-u(x1);
		esumy=esumy+pow(b,2);
		esumz=esumz+pow(c,2);
		x1=x1+h;
	}
	d=sqrt(esumy);
	e=sqrt(esumz);
	ely[N]=d/N;
	elz[N]=e/N;
*/
}

int main(){
	Rk4(0,0,1,0.1,1,Y,DY);
	int i;
	printf("value of y             value of derivative of y");
	for(i=0;i<=10;++i){
		printf("\n%f            %f",Y[i],DY[i]);
	}
	return 0;
}

