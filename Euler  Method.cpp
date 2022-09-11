#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//*fp=fopen("f1.txt","w");
float yval1[10],yval2[20],yval3[50],el1[10],el2[20],el3[50],rkfvl1[10],rkfvl2[20],rkfvl3[50],rkfe1[10],rkfe2[20],rkfe3[50];
float f(float x){
float y;
y=((-2*(pow(x,3)))+(12*(pow(x,2)))-(20*x)+8.5);
//printf("\n y=%f",y);
return y;
}
float g(float x){
float y;
y=((-0.5*pow(x,4))+(4*pow(x,3))-(10*pow(x,2))+(8.5*x)+1);
return y;
}
void Euler(float x,float y,float h,float yval[],float eL[])
{
	float a,b,x1,L;
	int  i,N;
	L=4;
	a=L-x;
	x1=x;
	N=a/h;
	yval[0]=y;
	for(i=1;i<=N;++i){
		yval[i]=y+(h*f(x));
		x=x+h;
		y=yval[i];
	//	printf("%f",yval[i]);
	}
	for(i=0;i<=N;++i){
		//c=yval[i];
		b=yval[i]-g(x1);
		eL[i]=b;
		x1=x1+h;
	}

    //x=0.0;
	//y=1.0;
	//L=0.0;
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
		b=rfyval[i]-g(x1);
		rfeL[i]=b;
	//	printf("\n%f\t\t%f\t\t%f",rfyval[i],rfeL[i],g(x1));
		x1=x1+h;
	}
	
//	x=1.0;
//	y=6.0;
//	L=6.0;
}

int main()
{   
     FILE *f1 = fopen("f1.txt","w");
     FILE *f2 = fopen("f2.txt","w");
     FILE *f3 = fopen("f3.txt","w");
     FILE *f4 = fopen("f4.txt","w");
     FILE *f5 = fopen("f5.txt","w");
     FILE *f6 = fopen("f6.txt","w");
    
     
    int i;
    Euler(0,1,0.5,yval1,el1);
    printf("VALUE                    ERROR");
    for(i=0;i<=8;++i){
    fprintf(f1,"\n%f                 %f",yval1[i],el1[i]);
    printf("\n%f                 %f",yval1[i],el1[i]);
    
    }
  //   fprintf(fp,"\n\n*********************************\n\n");
    Euler(0,1,0.25,yval2,el2);
    printf("\n\n\n");
    printf("\n\n\n");
    for(i=0;i<=16;++i){
    fprintf(f2,"\n%f                 %f",yval2[i],el2[i]);
    printf("\n%f                 %f",yval2[i],el2[i]);
    }
    //fprintf(fp,"\n\n*********************************\n\n");
    Euler(0,1,0.1,yval3,el3);
    printf("\n\n\n");
    for(i=0;i<=40;++i){
    fprintf(f3,"\n%f                 %f",yval3[i],el3[i]);
    printf("\n%f                 %f",yval3[i],el3[i]);
    }
    //fprintf(fp,"\n\n*********************************\n\n");
    Rk4(0,1,0.5,rkfvl1,rkfe1);
    printf("\n\n\n");
    for(i=0;i<=8;++i){
    fprintf(f4,"\n%f                 %f",rkfvl1[i],rkfe1[i]);
    printf("\n%f                 %f",rkfvl1[i],rkfe1[i]);
    }
   // fprintf(fp,"\n\n*********************************\n\n");
    Rk4(0,1,0.25,rkfvl2,rkfe2);
    printf("\n\n\n");
    for(i=0;i<=16;++i){
    fprintf(f5,"\n%f                 %f",rkfvl2[i],rkfe2[i]);
    printf("\n%f                 %f",rkfvl2[i],rkfe2[i]);
    }
   // fprintf(fp,"\n\n*********************************\n\n");
    Rk4(0,1,0.1,rkfvl3,rkfe3);
    printf("\n\n\n");
    for(i=0;i<=40;++i){
    fprintf(f6,"\n%f                 %f",rkfvl3[i],rkfe3[i]);
    printf("\n%f                 %f",rkfvl3[i],rkfe3[i]);
    }
    
    return 0;
}

