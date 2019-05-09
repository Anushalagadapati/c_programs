#include<stdio.h>
#include<string.h>
#include<unistd.h>
char s[100],s1[100];
void read1(void);
//int stricmp1(const char *s,const char *s1);
int stricmp(const char *s1,const char *s2);
FILE *fp1=NULL,*fp2=NULL;
int main(int argc, char *argv[])
{
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"r+");
	read1();
	fclose(fp1);
	fclose(fp2);

}

void read1(void)
{
	fscanf(fp1,"%s",s);
	fprintf(fp2,"%s",s);
	fprintf(fp2,"%s"," ");
	while (!feof(fp1))
	{
		fscanf(fp1,"%s",s);
		fseek(fp2,0,SEEK_SET);
		do
		{
			fscanf(fp2,"%s",s1);
			if(stricmp(s,s1)==0)
				break;
			memset(s1,'\0',sizeof(s1));
		}while(!feof(fp2));
		if(stricmp(s,s1)!=0)
		{
			fprintf(fp2,"%s",s);
			fprintf(fp2,"%s"," ");
			memset(s,'\0',sizeof(s));
		}
	}
}

int stricmp(const char *s1,const char *s2)
{
int i;
for(i=0;s1[i]!='\0'&&s2[i]!='\0';i++)
{
if(s1[i]!=s2[i]&&s1[i]!=s2[i]+32&&s1[i]!=s2[i]-32)
break;
}
if(s1[i]=='\0'&&s2[i]=='\0')
return 0;
return s1[i]-s2[i];
}
