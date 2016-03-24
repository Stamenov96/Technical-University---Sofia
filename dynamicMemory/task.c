#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char** array;
	char* mall;
	int i=0,g=0,eof=0;
	FILE *fp;
	
	array=(char**)malloc(sizeof(char*));
	
	
	while(eof==0){
		mall = (char*)malloc(sizeof(char)*81);
		memset(mall,0,81);
		scanf("%80s",mall);
		
		
		for(g=0;g<81;g++){
			if(mall[g]==0){
				if(g==0){
					eof=1;
				}
				break;
			}
		
		}
		
		mall=(char*)realloc(mall,sizeof(char)*(g+1));
		i++;
		array=(char**)realloc(array,sizeof(char*)*i);
		array[i-1]=mall;
		
	}
	
		
		
	if((fp=fopen("result.bin","wb"))==NULL)
		{
		printf("cannot open\n");}
	else{
	
		for(g=0;g<i;g++){
			fprintf(fp,"%d.  %s  \n",g+1,array[g]);
			free(array[g]);
		}
		fclose(fp);
	}
	free(array);
	
	



	return 0;
}
