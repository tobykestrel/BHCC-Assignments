//Orderhw4.c


//HW CHALLENGE PROBLEM!!!!!


// USE THIS PROGRAM AND INCLUDE A DELETE FUNCTION.
// RUN THEM ALL OFF A MENU LIKE IN STACK.C or final5.c from c1
// MENU ITEMS

//  1 LOAD THE LIST FROM DATA.BIN //buildlist
//  2 DISPLAY THE LIST  //prntlist
//  3 ADD TO THE LIST   // listinsert
//  4 DELETE FROM THE LIST // listdelete
//  5 EXIT


//INSERT.C
/*THIS PROGRAM READS A BINARY FILE (MUST ALREADY EXIST AND BE FILLED) */
/*AND PUTS IT INTO A LINKED LIST AND PRINTS THE LIST TO THE SCREEN)   */
#include <stdio.h>
#include <alloc.h>
#include <signal.h>
#include <string.h>

typedef struct ENTRY
{
 char name[81];
}ENTRY;

typedef struct LISTREC     /* LISTREC is a user-defined type, defined */
{                          /* before main so it will be global */
struct  ENTRY info;  /* info nests all fields contained in */
struct  LISTREC *link;    /* ENTRY (above).                   */
}LISTREC;                  /* link is a pointer variable to another   */
                           /* type LISTREC. NOTE: Name of type MUST   */
                           /* be entered at end of typedef            */
FILE *stream;
ENTRY part;

//prototypes !!!!
void listdelete(ENTRY part,LISTREC *liststart);
LISTREC *buildlist();
void prntlist(LISTREC *);
void listinsert(ENTRY,LISTREC *);
LISTREC * InsertAt(LISTREC *, ENTRY ,int );


void main()
{
  LISTREC *liststart;   /*holds a pointer to beginning of list*/
  stream=fopen("data.bin","r+b");

  liststart = buildlist();    /*buildlist is a function which will*/
// clrscr();                            /*return the beginning of the list*/
  printf("Before insertion linked list:\n");
 
			prntlist(liststart);
 
 printf("Enter name to insert:");
  scanf(" %[^\n]",part.name);
 
 printf("part.name = %s\n",part.name);
			listinsert(part,liststart);
 
			prntlist(liststart);
		
  printf("Before deletion linked list:\n");
  
			prntlist(liststart);
  
  printf("Enter name to delete:");
  scanf(" %[^\n]",part.name);
  
  printf("part.name = %s\n",part.name);
  
			listdelete(part,liststart);
  
			prntlist(liststart);
			
			

			printf("Enter name to insert using InsertAt 3:");
            scanf(" %[^\n]",part.name);
			
			printf("part.name = %s\n",part.name);
  
			liststart=InsertAt(liststart,part,3);
  
			prntlist(liststart);
			
			
			
			
			 printf("Enter name to insert using InsertAt 6:");
            scanf(" %[^\n]",part.name);
			
			printf("part.name = %s\n",part.name);
  
			liststart=InsertAt(liststart,part,6);
  
			prntlist(liststart);
			
			
			
			 printf("Enter name to insert using InsertAt 7:");
            scanf(" %[^\n]",part.name);
			
			printf("part.name = %s\n",part.name);
  
			liststart=InsertAt(liststart,part,7);
  
			prntlist(liststart);
			
			
			
		/*		 printf("Enter name to insert:");
            scanf(" %[^\n]",part.name);
			
			printf("part.name = %s\n",part.name);
  
			liststart=InsertAt(liststart,part,0);
  
			prntlist(liststart);
			
		*/
		
		
		
			 printf("Enter name to insert using InsertAt 1:");
            scanf(" %[^\n]",part.name);
			
			printf("part.name = %s\n",part.name);
  
			liststart=InsertAt(liststart,part,1);
  
			prntlist(liststart);
		
		// doesn't work but throws no error !!!!!!
			 printf("Enter name to insert using InsertAt 22:");
            scanf(" %[^\n]",part.name);
			
			printf("part.name = %s\n",part.name);
  
			liststart=InsertAt(liststart,part,22);
  
			prntlist(liststart);
		
		
		
		
}//main


/*****************FUNCTION LISTINSERT**********************/
void listinsert(ENTRY newentry,LISTREC *liststart)
{
 LISTREC *last,*next;
 next = liststart;

while ((strcmp(newentry.name,next->info.name)> 0) && (next->link != NULL))
 {
  last = next;
  next = next->link;
 }  /*end while*/

 if (strcmp(newentry.name,next->info.name) == 0)  /*if both are same*/
  next->info = newentry;   /*updates*/
 else
  if (strcmp(newentry.name,next->info.name) < 0)
  {
   last->link = (LISTREC*)malloc(sizeof(LISTREC));      /*creates new node*/
   last->link->info=newentry;
   last->link->link = next;
  }
  else
  {
    next->link = (LISTREC*)malloc(sizeof(LISTREC));
    next->link->info = newentry;
    next->link->link = NULL;
  }  /* end else */
  printf("\n\nAfter insertion, linked list:\n");
  
			prntlist(liststart);
			
 }   /* end function listinsert*/




/**************FUNCTION BUILDLIST************************/
LISTREC *buildlist()     /* Function buildlist returns type LISTREC.*/
{                         /* It takes no arguments */
	LISTREC *liststart = NULL;
													 /*of type LISTREC */
	int n;                   /*Needed to test for end of file*/

	//CREATE A DUMMY NODE !!!!

	liststart=(LISTREC *)malloc(sizeof(LISTREC));
	liststart->info.name[0]='\0';
	liststart->link=NULL;

	for (;;)
	 {   /*begin for*/   /*for will keep looping until breaks at end of file*/
		n= fread(&part,sizeof(part),1,stream);
		 if (n==0)  break;

		 listinsert(part,liststart);




			}  /*end for*/

	 return(liststart);

	}  /*end Function buildlist*/





/****************FUNCTION PRNTLIST********************/
void prntlist(LISTREC *liststart)
			/*argument is a pointer to type LISTREC*/
 {     /*begin function*/

	 while (liststart != NULL)
		{  /*begin while*/
			printf("%s\n",liststart->info.name);
			liststart = liststart->link;
		}  /*end while*/
	}   /* end function prntlist*/






/*****************FUNCTION LISTDELETE**********************/
void listdelete(ENTRY part,LISTREC *liststart)
{
 LISTREC *last,*next;
 next = liststart;

while ((strcmp(part.name,next->info.name)!=0) && (next->link != NULL))
 {
	last = next;
	next = next->link;
 }  /*end while*/


 if (strcmp(part.name,next->info.name) == 0)  /*if both are same*/
	{
	last->link=next->link;   /*updates*/
	free(next);
	}
	printf("\n\nAfter deletion, linked list:\n");
	
				prntlist(liststart);
 }   /* end function listdelete*/




LISTREC * InsertAt(LISTREC *liststart, ENTRY newentry,int n) {
	int i = 0;
	LISTREC * last  = NULL;
	LISTREC * next  = liststart;

	if (liststart == NULL) {
		liststart = (LISTREC*)malloc(sizeof(LISTREC));
		liststart->info=newentry;
		liststart->link = NULL;
		printf("\n Created node at %d",i);
	} else while ((next->link != NULL) &&  (i != n)) {
		last = next;
		next = next->link;
		++i;
	}

	if (i==n) {
		last->link = (LISTREC*)malloc(sizeof(LISTREC));
		last->link->info=newentry;
		last->link->link = next;
		printf("\n Created node at %d",i);	
	} else if (next->link == NULL) {
		next->link = (LISTREC*)malloc(sizeof(LISTREC));
		next->link->info=newentry;
		next->link->link = NULL;
		++i;
		printf("\n Created node at %d",i);	
	}

	return liststart;
}
