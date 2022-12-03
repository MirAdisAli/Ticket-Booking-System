#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char name[20];
    int seat,ticket,date;
    struct node *next;
};

struct qnode
{
    char name[20];
    int seat,ticket,date;
    struct qnode *qnext;
};

void enqueue(struct qnode **first,int d,char name[20],int date)
{
    struct qnode *n;
    n=*first;
    if(n!=NULL)
    {
        struct qnode *newnode =(struct qnode*)malloc(sizeof(struct qnode));
        newnode->ticket= d;
        newnode->date= date;
        strcpy(newnode->name,name);

        while((n->qnext)!=NULL)
        {
            n= n->qnext;
        }
        n->qnext= newnode;
        newnode->qnext= NULL;
    }
    else if(n==NULL)
    {
        struct qnode *head =(struct qnode*)malloc(sizeof(struct qnode));

        head->ticket= d;
        head->date= date;
        strcpy(head->name,name);

        head->qnext=*first;
        *first= head;
    }
}

struct qnode *dequeue(struct qnode **first)
{
    struct qnode *m;
    m= *first;

    if(m==NULL)
    {
       return NULL;
    }
    else if(m->qnext==NULL)
    {
        *first=NULL;
        return m;
    }
    else
    {
        *first= m->qnext;
        return m;
    }
}

void display(struct qnode **first)
{
    struct qnode *n;
    n=*first;

    if(n!=NULL)
        printf("\nWaiting List\n");
    else
        printf("\nNo tickets in Waiting List\n");

        while(n!=NULL)
        {
            printf("Name : %s  ||  Date : %d  ||  Ticket No. : %d \n",n->name,n->date,n->ticket);
            n=n->qnext;
        }
        printf("\n\n");
}

int check(struct node **first,int d,char name[20],int date)
{
     struct node *m = (struct node*)malloc(sizeof(struct node)) ;
     m=*first;

        int n10=d%10;
        int dn100=d%100;
        int n100=dn100/10;
        int dn1000=d%1000;
        int n1000=dn1000/100;

     while(m!=NULL)
     {
        int mt = m->ticket;
        int m10=mt%10;
        int md100=mt%100;
        int m100=md100/10;
        int md1000=mt%1000;
        int m1000=md1000/100;

        if(m10==n10)
        {
            if(m1000 < n100&&m->date==date)
            {
                printf("Sorry ! This seat is Unavailable. So your ticket is added to waiting list.\n\n");
                struct qnode* qfirst = NULL;
                int tic=730000+d;
                return -1;
            }
        }
        m=m->next;
      }
      return 1;
}

int insertion(struct node **first,int d,char name[20],int date)
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->next=*first;
    *first=head;
    struct node *m = (struct node*)malloc(sizeof(struct node));
    m=head->next;
    int tic=730000+d;

    strcpy(head->name,name);
    head->seat=d%10;
    head->ticket=tic;
    head->date=date;
    int ret=0;

    return ret;
}

int set(struct node **first,int tn)
{
    struct node *head;
    struct node * n;
    head=*first;
    n=*first;
    struct node* m;
    m=n;
    int cou=1;
    int ret=0;

    while(n!=NULL)
    {
        if(tn==n->ticket && cou>1)
        {
            m->next=n->next;
            n->next=head;
            *first=n;
            head=*first;

            ret=1;
        }
        else if(tn==n->ticket && cou==1){ret=1;}
        cou++;
        m= n;
        n= n->next;
    }
    return ret;
}

void traversal(struct node *n)
{
    FILE *ftr;
    ftr=fopen("FileTraverse","w");
    struct node *m;
    struct node *nn;
    nn=n;
    int t;
    char temp[20];
        while(n!=NULL)
    {
        m=n->next;
        while(m!=NULL)
        {
            if(n->seat>m->seat)
            {
                t= n->seat;
                n->seat=m->seat;
                m->seat=t;

                t= n->date;
                n->date=m->date;
                m->date=t;

                t= n->ticket;
                n->ticket=m->ticket;
                m->ticket=t;

                strcpy(temp,n->name);
                strcpy(n->name,m->name);
                strcpy(m->name,temp);
            }
            m= m->next;
        }
        n= n->next;
    }
    n= nn;
    while(n!=NULL)
    {
        fprintf(ftr,"%d - %s - %d - %d  \n",n->date,n->name,n->seat,n->ticket);
        n=n->next;
    }
    printf("\n\n");
    fclose(ftr);
}

void deletion(struct node **first)
{
      struct node *m;
      m= *first;
      if(m->next!=NULL)
      {
          *first=m->next;
          printf("\nTICKET CANCELED  -  %d \n\n",m->ticket);

      }
      else if(m->next==NULL)
      {
          printf("\nTICKET CANCELED  -  %d \n\n",m->ticket);
          *first=NULL;
      }
      else
      {
          printf("\nEMPTY !! deletion \n\n");
      }
}

int detail(int tn,int bp,int dp,struct node *n)
{
      printf("\n\nTICKET DETAILS : \n\n");
      if(bp==1 && dp==2)
      {
            while(n!=NULL)
            {
                if(n->ticket==tn)
                {
                    printf("Station A to Station B : Name       : %s \n",n->name);
                    printf("                         Date       : %d \n",n->date);
                    printf("                         Seat       : %d \n",n->seat);
                    printf("                         Ticket No. : %d \n\n",n->ticket);
                    return 73;
                }
                n=n->next;
            }
            printf("\n\n");
      }
      else if(bp==1 && dp==3)
      {
          while(n!=NULL)
            {
                if(n->ticket==tn)
                {
                    printf("Station A to Station C : Name       : %s \n",n->name);
                    printf("                         Date       : %d \n",n->date);
                    printf("                         Seat       : %d \n",n->seat);
                    printf("                         Ticket No. : %d \n\n",n->ticket);
                    return 73;
                }
                n=n->next;
            }
            printf("\n\n");
      }
      else if(bp==1 && dp==4)
      {
          while(n!=NULL)
            {
                if(n->ticket==tn)
                {
                    printf("Station A to Station D : Name       : %s \n",n->name);
                    printf("                         Date       : %d \n",n->date);
                    printf("                         Seat       : %d \n",n->seat);
                    printf("                         Ticket No. : %d \n\n",n->ticket);
                return 73;
                }
                n=n->next;
            }
            printf("\n\n");
      }
      else if(bp==2 && dp==3)
      {
             while(n!=NULL)
            {
                if(n->ticket==tn)
                {
                    printf("Station B to Station C : Name       : %s \n",n->name);
                    printf("                         Date       : %d \n",n->date);
                    printf("                         Seat       : %d \n",n->seat);
                    printf("                         Ticket No. : %d \n\n",n->ticket);
                return 73;
                }
                n=n->next;
            }
            printf("\n\n");

      }
      else if(bp==2 && dp==4)
      {
            while(n!=NULL)
            {
                if(n->ticket==tn)
                {
                    printf("Station B to Station D : Name       : %s \n",n->name);
                    printf("                         Date       : %d \n",n->date);
                    printf("                         Seat       : %d \n",n->seat);
                    printf("                         Ticket No. : %d \n\n",n->ticket);
                    return 73;
                }
                n=n->next;
            }
                printf("\n\n");
      }
      else if(bp==3 && dp==4)
      {
            while(n!=NULL)
            {
                if(n->ticket==tn)
                {
                    printf("Station C to Station D : Name       : %s \n",n->name);
                    printf("                         Date       : %d \n",n->date);
                    printf("                         Seat       : %d \n",n->seat);
                    printf("                         Ticket No. : %d \n\n",n->ticket);
                    return 73;
                }
                n=n->next;
            }
                printf("\n\n");

      }
      else return -1;
}

void main()
{
    int ch1=0,bp,dp,seat,date;
    char name[20],from[20],to[20];
    int itr=0,tn,rep;
    int re=0;
    struct node *first = NULL;
    struct qnode *qfirst = NULL;

    FILE *f1;
    f1=fopen("ticket73","w");

    do{
    printf("\n\t **** Welcome to Ticket Booking System ****\n");
    printf("\n\n\t\t\t1.Book Now!\n\n\t\t\t2.Cancel Ticket\n\n\t\t\t3.Ticket Details\n\n\t\t\t4.Waiting List\n\n\t\t\t5.Exit\n\n\t\t\t");
    printf("Enter your choice: ");
    scanf("%d",&ch1);
    printf("\n");

    switch(ch1)
    {
    case 1:

        printf("->Station A \n->Station B \n->Station C \n");
        do{
            if(itr==1)
            {
               printf("Enter Boarding Point: ");
            }
            gets(from);
            itr=1;

        }while(strcmpi(from,"Station A")!=0 && strcmpi(from,"Station B")!=0 &&
               strcmpi(from,"Station C")!=0 );

        printf("\n");
        if(strcmpi(from,"Station A")==0)bp=1;
        else if(strcmpi(from,"Station B")==0)bp=2;
        else if(strcmpi(from,"Station C")==0)bp=3;

        printf("Destinations are..\n");
        if(bp<2)
        {
            printf("->Station B \n->Station C \n->Station D\n");
        }
        else if(bp<3){ printf("->Station C \n->Station D \n");}
        else if(bp<4){ printf("->Station D \n");}

        do{
        if(itr==2)
        {
            printf("Please enter another destination than boarding point.\n");
        }
        itr=1;

        do{
            if(itr==1)
            {
                printf("Enter Destination : ");
            }
            gets(to);itr=1;

            }while((strcmpi(to,"Station B")!=0 || bp>=2)&&
            (strcmpi(to,"Station C")!=0 ||bp>=3)&& (strcmpi(to,"Station D")!=0)||bp==4);
        itr=2;

        }while(strcmpi(to,from)==0);

        if(strcmpi(to,"Station A")==0)dp=1;
        else if(strcmpi(to,"Station B")==0)dp=2;
        else if(strcmpi(to,"Station C")==0)dp=3;
        else if(strcmpi(to,"Station D")==0)dp=4;

        printf("\nEnter Date : ");
        scanf("%d",&date);
        gets(name);

        printf("\nEnter your name : ");
        gets(name);
        do{
        printf("Which seat you want out of 1 to 5: ");
        scanf("%d",&seat);
        }while(seat<1 || seat>5);

        if(bp==1 && dp==2)
        {
            if(check(&first,(seat+120),name,date)==-1)
            {
                    int tic=730000+seat+120;
                    enqueue(&qfirst,tic,name,date);
            }
            else
            {
                re=insertion(&first,(seat+120),name,date);
                printf("\nTICKET CONFIRMED == Station A to Station B | %d | %s | %d | %d \n\n",date,name,seat,(730120+seat));
                fprintf(f1,"Station A to Station B | %d | %s | %d | %d \n",date,name,seat,(730120+seat));
                traversal(first);
            }

        }

        else if(bp==1 && dp==3)
        {
            if(check(&first,(seat+130),name,date)==-1)
            {
                int tic=730000+seat+130;
                enqueue(&qfirst,tic,name,date);
            }
            else
            {
                re=insertion(&first,(seat+130),name,date);
                printf("\nTICKET CONFIRMED == Station A to Station C | %d | %s | %d | %d \n\n",date,name,seat,(730130+seat));
                fprintf(f1,"Station A to Station C | %d | %s | %d | %d \n",date,name,seat,(730130+seat));
                traversal(first);
            }
        }

        else if(bp==1 && dp==4)
        {
            if(check(&first,(seat+140),name,date)==-1)
            {
                int tic=730000+seat+140;
                enqueue(&qfirst,tic,name,date);
            }
            else
            {
                re=insertion(&first,(seat+140),name,date);
                printf("\nTICKET CONFIRMED == Station A to Station D | %d | %s | %d | %d \n\n",date,name,seat,(730140+seat));
                fprintf(f1,"Station A to Station D | %d | %s | %d | %d \n",date,name,seat,(730140+seat));
                traversal(first);
            }
        }

        else if(bp==2 && dp==3)
        {
            if(check(&first,(seat+230),name,date)==-1)
            {
                int tic=730000+seat+230;
                enqueue(&qfirst,tic,name,date);
            }
            else
            {
                re=insertion(&first,(seat+230),name,date);
                printf("\nTICKET CONFIRMED == Station B to Station C | %d | %s | %d | %d \n\n",date,name,seat,(730230+seat));
                fprintf(f1,"Station B to Station C | %d | %s | %d | %d \n",date,name,seat,(730230+seat));
                traversal(first);
            }
        }
        else if(bp==2 && dp==4)
        {
            if(check(&first,(seat+240),name,date)==-1)
            {
                int tic=730000+seat+240;
                enqueue(&qfirst,tic,name,date);

            }
            else
            {
                re=insertion(&first,(seat+240),name,date);
                printf("\nTICKET CONFIRMED == Station B to Station D | %d | %s | %d | %d \n\n",date,name,seat,(730240+seat));
                fprintf(f1,"Station B to Station D | %d | %s | %d | %d \n",date,name,seat,(730240+seat));
                traversal(first);
            }
        }

        else if(bp==3 && dp==4)
        {
            if(check(&first,(seat+340),name,date)==-1)
            {
                int tic=730000+seat+340;
                enqueue(&qfirst,tic,name,date);
            }
            else
            {
                re=insertion(&first,(seat+340),name,date);
                printf("\nTICKET CONFIRMED == Station C to Station D | %d | %s | %d | %d \n\n",date,name,seat,(730340+seat));
                fprintf(f1,"Station C to Station D | %d | %s | %d | %d \n",date,name,seat,(730340+seat));
                traversal(first);
            }
        }
        break;

    case 2 :

        tn=0;
        printf("Enter your ticket no. : ");
        scanf("%d",&tn);
        rep=0;
        int n10=tn%10;

        int dn100=tn%100;
        int n100=dn100/10;

        int dn1000=tn%1000;
        int n1000=dn1000/100;

        if(((tn-((tn)%1000))==730000) && n10<6 && n10>0 && n100<5 && n100>1
        && n1000<4 && n1000>0)
        {
            if(set(&first,tn)==1)
            {
                deletion(&first);traversal(first);
                rep=1;
                struct qnode *m;
                m = dequeue(&qfirst);

                if(m!=NULL)
                {
                    strcpy(name,m->name);
                    tn=m->ticket;

                    n10=tn%10;

                    dn100=tn%100;
                    n100=dn100/10;
                    dp=n100;

                    dn1000=tn%1000;
                    n1000=dn1000/100;
                    bp=n1000;
                    int tt;

                    re=insertion(&first,(tn%1000),name,date);
                    traversal(first);

                    if(bp==1 && dp==2)
                    {
                            printf("\nTICKET CONFIRMED == Station A to Station B | %d | %s | %d | %d \n\n",date,name,seat,(730120+seat));
                            fprintf(f1,"Station A to Station B | %d | %s | %d | %d \n",date,name,seat,(730120+seat));
                    }
                    else if(bp==1 && dp==3)
                    {
                            printf("\nTICKET CONFIRMED == Station A to Station C | %d | %s | %d | %d \n\n",date,name,seat,(730130+seat));
                            fprintf(f1,"Station A to Station C | %d | %s | %d | %d \n",date,name,seat,(730130+seat));
                    }
                    else if(bp==1 && dp==4)
                    {
                            printf("\nTICKET CONFIRMED == Station A to Station D | %d | %s | %d | %d \n\n",date,name,seat,(730140+seat));
                            fprintf(f1,"Station A to Station D | %d | %s | %d | %d \n",date,name,seat,(730140+seat));
                    }
                    else if(bp==2 && dp==3)
                    {
                            printf("\nTICKET CONFIRMED == Station B to Station C | %d | %s | %d | %d \n\n",date,name,seat,(730230+seat));
                            fprintf(f1,"Station B to Station C | %d | %s | %d | %d \n",date,name,seat,(730230+seat));
                    }
                    if(bp==2 && dp==4)
                    {
                            printf("\nTICKET CONFIRMED == Station B to Station D | %d | %s | %d | %d \n\n",date,name,seat,(730240+seat));
                            fprintf(f1,"Station B to Station D | %d | %s | %d | %d \n",date,name,seat,(730240+seat));
                    }
                    if(bp==3 && dp==4)
                    {
                            printf("\nTICKET CONFIRMED == Station C to Station D | %d | %s | %d | %d \n\n",date,name,seat,(730340+seat));
                            fprintf(f1,"Station C to Station D | %d | %s | %d | %d \n",date,name,seat,(730340+seat));
                    }
                }
            }
                    if(rep==0)printf("Please enter valid Ticket Number.\n\n");
        }
                    else
                    {
                        printf("Please enter valid Ticket Number \n\n");
                    }
        break;

      case 3:

         traversal(first);

         tn=0;
         printf("Enter your ticket no. : ");
         scanf("%d",&tn);
         rep=0;
         n10=tn%10;
         dn100=tn%100;
         n100=dn100/10;
         dn1000=tn%1000;
         n1000=dn1000/100;

         if(((tn-((tn)%1000))==730000) && n10<6 && n10>0 && n100<5 && n100>1
           && n1000<4 && n1000>0 )
         {
            if(detail(tn,n1000,n100,first)!=73)
            {
                printf("Please enter valid Ticket Number \n\n");
            }
         }
         else
         {
            printf("Please enter valid Ticket Number \n\n");
         }
         break;

      case 4:

         display(&qfirst);
         break;
     }
    }while(ch1!=5);
         fclose(f1);
}
