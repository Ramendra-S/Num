#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float Y1[25],Z1[25],Xi[25],V[25],Error[25];

float fn(float x){
	float y;
	y=pow(x,2)+(16/x);
	return y;
}
float g(float x,float y,float z){
	float a,b,c,d;
a=pow(x,3);
b=32-y*z+2*a;
c=b/8;

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
}
	///////

	float g1(float xi , float yi,float y,float z){   ///g(xi,DY[i],Y[i],v)
	float a,b,c,d;
a=(yi/8)*xi;
b=(y/8)*z;
c=-a-b;

return (c);
}

float f1(float z){
	float a,b,c,d;
a=z;
return (a);
}
void RKK4(float x,float xi,float v,float DY[],float Y[],float h,float l,float xival[],float vval[])  //,float ely[],float elz[]
{
	float a,b,c,d,e,esumy,esumz,k1,k2,k3,k4,kf,k,L,L1,L2,L3,L4,Lf,x1;
	int  i,N;
	a=l-x;
	x1=x;
	esumy=0;
	esumz=0;
	N=a/h;
	xival[0]=xi;
	vval[0]=v;
	for(i=1;i<=N;++i){
		k1=h*f1(v);
		L1=h*g1(xi,DY[i],Y[i],v);
		x=x+0.5*h;
		xi=xi+0.5*k1;
		v=v+0.5*L1;
		k2=h*f1(v);
		L2=h*g1(xi,DY[i],Y[i],v);
		xi=xi-0.5*k1+0.5*k2;
		v=v-0.5*L1+0.5*L2;
		k3=h*f1(v);
		L3=h*g1(xi,DY[i],Y[i],v);
		x=x+0.5*h;
		xi=xi-0.5*k2+k3;
		v=v-0.5*L2+L3;
		k4=h*f1(v);
		L4=h*g1(xi,DY[i],Y[i],v);
		k=k1+2*k2+2*k3+k4;
		L=L1+2*L2+2*L3+L4;
		kf=k/6;
		Lf=L/6;
		xi=xi-k3;
		v=v-L3;
		xival[i]=xi+kf;
		vval[i]=v+Lf;
			xi=xival[i];
			v=vval[i];
	}

	///////////
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

int main()
{float m=0;
float tol,k=1;
int c=-5;
tol=0.00001;
int i ,n=1;
while(k>tol&&n<100){
	
  Rk4(1,17,m,0.1,3,Y1,Z1);
  k=(Y1[20]-(43/3));
  RKK4(1,0,1,Z1,Y1,0.1,3,Xi,V);
  m=m-(k/Xi[20]);
  k=abs(k);
 // printf("Hello world!\n%f",k);
  n=n+1;
}

float x=1;
  //printf("\n\n****************\n");
  for(i=0;i<=20;++i){
  	float y=fn(x);
  	Error[i]=-Y1[i]+y;
  //	printf("\n%f",y);
  	x=x+0.1;
  }
printf("\n\nIterative value			Error");
  for(i=0;i<=20;++i){
   printf("\n%f\t\t\t%f",Y1[i],Error[i]);
  }
  
//   printf("Hello world!\n");
    return 0;
}
