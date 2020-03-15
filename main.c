#include <stdio.h>
#include <stdlib.h>

int swap(int *a , int *b){
    //int status=0;
    int c;
    c=*a;
    *a=*b;
    *b=c;
    return 0;
}
int parselog(char input1[], char *opt[]){
    int i=0;
    //int y;
    //"25:01:07,400-234-090\n00:05:01,400-234-090\n00:05:00,400-234-090";
    int count=0,index=0;
    while (input1[i]!='\0'){

        if (input1[i]=='\n'){
            count++;
            index=0;
            i++;
            printf("End count %d -- i %d \n",index, i);
        }
        if (count==0){
            printf("First Char: %c \n",input1[i]);
            *(*(opt+0)+index)=input1[i];
            printf("%c 1 - index %d  %d-----%c \n",input1[i],index,i,*(*(opt+0)+index));
        }
        if (count==1){
            printf("2nd Char: %c \n",input1[i]);
            *(*(opt+1)+index)=input1[i]; // == ans =
            printf("%c 2 - index %d  %d-----%c \n",input1[i],index,i,*(*(opt+1)+index));
        }
        if (count==2){
            printf("3rd Char: %c \n",input1[i]);
            *(*(opt+2)+index)=input1[i];
            printf("%c 3  - index %d  %d----%c \n",input1[i],index,i,*(*(opt+2)+index));
        }

        index++;
        i++;
    }
    //printf("End count %d \n",index);
    *(*(opt+0)+index)='\0';
    *(*(opt+1)+index)='\0';
    *(*(opt+2)+index)='\0';

 return 0;
}
int parseCalldurationAndNumber(char data[], char time[], char number[]){
    int i=0;
    int j=0;
    int status = 0;
    printf("Input: %s \n",data);
    if(data == 0 || time == 0 || number == 0){
            status = -1;
            printf("Parse Call Duration status: %d: ",status);
        return status;
    }

    while(data[i]!=','){
        printf(" - %c ",data[i]);
        time[i]=data[i];
        i++;
    }
    printf("i=%d \n",i);
    time[i] = '\0';
    printf("Input time: %s \n",time);
    i++;
    while(data[i]!='\0'){
        number[j]=data[i];
        i++;
        j++;
    }
    number[j] = '\0';

    return status;
}
int linenocount(char input1[]){
    int i=0,counter=0;
    while (input1[i]!='\0'){
      if (input1[i]=='\n'){
        counter++;
      }
      i++;
    }
    return counter+1;
}




int main()
{
    //printf("Hello world!\n");
    char input[]="25:01:07,400-234-090\n00:05:01,400-234-090\n00:05:00,400-234-090";
    int count=linenocount(input);
    char *oplog[count];
    printf("Max Size: %d \n",count);

    for(int i = 0; i < count; i++)
        oplog[i] =  (char *)malloc(20*sizeof(char));
    parselog(input,oplog);
    for (int i=0; i<count;i++)
        printf("%d  log:%s\n",i+1,*(oplog+i));
    return 0;
}
