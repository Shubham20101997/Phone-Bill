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


//00:01:07,400-234-093\n00:05:00,400-234-091\n00:05:00,400-234-090
int parselog_1(char input1[],char *opt[]){
    int j=0,i=0;
    int index=0;
    int nooflines=linenocount(input1);
    /*
     for ( i=0;input1[i]!='\0';i++){

            if(input1[i]=='\n'){
                *(*(opt+j)+index)='\0';
                printf("before -: %s -- i:%d - j:%d \n",*(opt+j),i,j);
                index = 0;
                i++;
                j++;
                printf("after -: %s -- i:%d - j:%d \n",*(opt+j),i,j);
            }else if(input1[i]=='\0'){
                *(*(opt+j)+index)='\0';
                printf("before -: %s -- i:%d - j:%d \n",*(opt+j),i,j);
            }else{
                *(*(opt+j)+index)=input1[i];
            }
            index++;
     }
    */


    for ( i=0;i<nooflines;i++){

        for (j=0;input1[j]!='\n';j++){
            *(*(opt+i)+j)=input1[index];
            index++;
           // printf("%c %d - index %d  %d-----%c\n",input1[i],i,index,j,*(*(opt+i)+j));
        }
        //printf("After each line index value: %d \n",index);
        if (input1[index]=='\n'|| input1[index]=='\0'){
            index++;
            *(*(opt+i)+j)='\0';
            //printf("%d -- j: %d -- \n%s \n",index,j, *(opt+i));
        }
    }


    return 0;

}
int parseCalldurationAndNumber(char input[],char *data[], char *time[], char *number[]){
    int i=0,index=0;
    int j=0,index_1=0;
   // int k;
    //25:01:07,400-234-090\n00:05:01,400-234-090\n00:05:00,400-234-090;
    int numberoflines=linenocount(input);  //TIME ENTRY//
    while (i<numberoflines){
        while (*(*(data+i)+index)!=','){
            *(*(time+i)+index)=*(*(data+i)+index);
            index++;
            //k=index;
        }
        *(*(time+i)+index)='\0';
        i++;
        if (i<numberoflines)
            index=0;
    }
    index++;
    int k=index;
    while (j<numberoflines){
       // if(j>=numberoflines)
         //   index++;

        while (*(*(data+j)+index)!='\0'){
            *(*(number+j)+index_1)=*(*(data+j)+index);
            index_1++;
            index++;

        }
        *(*(number+j)+index_1)='\0';
        index_1=0;
        j++;
        index=k;

    }
     return 0;
}
int clenPhNo(char input[],char *in_ph[], char *out_ph[]){
   // int count = 0;
    int numberoflines=linenocount(input);
    for (int i=0; i<numberoflines;i++){
        int count=0;
        for (int index=0; *(*(in_ph+i)+index) != '\0';index++){


            if(*(*(in_ph+i)+index) != '-'){
                *(*(out_ph+i)+count) = *(*(in_ph+i)+index);
                count++;
            }
        }
        *(*(out_ph+i)+count)='\0';
    }
    //out_ph[count++] = '\0';
    return 0;
}
int parsetime(char input[],char *time[], char *hour[],char *minute[], char *second[]){
    int index=0,count=0;
    int numberoflines=linenocount(input);
    for (int i=0;i<numberoflines;i++){
        for (index=0;*(*(time+i)+index)!=':';index++){   //25:01:07,400-234-090\n00:05:01,400-234-090\n00:05:00,400-234-090
            *(*(hour+i)+index)=*(*(time+i)+index);
        }
         *(*(hour+i)+index)='\0';
    }
    //count=0;
    index++;
    int j=index;
    //printf("index:%d\n",index);
    for (int i=0;i<numberoflines;i++){
       // printf("%d\n",index);
        index=j;
        count=0;
        while (*(*(time+i)+index)!=':'){
            *(*(minute+i)+count)=*(*(time+i)+index);
            count++;
            index++;
        }
         *(*(minute+i)+count)='\0';
        //count=0;
    }
    //count=0;
    index++;
    int k=index;
    //printf("index:%d\n",index);
    for (int i=0;i<numberoflines;i++){
        //printf("%d\n",index);
        index=k;
        count=0;
        while (*(*(time+i)+index)!='\0'){
            *(*(second+i)+count)=*(*(time+i)+index);
            count++;
            index++;
        }
         *(*(second+i)+count)='\0';
         //index=k;
    }


    return 0;
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
int bubblesort(int arr[],int n){
    int i=0,j=0;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    return 0;

}
int charges(int size, int timesec[],int bill[]){
    //int size=sizeof(timesec)/sizeof(timesec[0]);
    //printf("size is :%d",size);
   // int bill[size];
    int sum=0;
    for (int i=0;i<size;i++){
        if (timesec[i]<300){
            bill[i]=timesec[i]*3;
        }
        else {
            if (timesec[i]%60!=0){
                bill[i]=((timesec[i]/60)+1)*150;
            }

            else{
                bill[i]=(timesec[i]/60)*150;
            }
        }
        sum=sum+bill[i];

    }
    //printf("sum is:%d",sum);

    return sum;
}
int main()
{
    //printf("Hello world!\n");
    char input[]="00:01:07,400-234-090\n00:05:01,701-080-080\n00:05:00,400-234-090\n00:01:07,400-234-082\n00:04:00,400-234-082\n00:01:00,400-234-082\n00:01:07,400-234-091\n00:05:00,400-234-091";
    int count=linenocount(input);
    char *oplog[count];
    //printf("Max Size: %d \n",count);
    char *time[count];
    char *num[count];
    char *cleannum[count];
    char *hr[count],*min[count],*sec[count];
    for(int i = 0; i < count; i++)
        oplog[i] =  (char *)malloc(20*sizeof(char));
    for(int i = 0; i < count; i++)
        time[i] =  (char *)malloc(20*sizeof(char));
    for(int i = 0; i < count; i++)
        num[i] =  (char *)malloc(20*sizeof(char));
    for(int i = 0; i < count; i++)
        cleannum[i] =  (char *)malloc(20*sizeof(char));
    //parselog(input,oplog);
    //for (int i=0; i<count;i++)
        //printf("%d  log:%s\n",i+1,*(oplog+i));
   // printf("New Function....\n");
    parselog_1(input,oplog);
     for (int i=0; i<count;i++)
        printf("%d  new log:%s\n",i+1,*(oplog+i));
    parseCalldurationAndNumber(input,oplog,time,num);
    for(int i = 0; i < count; i++){
        hr[i] =  (char *)malloc(3*sizeof(char));
        min[i] =  (char *)malloc(3*sizeof(char));
        sec[i] =  (char *)malloc(3*sizeof(char));
    }
    //for (int i=0;i<count;i++){
        //printf("%d  time:%s\n",i+1,*(time+i));

   // }
   // for (int i=0;i<count;i++){
       // printf("%d  num:%s\n",i+1,*(num+i));

    //}
    clenPhNo(input,num,cleannum);
    for (int i=0;i<count;i++){
       // printf("%d  clean num:%s\n",i+1,*(cleannum+i));

    }
    int numarr[count];
    for (int i=0;i<count;i++){
       numarr[i]=atoi(*(cleannum+i));
    }
    for (int i=0;i<count;i++){
       // printf("array:%d\n",numarr[i]);
    }
    parsetime(input,time,hr,min,sec);
    for (int i=0;i<count;i++){
        //printf("hour:%s,min:%s,sec:%s\n",*(hr+i),*(min+i),*(sec+i));
    }
    int timearr[count];
    for (int i=0; i<count;i++){
        timearr[i]=atoi(*(hr+i))*3600+atoi(*(min+i))*60+atoi(*(sec+i));
    }
    for (int i=0;i<count;i++){
       // printf("time %d: %d\n",i+1,timearr[i]);
    }
    int n;
    n=sizeof(numarr)/sizeof(numarr[0]);
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;){
            if (numarr[i]==numarr[j]){
                timearr[i]=timearr[i]+timearr[j];
                for (int k=j;k<n;k++){
                    numarr[k]=numarr[k+1];
                    timearr[k]=timearr[k+1];
                }
                n--;
            }
            else{
                j++;
            }
        }
    }
    for (int i=0;i<n;i++){
       // printf("New array: %d\n",numarr[i]);
    }

    for (int i=0;i<n;i++){
       // printf("time array:%d\n",timearr[i]);
    }

    int timearrnew[n-1];
    int bill[n-1];
    bubblesort(timearr,n);
    /*
    if (timearr[n-1]==timearr[n-2]){
        for (int i=0;i<n-1;i++){
            timearrnew[i]=timearr[i];
        }
        int sum=0;
        int bill_1[n-1];
        charges(timearrnew,bill_1);
        for (int i=0;i<n-1;i++){
        //timearrnew[i]=timearr[i];
            //int sum;
            sum=sum+bill_1[i];
           // printf("Bill:%d\n",sum);
        }
            printf("Bill:%d\n",sum);
    }
    //printf("Bill:%d\n",sum);

    for (int i=0;i<n;i++){
        printf("time array:%d\n",timearr[i]);
    }*/
    for (int i=0;i<n-1;i++){
        timearrnew[i]=timearr[i];
       // printf("Billable time:%d\n",timearrnew[i]);
    }
    int m=sizeof(timearrnew)/sizeof(timearrnew[0]);
    int sum=0;
    if (n>1){
        int charge=charges(m,timearrnew,bill);
        printf("Bill:%d\n",charge);
        }
       // printf("Bill:%d\n",charge);
        else {
            int i=0;
            bill[i]=0;
            printf("Bill:%d\n",bill[i]);
        }
        return 0;
    }



