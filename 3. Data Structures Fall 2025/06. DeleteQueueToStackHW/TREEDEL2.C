

//TREE

// TREEDEL
#define MAXWORDLENGTH 20
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "getline.inc"

struct entry {
char name[81];
};



struct entry part;



struct tnode {
char *name;
int record_number;
struct tnode *left;
struct tnode *right;
};;;;;;;// don't forget the ;;;;;;
void lookup(struct tnode *root,char *s);
void treeprint2(struct tnode *root,char *searchkey);

int c;

int n;
FILE *stream;

struct tnode *root, *tree(struct tnode *, char *, int),*dtree(struct tnode *, char *);

void main()
{

char searchkey[81];
char name[MAXWORDLENGTH];
int i=0;

root=NULL;

stream = fopen("data.bin","r+b");

for (;;) {
//printf("enter a name or 'exit' to quit.... ");
//getline(name,81);
//scanf(" %[^\n]",name);

n=fread(&part,sizeof(part),1,stream);
if(!n) break;

//if (stricmp(name,"exit")==0) break;


//root=tree(root,name,i++);

root = tree(root,part.name,i++);

}

treeprint(root);

for(;;){
printf("\n\n\t enter the name to delete or exit");
scanf(" %[^\n]",searchkey);
if(stricmp(searchkey,"exit")==0) break;
root=dtree(root,searchkey);
treeprint(root);
}

for(;;){
printf("\n\n\t enter the name to lookup or exit");
scanf(" %[^\n]",searchkey);
if(stricmp(searchkey,"exit")==0) break;
lookup(root,searchkey);
}
fclose(stream);
}//main




struct tnode *tree(struct tnode *p,char *w,int w2)

{
struct tnode *talloc();
char *strsave(char *);
int cond;
if (p== NULL) {
p=talloc();
p->name=strsave(w);
p->record_number=w2;
p->left=p->right=NULL;
} else if ((cond=stricmp(w,p->name)) ==0)
/*printf("\7 duplicate entry !!!!!! \n");*/
p->right=tree(p->right,w,w2);
else if (cond<0)
p->left=tree(p->left,w,w2);
else
p->right=tree(p->right,w,w2);

return(p); // this maps the new node back to the root!!!!
}// tree

treeprint(struct tnode *root)
{
if (root) {
treeprint(root->left);
printf("\n\n %s  %d",root->name,root->record_number);
treeprint(root->right);
}//if
}// treeprint

struct tnode *talloc()
{
return((struct tnode *) malloc(sizeof(struct tnode)));
}

char *strsave(char *s)
{
char *p;
if ((p=malloc(strlen(s)+1)) != NULL)
strcpy(p,s);
return(p);
}

struct tnode *dtree(struct tnode *root,char *searchkey)

{struct tnode *p,*p2;

if (root){
if (stricmp(root->name,searchkey)==0) {
if (root->left == root->right) {free(root);return(NULL);}  // the node is a leaf!!!

else if (root->left==NULL) {p=root->right;free(root);return(p);}

else if (root->right==NULL) {p=root->left;free(root);return(p);}
else {
p2=root->right;
p=root->right;
while(p->left) p=p->left;
p->left=root->left;
free(root);
return(p2);
}
}

if (stricmp(root->name,searchkey) < 0) root->right=dtree(root->right,searchkey);
else root->left=dtree(root->left,searchkey);
return(root);
}
else {printf("\n\n\t\a %s not found !!!\n\n",searchkey);return(NULL);}

}//treedel

void lookup(struct tnode *p,char *s)
{


if(!p)
 {printf("\n\a %s not found",s);return;}
else if (strncmpi(s,p->name,strlen(s))==0)
{
fseek(stream,p->record_number *sizeof(part),0);
fread(&part,sizeof(part),1,stream);
printf("\n %s    %d",part.name,p->record_number);
puts("\n (y) or (n)????");
fflush(stdin);
c = getchar();
fflush(stdin);
if(c!='y')
//lookup(p->right,s);
treeprint2(p->right,s);
}//else
else   if (strncmpi(s,p->name,strlen(s))<0)
lookup(p->left,s);
else lookup(p->right,s);

}//lookup


void treeprint2(struct tnode *root,char *searchkey)
{
if (root) {
treeprint2(root->left,searchkey);
if (strncmpi(searchkey,root->name,strlen(searchkey))==0) printf("\n\n %s  %d",root->name,root->record_number);
treeprint2(root->right,searchkey);
}//if
}// treeprint



