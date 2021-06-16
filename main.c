#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
typedef struct list
{
    char bookname[100];
    int id;
    char author[100];
    float price;
} List;
struct listNode
{
    List l;
    struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void start();
void save();
void welcomeMessage();
void headMessage(const char *message);
int main(){
}
void start()
{

    FILE *fptr;
    if ((fptr=fopen("store.txt","r+") ) == NULL)puts("File could not be opened");
    else
    {
        ListNodePtr current=startPtr;

        while(!feof(fptr))
        {

            ListNodePtr newNode =malloc(sizeof(ListNode));;

            newNode->nextPtr=NULL;
            fscanf(fptr,"%d  %19[^\n]%*1[\n]",&newNode->l.id,newNode->l.author);
            fscanf(fptr,"%f  %19[^\n]%*1[\n]",&newNode->l.price,newNode->l.bookname);
            if ( feof(fptr) )break;

            if(startPtr==NULL)
            {
                startPtr=newNode;
                current=startPtr;
            }
            else
            {
                current->nextPtr=newNode;
                current=current->nextPtr;
            }
        }

        fclose(fptr);
    }
}
void save()
{
    FILE *fptr;
    if ((fptr=fopen("store.txt","w") ) == NULL)puts("File could not be opened");
    else
    {
        ListNodePtr current=startPtr;

        current=startPtr;
        while(current!=NULL)
        {
            fprintf(fptr,"%d  %s \n",current->l.id,current->l.author);
            fprintf(fptr,"%f  %s \n",current->l.price,current->l.bookname);
            current=current->nextPtr;
        }

    }
    fclose(fptr);
    return 0;
}
void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############            Books-Databases in C                   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void welcomeMessage()
{
    headMessage("faculty of engineering  shoubra banha");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 Books                     =");
    printf("\n\t\t\t        =               Databases                   =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n                          ");
    system("pause");
}
