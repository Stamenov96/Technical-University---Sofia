#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFER_SIZE 256


int IsValidIdentifier(char *);
int engine(FILE*,int*);
void check_save(char*,int* ,short* ,short ,char abv[][255] );

void RF(int);
void RC(int);

int main(){
	while(1){
	int choice;
	
	 system("clear");

	printf("MENU:\n");
	printf("1.Chetene ot fail i zapis vuv fail(Molq vuvedete imenata na dvata faila)\n");
	printf("2.Chetene ot fail  i izvejdane na rezultata na ekrana\n");
	printf("3.Chetene ot kalviaturata  i izvejdane vuv fail\n");
	printf("4.Chetene ot klaviaturata i izvejdane na ekrana\n");
	printf("5 Exit\n");
	
	do{
	
	scanf("%d",&choice);
		if (choice == 5) return 0;
	}while(choice<1 || choice>6);
	
	switch(choice){
	
	case 1 : RF(1);
		break;
	
	case 2 :  RF(2);
		break;
	
	case 3 : RC(3);
		break;
	
	case 4 :  RC(4);
	}
	
	}
	return 0;
}


void RF(int a){
	 system("clear");
	int lines=0;
		
	int identific=0 ;
	char inputfile[100];
	//char ch;
	FILE *fp;
	
	printf("please type an input file\n");
	scanf("%s",inputfile);
	
	while(!(inputfile[strlen(inputfile)-1]=='c' && inputfile[strlen(inputfile)-2]=='.')){
		printf("please enter a valid file in .c format\n");
		scanf("%s",inputfile);
	}
 
   fp = fopen(inputfile,"r");
   
   
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
	
	identific=engine(fp,&lines);
	fclose(fp);
  
  
  if(a==1){
	 char outputfile[100]; 
	 printf("Vuvedete imeto na faila za rezultati\n");
	 scanf("%s",outputfile);
 
	FILE *fp;
	fp=fopen(outputfile, "w");
	fprintf(fp, "Number of identificators is : %d \n",identific);
	fprintf(fp, "Number of lines is : %d \n",lines);
	fclose(fp);
	
	 
	 }else if(a==2){
			printf("Number of identificators is : %d \n",identific);
			printf("Number of lines is : %d \n",lines);
			
			getchar();
	}
  
   
   
	
}



void RC(int b){
	int lines=0;
	
 	system("clear");
	
	int identific=0;

	 
	identific=engine(stdin,&lines);
         
    
   if(b==3){
	 char outputfile[100]; 
	 printf("Vuvedete imeto na faila za rezultati\n");
	 scanf("%s",outputfile);
 
	FILE *fp;
	fp=fopen(outputfile, "w");
	fprintf(fp, "Number of identific is : %d \n",identific);
	fprintf(fp, "Number of lines is : %d \n",lines);
	fclose(fp);
	
		}
	else if(b==4){
		printf("Number of identific is : %d \n",identific);
		printf("Number of lines is : %d \n",lines);
		getchar();
		}	
	}

int engine(FILE* fp,int* lines){
	
	char abv[255][255];
	short exist,singlelineflag=0,singlewithmulti=0,multilineflag=0,stringflag=0;
	char buffer[BUFFER_SIZE];
	int isID=0,i=0,br=0;
	char* pch,point;
	char* container[20];
	const char* singleline = "//";
	const char* multiline="/*";
	const char* endofmultiline="*/";
	
	
	
 while (fgets(buffer, BUFFER_SIZE, fp)) {
      (*lines)++;
   
if(multilineflag==0){     	
	if(singlewithmulti!=1){  
		if(strstr(buffer,singleline)!= NULL){
			if(buffer[strlen(buffer)-2]== '\\'){
				singlewithmulti=1;
			}
			if(buffer[0]=='/' && buffer[1]=='/'){
				memset(buffer,0,strlen(buffer));
			}
			pch=strtok(buffer,singleline);
			singlelineflag=1;
		}
		
		if(strstr(buffer,multiline)!=NULL){
			pch=strtok(buffer,multiline);
				if(buffer[0]=='/' && buffer[1]=='*'){
					memset(buffer,0,strlen(buffer));
				}
				multilineflag=1;
		}
    
	pch = strtok (buffer," ,;\n");	
	check_save(pch,&br,&stringflag,exist,abv);

	
	}else{
		if(buffer[strlen(buffer)-1]!='\\' && singlewithmulti==1){
			singlewithmulti=0;
		}
    }
	}else{
		if(strstr(buffer,endofmultiline)!=NULL){
			pch=strtok(buffer,endofmultiline);
			if(!(buffer[0]=='*' && buffer[1]=='/')){
			pch=strtok(NULL,endofmultiline);
			}
			pch = strtok (pch," ,;\n");
			multilineflag=0;
			check_save(pch,&br,&stringflag,exist,abv);
			
			}
		
		}
    }
    
 //   printf("broq na identifikatorite e %d",br);
return br;
}

int IsValidIdentifier(char *word)
{
    int i = 0,
        isIdentifier = 0;

        if ((word[0] == '_') || (isalpha(word[0]) != 0))
        {
            if (strlen(word) == 1)
            {
				return isIdentifier = 1;
            }
            for (i = 1; word[i] != '\0'; i++)
            {
 
                if ((isalnum(word[i]) != 0) && (word[i] != '_'))
                    isIdentifier = 1;
                 else
                {
                    isIdentifier = 0;
                    break;
                }
            }
        }
        else
        {
            isIdentifier = 0;
        }
 
    return isIdentifier;
}



void check_save(char*pch,int* br,short* stringflag,short exist,char abv[][255]){
	

	
	int isID=0,i;
	while (pch != NULL)
		{	
			
			
			
			
			if(pch[0]=='\"'){
			(*stringflag==1)? (*stringflag=0):(*stringflag=1);
			}
			
			
			isID=IsValidIdentifier(pch);
					
			
			exist=0;
			if(isID==1){
				
			
			for(i=0;i<*br;i++){
			
					if (strcmp(abv[i],pch)==0){
						exist=1;
					}
			}
			}	
			
		if(exist==0 && *stringflag==0){
					strcpy(abv[i],pch);
					i++;
					(*br)++;
					
				}
			
			if(pch[strlen(pch)-1]=='\"' && strlen(pch)!=1 && pch[strlen(pch)-2]!='\\'){
					(*stringflag==1)? (*stringflag=0):(*stringflag=1);
			}
			pch = strtok (NULL, " ,;\n");
		
	}
	
	
	
	}
