#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

void menu(void);
void Speed_post();
void Registered_post();
void Parcel_booking();
void information();
void Login_or_signup();
void Admin_login();
void close();
void Money_transfer();
void Ecard_Booking();
void search();
void print_search(FILE *file);
void all_record(FILE *f1);;
void ll();

char username[20],email_id[30],phone_no[12],pin[13];
float weight,cost,amount ;

struct
{
    char s[15];
    char r[15];
    char name[25];
    char address[100];
    int pincode;
    char city[50];
    char state[50];
}sender,reciever;


struct list
{
    char *string;
    char *data1;
    char *data2;
    char *data3;
    char *data4;
    struct list *next;
};
typedef struct list LIST;

void main()
{
  Login_or_signup();
}

void menu(void)
{
       int choice;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\t\t<<POSTAL SERVICES>>");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1) Speed Post\n\t\t2) Resgistered Post\n\t\t3) Parcel Bookings\n\t\t4) Money Transfer\n\t\t5) E-card Booking\n\t\t6) Search your records\n\t\t7) Login Module\n\t\t8) Exit \n\n\n\n\n\t\t Enter your choice: ");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:
        Speed_post();
        break;
        case 2:
        Registered_post();
        break;
        case 3:
        Parcel_booking();
        break;
        case 4:
            Money_transfer();
            break;
        case 5:
            Ecard_Booking();
            break;
        case 6:
            search();
            break;
        case 7:
            Login_or_signup();
            break;
        case 8:
            close();
            break;

        default :
            printf("\nInvalid option\n Enter a valid option :");
            system("pause");
            menu();
            break;
    }
}

void information()
{

    printf("\n\t\t\t                     <<Sender Information>>\n\n");
    printf("\nEnter name : ");
    getchar();
    gets(sender.name);
    printf("\nEnter address : ");
    gets(sender.address);
    printf("\nEnter pin code : ");
    scanf("%d",&sender.pincode);
    printf("\nEnter city name : ");
    getchar();
    gets(sender.city);
    printf("\nEnter state : ");
    gets(sender.state);

    system("color 2");
    printf("\t\t\t                     <<Reciever Information>>\n\n");
    printf("\nEnter name : ");
    gets(reciever.name);
    printf("\nEnter address : ");
    gets(reciever.address);
    printf("\nEnter pin code : ");
    scanf("%d",&reciever.pincode);
    printf("\nEnter city name :");
    scanf("%s",reciever.city);
    printf("\nEnter state : ");
    getchar();
    gets(reciever.state);
}

void Speed_post()
{
    FILE *sp ;
    system("cls");
    system("color 1");
    printf("\n\t\t\t                     <<SPEED POST BOOKING>>\n\n");
     information();

    sp=fopen("speed_post.txt","a");
     if(sp==NULL)
     {
         printf("\nSpeed_post.txt file could not be opened \n");
     }
     else
    {
        fprintf(sp,"%s:SENDER:%s:%s:%d:%s:%s:RECIEVER:%s:%s:%d:%s:%s:\n",username,sender.name,sender.address,sender.pincode,sender.city,sender.state,reciever.name,reciever.address,reciever.pincode,reciever.city,reciever.state);

        printf("\nSpeed Post Booked......\nRecord Inserted!........\n");
    }
    fclose(sp);
    system("pause");
    menu();
}

void Registered_post()
{
        FILE *rp ;
    system("cls");
    system("color 1");
    printf("\n\t\t\t                     <<REGISTERED POST BOOKING>>\n\n");
    information();


    rp=fopen("registered_post.txt","a");
     if(rp==NULL)
     {
         printf("\nregistered_post.txt file could not be opened \n");
     }
     else
    {
        fprintf(rp,"%s:SENDER:%s:%s:%d:%s:%s:RECIEVER:%s:%s:%d:%s:%s:\n",username,sender.name,sender.address,sender.pincode,sender.city,sender.state,reciever.name,reciever.address,reciever.pincode,reciever.city,reciever.state);
        printf("\nRegistered Post Booked......\nRecord Inserted!........\n");
    }
    fclose(rp);
    system("pause");
    menu();

}


void Parcel_booking()
{
    FILE *pp;
    system("cls");
    system("color 5");
    printf("\n\t\t\t                      <<PARCEL BOOKING>>\n\n");
    information();


    label:
        printf("NOTE: The weight should not exceed 30kg\nEnter weight (in kgs) : ");
        scanf("%f",&weight);
        if(weight>0&&weight<=1)
            cost=100;
        else if(weight>=1&&weight<=3)
            cost=175;
        else if(weight>=2&&weight<=5)
            cost=250;
        else if(weight>=5&&weight<=10)
            cost=375;
        else if(weight>=10&&weight<=15)
            cost=500;
        else if(weight>=15&&weight<=20)
            cost=625;
        else if(weight>=20&&weight<=25)
            cost=750;
        else if(weight>=25&&weight<=30)
            cost=875;
        else
            goto label;

            printf("\nCost : %.2f",cost);

   pp=fopen("parcel_post.txt","a");
     if(pp==NULL)
     {
         printf("\nparcel_post.txt file could not be opened \n");
     }
     else
    {
        fprintf(pp,"%s:SENDER:%s:%s:%d:%s:%s:RECIEVER:%s:%s:%d:%s:%s:Weight:=%.2f:Cost:=%.2f:\n",username,sender.name,sender.address,sender.pincode,sender.city,sender.state,reciever.name,reciever.address,reciever.pincode,reciever.city,reciever.state,weight,cost);
        printf("\nParcel Booked .....\nRecord Inserted!........\n");
    }
    fclose(pp);
    system("pause");
    menu();

}


void Login_or_signup()
{
    FILE *login,*c_details;
    int op,i;
    char password[15], p[15]="harshu2003",user[15],ch;

    system("cls");
    system("color 5");
    printf("\n\n\t\t\t\t<<POSTAL SERVICES>>\n\n");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t1. Admin login\n\t2. customer Login\n\t3. Create an Account\n\t4. Exit\n\n\t\tEnter your choice : ");
    scanf("%d",&op);


     switch(op)
     {
     case 1:
         printf("\n                        <<ADMIN LOGIN>>\n\nEnter your username :");
        scanf("%s",username);
        printf("\nEnter your password :");

        for(i = 0;i < 100;i++)
         {
        ch= getch();
        if(ch == 13)
        break;
        password[i] = ch;
        ch = '*' ;
        printf("%c ", ch);
        }
        password[i] = '\0';


        if(strcmp(password,p)==0)
        {
            printf("\n\n                  Successfully loggedin\n");
          system("pause");
        Admin_login();
        }
        else
        {
           printf("\nEnter a valid password!.....\n");
           system("pause");
             Login_or_signup();
        }


        break;

     case 2:

         printf("\n\n                       <<COSTUMER LOGIN>>\n\nEnter your username :");
        scanf("%s",username);
        printf("\nEnter your password :");
        for(i=0;i<100;i++)
        {
            ch=getch();
            if(ch==13)
                break;
            password[i]=ch;
            ch='*';
            printf("%c ",ch);
        }
        password[i]= '\0';
        char u1[15],p1[15];
        int count=0;
        login=fopen("login_details.txt","r");

        if(login==NULL)
         {
            printf("\nlogin_details.txt file could not be opened \n");
         }

        while(fscanf(login,"%s %s\n",u1,p1)!=EOF)
        {
            if((strcmp(username,u1)==0)&&(strcmp(password,p1)==0))
            {
                printf("\nLOGIN SUCCESSSFULLY\n \n");
                count++;
            }
        }
            if(count==0)
            {
                printf("\tSorry your account is not found \n\n\t Would you like to create a new account \n\n ");
                system("pause");
                Login_or_signup();

            }
            system("pause");

        fclose(login);
        menu();
        break;
     case 3:
         system("cls");
          printf("\n\n                       <<COSTUMER NEW LOGIN>>\n\nEnter your username :");
        scanf("%s",username);
        printf("\n\nEnter your password :");
        for(i=0;i<100;i++)
        {
            ch=getch();
            if(ch==13)
                break;
            password[i]=ch;
            ch='*';
            printf("%c ",ch);
        }
        password[i]='\0';
        printf("\n\nEnter your email-id : ");
        getchar();
        gets(email_id);
        printf("\n\nPhone no. : ");
        getchar();
        gets(phone_no);
        printf("\n\nEnter pin code : ");
        gets(pin);
        login=fopen("login_details.txt","a+");
        c_details=fopen("costumer_details.txt","a+");
        if((login==NULL)&&(c_details==NULL))
         {
            printf("\nlogin_details.txt file could not be opened \n");
         }
         else
         {
             fprintf(login,"%s\t%s\n",username,password);
             fprintf(c_details,"%s %s %s %s %s\n",username,password,email_id,phone_no,pin);
         }
         fclose(login);
         fclose(c_details);
         printf("\n\n\tSuccessfully account created\n\n");
         system("pause");
         menu();
         break;


     case 4:
        close();
        break;

     default :
                printf("\nInvalid entry\nEnter a valid option \n");
                system("pause");
                Login_or_signup();
        break;

     }
}

void Admin_login()
{
    system("cls");
    int op1;
    FILE *sp, *rp, *pp ,*login,*mp,*eb,*c_details;
    char line[200],log;
    char password[10];
            printf("\n\n\n\t\t                        <<ADMIN LOGIN>>\n\n");

            printf("\n    \t             <<Booking details>>\n\n\t1. Speed Post\n\t2. Registered Post\n\t3. Parcel Booking\n\t4. Money transfer\n\t5. Customer logins\n\t6. Customer details\n\t7. E-card booking\n\t8. Log out\n\n");
            printf("\n\t\tEnter your choice : ");
            scanf("%d",&op1);
            switch(op1)
            {
            case 1:
                   system("cls");
                sp=fopen("speed_post.txt","a+");
                if(sp==NULL)
                {
                   printf("\nSpeed_post.txt file could not be opened \n");
                }
                 else
                {
                    printf("\n\n\n\t\t\t\t   <<SPEED POST DETAILS>>\n\n\n\n\tUSER\t\tNAME\t\tADDRESS\t\t\tPINCODE\t\tCITY\t\tSTATE\n\n ");
                       all_record(sp);
                }
                 fclose(sp);
                 system("pause");
                  Admin_login();
                 break;

            case 2:
                system("cls");
                rp=fopen("registered_post.txt","a+");
                if(rp==NULL)
                {
                   printf("\nregistered_post.txt file could not be opened \n");
                }
                 else
                {
                    printf("\n\n\n\t\t\t\t    <<REGISTERED POST DETAILS>>\n\n\n\n\t\tUSER\t\tNAME\t\tADDRESS\t\t\tPINCODE\t\tCITY\t\tSTATE\n\n ");

                     all_record(rp);

                }
                 fclose(rp);
                 system("pause");
                  Admin_login();
                 break;

            case 3:
                system("cls");
                pp=fopen("parcel_post.txt","a+");
                if(pp==NULL)
                {
                   printf("\nparcel_post.txt file could not be opened \n");
                }
                 else
                {
                    printf("\n\n\n\t\t\t\t     <<PARCEL BOOKING DETAILS>>\n\n\n\n\t\tUSER\t\tNAME\t\tADDRESS\t\tPINCODE\t\tCITY\t\tSTATE\n\n ");

                    all_record(pp);

                }
                 fclose(pp);
                 system("pause");
                  Admin_login();
                 break;

            case 4:
                system("cls");
                mp=fopen("money_post.txt","a+");
                if(mp==NULL)
                {
                   printf("\nmoney_post.txt file could not be opened \n");
                }
                 else
                {
                    printf("\n\n\n\t\t\t\t     <<MONEY TRANSFER DETAILS>>\n\n\n\n\t\tUSER\t\tNAME\t\tADDRESS\t\tPINCODE\t\tCITY\t\tSTATE\n\n ");

                    all_record(mp);

                }
                 fclose(mp);
                 system("pause");
                  Admin_login();
                 break;

            case 5:
                system("cls");
                login=fopen("login_details.txt","r");

                if(login==NULL)
                {
                    printf("\nlogin_details.txt file could not be opened \n");
                }
                else
                {
                    printf("\n\n\n\t\t\t\t          <<CUSTOMER'S LOGIN DETAILS>>\n\n\n\tUSERNAME\tPASSWORD\n\n");

                    while(fscanf(login,"%s %s",username,password)!=EOF)
                    {
                        printf("%15s %15s\n",username,password);
                    }
                }
                fclose(login);

                system("pause");
                 Admin_login();
               break;

            case 6:
                system("cls");
                c_details=fopen("costumer_details.txt","r");
                 char email[30],phone[13],pin2[10];
                if(c_details==NULL)
                {
                    printf("\nCostumer_details.txt file could not be opened \n");
                }
                else
                {
                    printf("\n\n\n\t\t\t\t          <<CUSTOMER'S DETAILS>>\n\n\n\tUSERNAME\tPASSWORD\t\tE-MAIL\t\tPHONE NO.\tPIN CODE\n\n");
                    while(fscanf(c_details,"%s %s %s %s %s",username,password,email,phone,pin2)!=EOF)
                    {
                        printf("%15s %15s %30s %15s %10s\n",username,password,email,phone,pin2);
                    }
                }
                fclose(c_details);

                system("pause");
                 Admin_login();
               break;

            case 7:
                system("cls");
                eb=fopen("Ecard_post.txt","a+");
                if(eb==NULL)
                {
                   printf("\nEcard_post.txt file could not be opened \n");
                }
                 else
                {
                    printf("\n\n\n\t\t\t\t    <<E-CARD BOOKING DETAILS>>\n\n\t\tUSER\t\tNAME\t\tADDRESS\t\tPINCODE\t\tCITY\t\tSTATE\n  ");

                    all_record(eb);
                }
                 fclose(eb);
                 system("pause");
                  Admin_login();
                 break;


            case 8:
                printf("\n\n\t\t\t\t\tLogged out successfully.....\n\n\n");
                    system("pause");
                    Login_or_signup();
                break;


            default :
                printf("\n\n\t\tIncorrect choice!.....\n\n\t\tTry again  ");
                system("pause");
                Admin_login();
                break;

            }
}


void Money_transfer()
{
    FILE *mp;
    system("cls");
    system("color 6");
    printf("\t\t\t                        <<MONEY TRANSFER>>\n\n");
    information();

    printf("\nEnter Amount (in Rs.) : ");
    scanf("%f",&amount);
    mp=fopen("money_post.txt","a");
     if(mp==NULL)
     {
         printf("\nmoney_post.txt file could not be opened \n");
     }
     else
    {
        fprintf(mp,"%s:SENDER:%s:%s:%d:%s:%s:RECIEVER:%s:%s:%d:%s:%s:Amount:= %f:\n",username,sender.name,sender.address,sender.pincode,sender.city,sender.state,reciever.name,reciever.address,reciever.pincode,reciever.city,reciever.state,amount );

        system("color 11");
        printf("\n\nMoney SUCCESSFULLY Transfered......\nRecord Inserted!........\n");
    }
    fclose(mp);
    system("pause");
    menu();

}

void Ecard_Booking()
{
    FILE *eb;
    system("cls");
    system("color 9");
    char code[10];

    int cost=300;

    printf("\t\t\t                        <<E-CARD BOOKING>>\n\n");
    information();
     printf("\nEnter code of CARD : ");
    gets(code);
    printf("\nAmount (in Rs.) : %d\n",cost);
    eb=fopen("Ecard_post.txt","a");
     if(eb==NULL)
     {
         printf("\nEcard_post.txt file could not be opened \n");
     }
     else
    {
        fprintf(eb,"%s:SENDER:%s:%s:%d:%s:%s:RECIEVER:%s:%s:%d:%s:%s:Amount:= %f:Code:= %s:\n",username,sender.name,sender.address,sender.pincode,sender.city,sender.state,reciever.name,reciever.address,reciever.pincode,reciever.city,reciever.state,cost,code);

        system("color 11");
        printf("\n\nE-CARD BOOKED ......\nRecord Inserted!........\n");
    }
    fclose(eb);
    system("pause");
    menu();

}

void search()
{
    system("cls");
    FILE *sp, *rp, *pp ,*mp,*eb,*c_details;
    int op,i,count=0;
    char u1[15];
    printf("\n\n\t\t\t\t        <<SEARCH YOUR RECORDS>>\n    ");

    printf("\n\n\n\t\t1) Speed post details \n\t\t2) Registered post booking \n\t\t3) Parcel booking \n\t\t4) Money order details \n\t\t5) E-card booking \n\t\t6) Costumer details \n\t\t7) Go back to MENU module\n\n\t\t\tEnter your choice :");
    scanf("%d",&op);

    switch(op)
    {
         case 1:
                 system("cls");
                sp=fopen("speed_post.txt","r");
                if(sp==NULL)
                {
                   printf("\nSpeed_post.txt file could not be opened \n");
                }
                 else
                {
                    printf("\n\n\t\t\t     <<SPEED POST DETAILS>>\n\n\tUSER\t\tNAME\t\tADDRESS\t\t\tPINCODE\t\tCITY\t\tSTATE\n ");

                    print_search(sp);
                    fclose(sp);
                }

                 system("pause");
                  search();
                 break;


        case 2:
            system("cls");
                rp=fopen("registered_post.txt","r");
                if(rp==NULL)
                {
                   printf("\nregistered_post.txt file could not be opened \n");
                }
                 else
                {
                    printf("\n\n\t\t\t     <<REGISTERED POST DETAILS>>\n\n\tUSER\t\tNAME\t\tADDRESS\t\t\tPINCODE\t\tCITY\t\tSTATE\n ");

                    print_search(rp);
                    fclose(rp);
                }

                 system("pause");
                  search();
            break;

           case 3:
               system("cls");
                pp=fopen("parcel_post.txt","a+");
                if(pp==NULL)
                {
                   printf("\nparcel_post.txt file could not be opened \n");
                }
                 else
                {
                    printf("\n\n\t\t\t     <<PARCEL BOOKING DETAILS>>\n\n\tUSER\t\tNAME\t\tADDRESS\t\t\tPINCODE\t\tCITY\t\tSTATE\n ");

                    print_search(pp);
                 fclose(pp);
                }

                 system("pause");
                  search();
                 break;

            case 4:
                system("cls");
                mp=fopen("money_post.txt","a+");
                if(mp==NULL)
                {
                   printf("\nmoney_post.txt file could not be opened \n");
                }
                 else
                {
                    printf("\n\n\t\t\t     <<MONEY ORDER DETAILS>>\n\n\tUSER\t\tNAME\t\tADDRESS\t\t\tPINCODE\t\tCITY\t\tSTATE\n ");

                    print_search(mp);
                 fclose(mp);
                }
                 system("pause");
                  search();
                 break;

            case 5:
                system("cls");
                eb=fopen("Ecard_post.txt","r");
                if(eb==NULL)
                {
                   printf("\nEcard_post.txt file could not be opened \n");
                }
                 else
                {
                    printf("\n\n\t\t\t    <<E-CARD BOOKING DETAILS>>\n\n\tUSER\t\tNAME\t\tADDRESS\t\t\tPINCODE\t\tCITY\t\tSTATE\n ");
                     print_search(eb);
                }
                 fclose(eb);
                 system("pause");
                  search();
                 break;

            case 6:
                system("cls");
                c_details=fopen("costumer_details.txt","r");
                char password[10];
                if(c_details==NULL)
                {
                    printf("\nCostumer_details.txt file could not be opened \n");
                }
                else
                {
                    printf("\n\n\t\t\t          <<CUSTOMER'S DETAILS>>\n\n\n\tUSERNAME\tPASSWORD\t\tE-MAIL\t\t\tPHONE NO.\t\tPIN CODE\n");

                    ll();

                }

                fclose(c_details);

                system("pause");
                 search();
               break;

            case 7:
                    system("pause");
                    menu();
                break;


            default :
                printf("\n\n\t\tIncorrect choice!.....\n\n\t\tTry again  ");
                system("pause");
                system("cls");
                search();
                break;

            }

}



void print_search(FILE *file)
{
    int i=1,count=0;
    char line[200];
    while(fgets(line,sizeof(line),file))
                    {
                        i=1;
                        char *token = strtok(line,":");
                        if((i==1)&&(strcmp(username,token)==0))
                    {
                          while(token!=NULL)
                          {
                              if(strcmp(token,"SENDER")==0)
                                  printf("\n");

                              if(strcmp(token,"RECIEVER")==0)
                                printf("\n");

                              if(strcmp(token,"Amount")==0)
                                printf("\n");

                              if(strcmp(token,"Weight")==0)
                                printf("\n");

                              printf("%17s",token);
                              token=strtok(NULL, ":");
                              }
                              i++;
                              count++;
                          }
                          printf("\n");

                    }
                    if(count==0)
                        printf("no record found\n");
}

void all_record(FILE *f1)
{
    char line[200];

    while(fgets(line,sizeof(line),f1))
                    {
                        char *token = strtok(line,":");
                          while(token!=NULL)
                          {
                              if(strcmp(token,"SENDER")==0)
                                  printf("\n");

                              if(strcmp(token,"RECIEVER")==0)
                                printf("\n");

                                if(strcmp(token,"Amount")==0)
                                printf("\n");

                              if(strcmp(token,"Weight")==0)
                                printf("\n");

                              printf("%17s",token);
                              token=strtok(NULL, ":");
                          }
                          printf("\n");
                    }

}

void close(void)
{
    system("cls");
    printf("\n\n\n\n\t\t\tTHANK YOU!!!\n\n\n\n\n");
}

void ll()
{
    FILE *c_details;
    int count=0,op,ch2,calc=0;
    char line[150],n[20],pa[25],e[50],pn[15],p[10];
    LIST *current ,*head;
    head=current=NULL;
    c_details=fopen("costumer_details.txt","r");

    while(fscanf(c_details,"%s %s %s %s %s",n,pa,e,pn,p)!=EOF)
    {
        LIST *node =malloc(sizeof(LIST));
        node->string=strdup(n);
        node->data1=strdup(pa);
        node->data2=strdup(e);
        node->data3=strdup(pn);
        node->data4=strdup(p);
        node->next=NULL;
        if(head==NULL)
        {
            current=head=node;
        }
        else
        {
            current=current->next=node;
        }
    }
    fclose(c_details);

    for(current=head;current;current=current->next)
    {
        if(strcmp(username,current->string)==0)
        {
            printf("\n%15s %15s %35s %20s %10s\n\n",current->string,current->data1,current->data2,current->data3,current->data4);
             count=1;
             change:
                 system("pause");
             printf("\n\n\t\tDo you want to edit any of ur details (like email , phone number, pin code )\n \n\t\tif yes enter 1\n \n\t\tEnter your choice : ");
             scanf("%d",&op);
             if(op==1)
             {
                 printf(" \n\n\t\t1. E-mail \n\t\t2. Phone number\n\t\t3-Pin code \n\n\t\t\tEnter your choice : ");
                 scanf("%d",&ch2);
                 switch(ch2)
                 {
                     case 1: printf("\n\tEnter your new E-mail : ");
                     getchar();
                     gets(current->data2);
                     calc=1;
                     break;

                     case 2: printf("\n\tEnter your new Phone number : ");
                     getchar();
                     gets(current->data3);
                     calc=1;
                     break;

                     case 3: printf("\n\tEnter your new pincode : ");
                     getchar();
                     gets(current->data4);
                     calc=1;
                     break;

                     default : printf("\n\t\tInvalid option\n");
                     goto change;
                     break;
                 }
             }
             system("cls");
             printf("\n\n\tNew details \n\n");
             printf("\n\n\n\tUSERNAME\tPASSWORD\tE-MAIL\t\t\tPHONE NO.\t\tPIN CODE\n");
             printf("\n%15s %15s %30s %15s %10s\n",current->string,current->data1,current->data2,current->data3,current->data4);
        }
    }

    if(calc==1)
    {
        c_details=fopen("costumer_details.txt","w");
        if(c_details==NULL)
            printf("error in opening a file\n");
        else
        {
        for(current=head;current;current=current->next)
        {
            strcpy(n,current->string);
            strcpy(pa,current->data1);
            strcpy(e,current->data2);
            strcpy(pn,current->data3);
            strcpy(p,current->data4);


            fprintf(c_details,"%s %s %s %s %s\n",n,pa,e,pn,p);
        }
        printf("Data updated successfully\n");
        }
        fclose(c_details);
    }
    if(count==0)
        printf("\n\n\t\t\tNO RECORDS\n\n\n");
    else
        printf("\n");
}
