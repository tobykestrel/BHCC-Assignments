

//queue

#include <stdio.h>
#include <alloc.h> //malloc.h   stdlib.h
#include <ctype.h>
#include <conio.h>

struct entry
        {
	char name[81];
        } part;

typedef struct LISTREC
        {
        struct entry info;
	struct LISTREC * link;
	}  LISTREC;


LISTREC *next;

LISTREC *top , *purgequeue(), *ne, *p, *last;
void push(), pop();
void printqueue();
void loadfile();
void countqueue();
void menu();
void listdelete();


FILE *stream1,*stream2;
void savequeue();


void main()

{
        char selection;
        top = NULL;


        stream1 = fopen("data.bin","r+b");


        /* initialize */
    loadfile();

        clrscr();

        for (;;) {
        menu ();
        selection = getche();
	switch (toupper(selection))
	{
	    case '1' : push();clrscr() ; break;
	    case '2' : pop(); clrscr() ; break;
	    case '3' : printqueue(top) ; clrscr() ; break;
	    case '4' : loadfile() ; clrscr() ; break;
	    case '5' : savequeue() ; clrscr(); break;
	    case '6' : countqueue() ; clrscr(); break;
	    case '7' : top = purgequeue(top) ; clrscr(); break;
		case '8' : listdelete() ; clrscr(); break;
	    case 'Q' : clrscr() ; return ;break;
	      }  /*  switch  */

              }  /* for  */

} /* main */


void push()
{
clrscr();
gotoxy(10,12);
printf("\n name to add ");
scanf(" %[^\n]",part.name);
ne=(LISTREC *) malloc(sizeof(LISTREC));
ne->info=part;
ne->link=NULL;




	if (! top) top=last=ne;
	else { last->link=ne; last=ne; }



//ne->link=top;
//top=ne;


}//push


void printqueue(LISTREC *top)
	{
	clrscr() ;
	printf ("\n\n");

	while (top){

	 printf("\n %s ", top->info.name);
                top = top->link;
                } /* while */
                gotoxy(52,25) ; printf("Press Any Key to Continue") ; getch();
	} /* printqueue */


void pop ()
        {

        clrscr();
        gotoxy(10,12);
	if (! top) { printf("\n\a the queue is empty !!!"); getch(); return;}
        p=top;
        top=top->link;
	printf("\n %s",p->info.name);
        getch();
        free(p);
        }  /* pop  */

void loadfile ()
        {
        int n;
        rewind(stream1);
        for(;;) {
        n=fread(&part,sizeof(part),1, stream1);
        if (!n) break;
        ne=(LISTREC *) malloc(sizeof(LISTREC));
        ne->info=part; ne->link=NULL;


        if (! top) top=last=ne;
        else { last->link=ne; last=ne; }



        }//for
        }//loadfile

void savequeue ()
        {
		       stream2 = fopen("output.bin","w+b");
		       p = top;
		       while (p)
		       {

		    fwrite(&p->info,sizeof(part),1,stream2);

		// fprintf(stream2,"\n %s",p->info.name);
                       p=p->link;
                       }
		      fclose(stream2);
        }
		

void countqueue ()
        {
                       int i = 0;
                       p = top;
		       while (p)
		       {
		       i++;
		       p=p->link;
                       }
                       clrscr() ; gotoxy(27,12) ;
		       printf("Total Items in queue - %d",i);
                       gotoxy(52,25) ; printf("Press Any Key to Continue");
                       getch();
        }




void menu ()
        {
        gotoxy(30,1)  ; printf("NORTHEASTERN UNIVERSITY");
        gotoxy(32,2)  ; printf ("University College");
        gotoxy(37,3)  ; printf ("MIS 4277");
	gotoxy(19,9)  ; printf (" 1 - Add an Item to the queue		 ");
	gotoxy(19,10) ; printf (" 2 - Delete an Item from the queue	    ");
	gotoxy(19,11) ; printf (" 3 - List the queue from Top to Bottom        ");
	gotoxy(19,12) ; printf (" 4 - Load File to Current queue  ");
	gotoxy(19,13) ; printf (" 5 - Save Current queue in File OUTPUT.BIN ");
	gotoxy(19,14) ; printf (" 6 - Count Number of Items in queue	   ");
	gotoxy(19,15) ; printf (" 7 - Purge the Entire queue		   ");
	gotoxy(19,16) ; printf (" 8 - Delete from any location in the Queue		   ");
	
        gotoxy(19,17) ; printf (" Q - End the program                          ");
        gotoxy(25,22) ; printf ("Please enter your selection - ");
        }


LISTREC *purgequeue (LISTREC *top)

        {
                p = top;
                while (p)
                {
                top = top->link;
                if (p == last) free(last);
				free(p);
                p=top;
                } /* while */
		clrscr() ; gotoxy(27,12) ; printf("queue has been Purged");
                gotoxy(52,25) ; printf("Press Any Key to Continue -") ; getch();
                return (top);
	} /* purgequeue */
	



void listdelete()
{

int i=0;//FLAG FOR TRUE OR FALSE!!!!FOR THE TOP ITEM BEING DELETED!!!!
LISTREC *last,*next;


clrscr();

gotoxy(10,12);
printf("\n name to delete ");
scanf(" %[^\n]",part.name);

                //LISTREC *last,*next; // Can't do this in the language C
 
if (top == NULL)
{
	clrscr();
    gotoxy(10,12);
	printf("\n\a  The Queue is EMPTY!!! ");
	getch();
	return;
}

next = top;

 if ((strcmp(part.name,next->info.name) == 0) && (i==0))   /*if both are same*/
{

//i = 1;

top = top->link;

free(next);

             
 
 return;

}

next = top;

while ((strcmp(part.name,next->info.name)!=0) && (next->link != NULL))
 {
	last = next;
	next = next->link;
	        
 }  /*end while*/

    

	if ((strcmp(part.name,next->info.name)==0))
	{	

    last->link=next->link;   
	free(next);
	return;
	}
	
	if ((strcmp(part.name,next->info.name) != 0))
	{	
clrscr();

gotoxy(10,12);
	
printf("\n\a %s not found \n",part.name);

getch();

	return;	
	}
	
 }   /* end function listdelete*/	
	
	