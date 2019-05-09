//#include"header.h"
#include<stdio.h>
FILE *fp,*fp2,*fp3;
int count=0;
char fname[100];
void compareword(char*);
void removeword(char *);
void openfile(){
      fp=fopen("anu.txt","r+");
         if(fp==NULL){
           printf("file open error\n");
             return;
          }
      fp3=fopen("test.txt","w+");
        if(fp3==NULL){
        printf("file open error\n");
        return;
       }
  }

  void openfile2(){
        fp2=fopen("anu.txt","r");
            if(fp2==NULL){
                printf("file open error\n");
                return;
             }
      
  } 

  int main()
  {
    char cbuf[100];
    openfile();
      while(1){
        if(feof(fp))
        break;
        fscanf(fp,"%s",cbuf);
        compareword(cbuf);
        bzero(cbuf,100);
      }
     fclose(fp);
     fclose(fp3);
  } 

  void compareword(char *ptr)
  {
      int i=0,count=0;
      char buf[100],chr;
      int len1=strlen(ptr);
      printf("ptr=%s\n",ptr);
      openfile2();
        while(1){
           if(feof(fp2))
              break;
       bzero(buf,100);
       fscanf(fp2,"%s",buf);
       printf("buf=%s\n",buf);
       int len2=strlen(buf);
           if(len1==len2){
               for(i=0;i<len1;i++){
                     if((ptr[i]-buf[i]==0)||(ptr[i]-buf[i]==32)||(buf[i]-ptr[i]==32)){
                          if((i+1)==len1){
                                        count++;
                                if(count==1)
                                removeword(ptr);
                           printf("words are equal\n");
                     }
                     continue;
                  }
                    /* else{
                       removeword(ptr);
                       break;
                     }*/
             }
    }
    removeword(ptr);
  }
  fclose(fp2);
}

void removeword(char *rptr){
  char b[]=" ";
  fprintf(fp3,"%s",rptr);
  fprintf(fp3,"%s",b);
}


