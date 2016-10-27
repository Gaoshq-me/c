#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DENSITY 62.4 //Defined by the section nosy informative Sophia
int main(int argc, char *argv[])
{
    FILE *fp;
	//Arguments checkments
	if(argc<2)
    {
        fprintf(stderr, "Usage: %s lacks arguments.\n", argv[0]);
		fprintf(stdout,"Just append \"talkback\" and talk with me~");
        exit(EXIT_FAILURE);
    }
    //This section is used to record code 
	if(strcmp(argv[1],"code")==0)
    {
        if((fp=fopen("code.sf", "a+"))==0)
		{
			fprintf(stdout,"%s open %s failure.\n", argv[0],argv[1]);
			exit(EXIT_FAILURE);
		}
		fputs(strcat(strcat(strcat(argv[2],"\t"),strcat(argv[3],"\t")),strcat(argv[4],"\n")),fp);
		fprintf(stdout,"A successful try.\n");
    }
	//This section you got a nosy informative Sophia
	if(strcmp(argv[1],"talkback")==0)
	{
		float weight,volume;
		int size,letters;
		char name[20];
		
		printf("Hi~ This is Sophia, then your name is __________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s",name);
		printf("%s, just talk to me bravely your weight is ___  pounds\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%f",&weight);
		size=sizeof(name);
		letters=strlen(name);
		volume=weight/DENSITY;
		printf("Ok, %s, your volume is %2.2f cubic feet.\n",name,volume);
		printf("Also, your first name has %d letters,",letters);
		printf("\nand we have %d bytes to store it.",size);
	}
	//This section is used to record some temporary files
	if(strcmp(argv[1],"record")==0)
	{
		int count;
		FILE *fp;
		char filename[20];
		if((fp=fopen(strcat(argv[2],".txt"),"a"))==0)
		{
			fprintf(stderr,"Sophia cannot create the new file.");
			exit(EXIT_FAILURE);
		}
		for(count=3;count<argc;count++)
		{
			fputs(argv[count],fp);
			fputs("\t",fp);
		}
		fputs("\n",fp);
		fclose(fp);
	}
	//This seciton is used to ...
    exit(EXIT_SUCCESS);
}
