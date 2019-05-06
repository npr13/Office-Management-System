#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct employee
{
    char emp_name[35];
    char emp_address[50];
    char emp_department[10]; 
    char date_of_joining[35];
    long int mble_no;
    long int emp_salary;
    char mail[100];
    char sex[8];
};
void got();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
void menu();
void admin();
void user();
void start();
int main()
{
    system("color 5f");
    start();
    return 0;
}
void start()
{
    menu();
}
void menu()
{
 system("cls");
printf("\t\t**********WELCOME TO OFFICE MANAGEMENT SYSTEM*************");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.Admin  \t2.User  \t3.Exit");
switch(getch())
{
    case '1':
    admin();
    break;
    case '2': 
	user();
    break;
    case '3': 
	exit(0);
    break;
    default:
     system("cls");
     printf("\nEnter 1 to 3 only");
     printf("\n Enter any key");
     getch();

menu();
}
}
        void addrecord()
{
        system("cls");
        FILE *f;
        struct employee e;
        f=fopen("project1","ab+");
        printf("\n Enter employee name: ");
        got(e.emp_name);
        printf("\nEnter employee address: ");
        got(e.emp_address);
        printf("\nEnter employee department: ");
        got(e.emp_department);
        printf("\nEnter emp date of joining:");
        got(e.date_of_joining);
        printf("\nEnter gender:");
        got(e.sex);
        printf("\nEnter e-mail:");
        got(e.mail);
    	printf("\nEnter employee phone no.:");
        scanf("%ld",&e.mble_no);
       	printf("\nEnter employee salary:");
        scanf("%ld",&e.emp_salary);
        fwrite(&e,sizeof(e),1,f);

      fflush(stdin);
        printf("\nrecord saved");

     fclose(f);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
    menu();
}
void listrecord()
{
    struct employee e;
    FILE *f;
f=fopen("project1","rb");
if(f==NULL)
{
printf("\nfile opening error in listing :");

exit(1);
}
while(fread(&e,sizeof(e),1,f)==1)
{
     printf("\n\n\n YOUR RECORD IS\n\n ");
     printf("\nEmployee Name=%s\nEmployee Adress=%s\nEmployee Department=%s\nEmployee date of joining=%s\nEmployee gender=%s\nEmployee E-mail=%s\nEmployee phone no=%ld\nEmployee salary=%ld",e.emp_name,e.emp_address,e.emp_department,e.date_of_joining,e.sex,e.mail,e.mble_no,e.emp_salary);
	 getch();
	 system("cls");
}
fclose(f);
 printf("\n Enter any key");
 getch();
    system("cls");
menu();
}
void searchrecord()
{
    struct employee e;
FILE *f;
char emp_name[100];

f=fopen("project1","rb");
if(f==NULL)
{
    printf("\n error in opening\a\a\a\a");
    exit(1);

}
printf("\nEnter name of employee to search\n");
got(emp_name);
while(fread(&e,sizeof(e),1,f)==1)
{
    if(strcmp(e.emp_name,emp_name)==0)
    {
        printf("\n\tDetail Information About %s",emp_name);
        printf("\nEmployee Name=%s\nEmployee Adress=%s\nEmployee Department=%s\nEmployee date of joining=%s\nEmployee gender=%s\nEmployee E-mail=%s\nEmployee phone no=%ld\nEmployee salary=%ld",e.emp_name,e.emp_address,e.emp_department,e.date_of_joining,e.sex,e.mail,e.mble_no,e.emp_salary);
    }
        else
        printf("file not found");

}
 fclose(f);
  printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}
void deleterecord()
/*{
char another;
system("cls");
      another = 'y';
           while(another == 'y')
            {  
	  			FILE *fp, *ft;
	  			struct employee e;
	  			char emp_name[30];
                printf("\nEnter name of employee to delete: ");
                scanf("%s",emp_name);
                ft = fopen("temp","wb");  /// create a intermediate file for temporary storage
                rewind(fp); /// move record to starting of file
                while(fread(&e,sizeof(e),1,fp) == 1)  /// read all records from file
                {
                    if(strcmp(e.emp_name,emp_name) != 0)  /// if the entered record match
                    {
                        fwrite(&e,sizeof(e),1,ft); /// move all records except the one that is to be deleted to temp file
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("project1"); /// remove the orginal file
                rename("temp","project1"); /// rename the temp file to original file name
                fp = fopen("project1", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                 printf("\n Enter any key");


    system("cls");
menu();
               // another = getche();
           }
}*/
{
    struct employee e;
    FILE *f,*ft;
	int flag;
	char emp_name[100];
	f=fopen("project1","rb");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("file opening error");
		else

        {


		printf("Enter EMPLOYEE's NAME:");
		got(emp_name);

		fflush(stdin);
		while(fread(&e,sizeof(e),1,f)==1)
		{
			if(strcmp(e.emp_name,emp_name)!=0)
				fwrite(&e,sizeof(e),1,ft);
			if(strcmp(e.emp_name,emp_name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("NO EMPLOYEE'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project1");
			rename("temp.txt","project1");
			printf("RECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}

void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct employee e,s;
	char  emp_name[50];
	f=fopen("project1","ra+");
	if(f==NULL)
		{

			printf("EMPLOYEE'S DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter EMPLOYEE'S NAME TO MODIFY:\n");
            got(emp_name);
            while(fread(&e,sizeof(e),1,f)==1)
            {
                if(strcmp(emp_name,e.emp_name)==0)
                {
		printf("\n Enter employee name: ");
        got(s.emp_name);
        printf("\nEnter employee address: ");
        got(s.emp_address);
        printf("\nEnter employee department: ");
        got(s.emp_department);
        printf("\nEnter emp date of joining:");
        got(s.date_of_joining);
        printf("\nEnter gender:");
        got(s.sex);
        printf("\nEnter e-mail:");
        got(s.mail);
    	printf("\nEnter employee phone no.:");
        scanf("%ld",&s.mble_no);
       	printf("\nEnter employee salary:");
        scanf("%ld",&s.emp_salary);
                    fseek(f,-sizeof(e),SEEK_CUR);
                    fwrite(&s,sizeof(e),1,f);
                    flag=1;
                    break;
                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n your data is modified");

            }
            else
            {
                    printf(" \n data is not found");

            }
            fclose(f);
	}
	 printf("\n Enter any key");
	 getch();
    system("cls");
	menu();

}
void admin()
{
	system("cls");
printf("\n\n\t\t\t ADMIN\t\t\n\n");
printf("\t1.Add New  \t2.Modify  \t3.Delete  \t4.list");
switch(getch())
{
    case '1':
    addrecord();
    break;
    case '2': 
	modifyrecord();
    break;
    case '3': 
	deleterecord();
    break;
    case '4':
    	listrecord();
    	break;
    default:
     system("cls");
     printf("\nEnter 1 to 3 only");
     printf("\n Enter any key");
     getch();

menu();
}
}
void user()
{
system("cls");
printf("\n\n\t\t\t USER\t\t\n\n");
printf("\t1.list  \t2.Search");
switch(getch())
{
    case '1': 
	listrecord();
    break;
    case '2': 
	searchrecord();
    break;
    default:
     system("cls");
     printf("\nEnter 1 amd 3 only");
     printf("\n Enter any key");
     getch();

menu();
}
}
void got(char *emp_name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(emp_name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(emp_name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(emp_name+i)='\0';
}
