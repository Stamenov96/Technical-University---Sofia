#include<stdio.h>
#include<math.h>


int main(){
	
	int a,b,c;
	double x,x1,x2,re,im,d;
	
	printf("A=");
	scanf("%d",&a);
	printf("B=");
	scanf("%d",&b);
	printf("C=");
	scanf("%d",&c);

	if(a==0&&b==0){
		printf("izordeno");
		}else{
			if(a==0){
				x=-(double)c/(double)b;
				printf("Lineino x=%f",x);
				}else{
					if(c==0){
						x1=-(double)b/(double)a;
						x2=0;
						printf("uravnenieto ima 2 korena %f , %f",x1,x2);
						}else{
							re=-(double)b/(2*(double)a);
							d=pow(b,2)-4*(double)a*(double)c;
							im=sqrt(fabs(d))/(2*a) ;
							if(d>0){
								x1=re+im;
								x2=re-im;
								printf("ima dva %f , %f",x1,x2);
								
								}else{
									if(d<0){
										printf("kompleksni (%f,%f) , (%f,%f)",re,im,re,(-im));
										}else{
											x1=re;
											x2=x1;
											printf("dva ravni x1=x2=%f",x1);
											
											}
									}
							
							
							
							
							}			
				}
			}
	
	
	
	return 0;
	}
