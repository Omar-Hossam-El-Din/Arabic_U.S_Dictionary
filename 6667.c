#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

// NAME : OMAR HOSSAM ELDIN EBRAHEEM
// ID : 6667

typedef struct
{
    char word[100];
} string;

typedef struct
{
    string * data;
    struct node *left;
    struct node*right;
} node;


node * newNode(string *val)
{
    node* n=malloc(sizeof(node));
    strcpy(n->data->word,val->word);
    n->left=NULL;
    n->right=NULL;
    return n;
}

void PreOrderTraverse(node *t)
{
    if (t!=NULL)
    {
        printf("%s ",t->data->word);
        PreOrderTraverse(t->left);
        PreOrderTraverse(t->right);
    }
}

void InOrdertraverse(node *t)
{
    if (t!=NULL)
    {
        InOrdertraverse(t->left);
        printf("%s ",t->data->word);
        InOrdertraverse(t->right);
    }
}

void PostOrdertraverse(node *t)
{
    if (t!=NULL)
    {
        PostOrdertraverse(t->left);
        PostOrdertraverse(t->right);
        printf("%s ",t->data->word);
    }
}

node* insert(node* node, string* key, int count)
{
    /* If the tree is empty, return a new node */
    int i;
    for ( i=0;i<count;i++)
    {
    if (node == NULL)
        return newNode(key->word);
    if (strcasecmp(key->word , node->data->word)==-1)
        node->left  = insert(node->left, key[i].word,count);
    else if (key > node->data)
        node->right = insert(node->right, key[i].word,count);
    }
    return node;
}

// RECURSIVE SEARCH
node* searchRecursive(node *t,string val)
{
    if (t==NULL)
        return NULL;
    if (strcasecmp(t->data->word,val.word)==0)
        return t;
    else if(strcasecmp(val.word ,t->data->word)==-1)
        return searchRecursive(t->left,val);
    else
        return searchRecursive(t->right,val);
}

// ITERATIVe SEARCH
node* search( node *t, string val)
{
    while (t!=NULL)
    {
        if (strcasecmp(val.word , t->data->word)==0)
            return t;
        else if (strcasecmp(val.word , t->data->word)==-1)
            t =t->left;
        else
            t = t->right;
    }
    return NULL;
}

int max(int a, int b)
{
    return a>b?a:b;
}

int height(node *root)
{
    if ( root == NULL)
        return -1;
    else
        return 1 + max(height(root->left), height(root->right));
}

int count(node *root)
{
    if ( root == NULL)
        return 0;
    else
        return  1 + count(root->left) + count(root->right);
}

void readFile( char * fileName)
{
    FILE*fp;
    fp=fopen(fileName,"r");
    if (fp==NULL)
        printf("The File Not Exist\n");
    string *arr = ( string *) malloc(100000000000000000000);
    int i,count=0;
    char line[5000];
    while( !feof(fp))
    {
        count++;
        fgets(line,5000,fp);
    }
    puts("-------------------------------------------");
    printf("Number of Lines : %d\n",count);
    fseek(fp,0,0);
    for (i=0; i<count; i++)
    {
        fgets(arr[i].word,5000,fp);
    }
    fclose(fp);
    printFile(arr,count);

}

void printFile(string*arr,int count)
{
    int i;
    for(i=0; i<count; i++)
    {
        printf("%s",arr[i].word);
    }
    puts("\n-------------------------------------------");

}

int main()
{
    char filename[261];
    puts("Enter file name or Ctrl+Z to exit:");
    puts("-------------------------------------------");
    while(fgets(filename, 260, stdin) != NULL)
    {
        filename[strlen(filename)-1]='\0';
        if(fopen(filename,"r"))
            readFile(filename);
        else
        {
            puts("File Not Found!");
            puts("----------------------------------------");
        }
        puts("\nEnter file name or Ctrl+Z to exit:\n");
        puts("----------------------------------------");
    }
}
