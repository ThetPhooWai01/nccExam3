#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int id = 0,amount = 0,password = 0,age = 0,choice = 0,newid = 0,newamount = 0,newpassword = 0,newage = 0,stop = 1;
char username[30],location[30],searchName[30],newusername[30],newlocation[30];
FILE *fptr1,*fptr2;

void insert(int id,char username[],int password,int amount,int age,char location[]);
void search(char searchName[]);
void view();
void edit();

int main(){

int tValue = 1;
int a = 0;

while(tValue == 1){
    puts("Press 1 to insert data");
    puts("Press 2 to find data");
    puts("Press 3 to update data");
    puts("Press 4 to view all data");
    printf(">");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            puts("Enter ID,USER NAME,PASSWORD,AMOUNT,AGE,LOCATION.");
            printf(">:");
            scanf("%d%s%d%d%d%s",&id,username,&password,&amount,&age,location);
            insert(id,username,password,amount,age,location);
            break;
        case 2:
            fptr1 = fopen("original.txt","r");
            fseek (fptr1, 0, SEEK_END);
            if(ftell(fptr1) != 0){
                puts("Enter NAME you want to find.");
                scanf("%s",searchName);
                search(searchName);
            }else{
                printf("There is no data yet!\n");
            }
            fclose(fptr1);
            break;
        case 3:
            fptr1 = fopen("original.txt","r");
            fseek (fptr1, 0, SEEK_END);
            if(ftell(fptr1) != 0){
                edit();
            }else{
                printf("There is no data yet!\n");
            }
            fclose(fptr1);
            break;
        case 4:
            fptr1 = fopen("original.txt","r");
            fseek (1, 0, SEEK_END);
            if(ftell(fptr1) != 0){
                view();
            }else{
                printf("There is no data yet!\n");
            }
            fclose(fptr1);
            break;
        default:
            printf("Please enter valid value!");
    }
}



return 0;
}

void insert(int id,char username[],int password,int amount,int age,char location[]){
    fptr1 = fopen("original.txt","a");
    if(fptr1 == NULL){
        printf("File Cannot Open!");
        exit(1);
    }
    while(!feof(stdin)){
        fprintf(fptr1 , "%d%10s%10d%10d%10d%15s\n",id,username,password,amount,age,location);
        printf(">:");
        scanf("%d%s%d%d%d%s",&id,username,&password,&amount,&age,location);
    }
    fclose(fptr1);
}

void search(char searchName[]){
    fptr1 = fopen("original.txt","r");
    if(fptr1 == NULL){
        printf("File Cannot Open!");
        exit(1);
    }

    do{
        fscanf(fptr1,"%d%10s%10d%10d%10d%15s",&id,username,&password,&amount,&age,location);
        if(strcmp(username,searchName) == 0){
            printf("%d%10s%10d%10d%10d%15s\n",id,username,password,amount,age,location);
            break;
        }else{
            printf("NO DATA FOUND!\n");
            break;
        }
    }
    while(!feof(fptr1));

    fclose(fptr1);
}

void view(){
    fptr1 = fopen("original.txt","r");
    if(fptr1 == NULL){
        printf("File Cannot Open!");
        exit(1);
    }
    while(fscanf(fptr1,"%d%10s%10d%10d%10d%15s",&id,username,&password,&amount,&age,location) == 6){
        printf("%d%10s%10d%10d%10d%15s\n",id,username,password,amount,age,location);
    }
    fclose(fptr1);
}

void edit(){

  fptr1 = fopen("original.txt","r");
  fptr2 = fopen("temp.txt","a");
    if(fptr1 == NULL){
        printf("File Cannot Open!");
        exit(1);
    }

    printf("Enter Name you  want to edit : ");
    scanf("%s",&searchName);
        fscanf(fptr1,"%d%10s%10d%10d%10d%15s",&id,username,&password,&amount,&age,location);
        printf("%d%10s%10d%10d%10d%15s\n",id,username,password,amount,age,location);
    printf("Sorry,there is no update function yet!Come back later!\n");
        fclose(fptr1);
        fclose(fptr2);
        remove("original.txt");
        rename("temp.txt","original.txt");
}
