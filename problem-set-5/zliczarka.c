#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 256

//Structures
//********************************************************************

struct node
{
   	char *data;
    int amount;
    struct node *left;
    struct node *right;
};

typedef struct node* Node;

//Functions declarations
//********************************************************************


//Function checks alphabetical relation between two words
// Returns:
// 0 if strings match
// 1 if first string is earlier in alphabetical order
// 2 if second string is earlier in alphabetical order

int isFirst(char* tab1, char* tab2);

//Function adds new words to binary tree structure

Node addTree(Node head, char* tab);

//Auxiliary function for above addTree()

Node NewNode(char* tab);

//Function clears content of char array

void clearArray(char* tab);

//Function checks if char array is a word (contain only letters)

int isGood(char* tab);

//Punctiuation marks deleter

void delPunc(char* tab);

//Sequence of functions related to conversion Binary Tree to Doubly Linked Tree

void join(Node a, Node b);

Node append(Node a, Node b);

Node treeToList(Node root);

//Function prints Doubly Linked Tree

void printList(Node root, int qty);

//Sequence of functions related to sorting Doubly Linked List by amount of occurrence of particular word

void _quickSort(Node l, Node h);

void quickSort(Node head);

Node lastNode(Node root);

Node partition(Node l, Node h);

void swapAmount(int* a, int* b);

void swapData(char** tab1, char** tab2);

//Function prints Binary Tree of words with specific amount of occurrences

void printTreeAm(Node noo, int amount);

//Function deallocates tree

void deleteTree(Node node);

//Function saves output of program into text file

void AlpOrdToFile(Node head, int quantity, char* output);


//Main function
//********************************************************************

int main(int argc, char *argv[])
{
   	if(argc<3||argc>4)
	{
		printf("Couldn't start program: Wrong parameters\nPlease type ./zliczanie.c <amount> <input> <output>\n");
		printf("<amount> - integer greater than 0\n<input_name> - input filename\n<output> - output filename\nFor more info please check documentation\n");
		return 0;
	}


	int quantity;
	char* input;
	char* output;

	if(argc==3)
	{
		quantity = 100;
		input = argv[1];
		output = argv[2];
	} else
	{
		sscanf(argv[1], "%d", &quantity);
		if(quantity==0)
		{
			printf("Couldn't start program: Wrong parameters\nPlease type ./zliczanie.c <amount> <input> <output>\n");
			printf("<amount> - integer greater than 0\n<input_name> - input filename\n<output> - output filename\nFor more info please check documentation\n");
			return 0;
		}
		input = argv[2];
		output = argv[3];
	}


	if(access(input, F_OK ) != -1 )
	{

	}
	else
	{
    	printf("Error: input file doesn't exist. Please provide good filename.\n");
		exit(0);
	}

	if(access(output, F_OK ) != -1 )
	{

		char yn='z';
		while(yn!='Y')
		{

		printf("File %s already exist. Do you want to overwrite? y/n\n", output);

		scanf("%c", &yn);

		yn = toupper(yn);
			if(yn=='N')
			{

				printf("Program aborted.\n");
				exit(0);

			}
		}

	}


    
	int ch = 0;

	char* ch_array = (char*)malloc(MAX_SIZE*sizeof(char));
	
	FILE *plik;

	plik = freopen(input, "r", stdout);

	int iter = 0;

	Node head = NULL;
 
    
    while(1)
    {
        ch = toupper(getc(plik));

        while(ch>=65&&ch<=90&&ch!=EOF)
        {
            ch_array[iter] = ch;
            ch = toupper(getc( plik ));
            iter++;
	}
        ch_array[iter]='\0';

        if(iter != 0)
        {
	    
            if(isGood(ch_array))
            {		
				head = addTree(head, ch_array);
            }


            iter = 0;

            clearArray(ch_array);

        }



        if(ch == EOF)
        {
            break;
        }
    }

    fclose(plik);

    head = treeToList(head);

    head->left->right = NULL;

    head->left = NULL;

    quickSort(head);

    AlpOrdToFile(head, quantity, output);



    return 0;
}



//Functions definitions
//********************************************************************

//Function checks alphabetical relation between two words

int isFirst(char* tab1, char* tab2)
{
    int iter = 0;

    while(tab1[iter]==tab2[iter]&&tab1[iter]!='\0')
    {
        iter++;
    }
    if(tab1[iter]=='\0'&&tab2[iter]=='\0')
    {
        return 0;
    }
    else if(tab1[iter]=='\0')
    {
        return 1;
    }
    else if(tab1[iter]<tab2[iter])
    {
        return 1;
    }
    else
    {
        return 2;
    }

}

//Function adds new words to binary tree structure

Node addTree(Node head, char* tab)
{


    if(head == NULL)
    {
        return NewNode(tab);

    }
    else if(isFirst(head->data, tab)==0)
    {
        head->amount+=1;
        return head;

    }
    else if(isFirst(head->data, tab)==1)
    {
        head->right = addTree(head->right, tab);
        return head;
    }
    else
    {
        head->left = addTree(head->left, tab);
        return head;
    }


}

//Auxiliary function for above addTree()

Node NewNode(char* tab)
{
    Node node = malloc(sizeof(struct node));

    char* word = malloc((strlen(tab)+1)*sizeof(char));
    
    strcpy(word, tab);
    
    /*
    while(iter!=strlen(tab)+1)
    {
        word[iter] = tab[iter];
        iter++;
    }

    word[iter]='\0';
    */
    node->data = word;
    node->amount = 1;
    node->left = NULL;
    node->right = NULL;

    return node;

}

//Function clears content of char array

void clearArray(char* tab)
{
    int iter = 0;

    while(tab[iter]!='\0')
    {
        tab[iter]='\0';
        iter++;
    }
}

//Function checks if char array is a word (contain only letters)

int isGood(char* tab)
{
    int iter = 0;
    
    int length = strlen(tab);
    
    while(iter<length)
    {	
        if(tab[iter]>90||tab[iter]<65)
        {
            return 0;
        }
        iter++;
    }
    return 1;
}


//Sequence of functions related to conversion Binary Tree to Doubly Linked Tree

void join(Node a, Node b)
{
    a->right = b;
    b->left = a;
}

Node append(Node a, Node b)
{
    Node aLast, bLast;
    if(a==NULL) return (b);
    if(b==NULL) return (a);

    aLast = a->left;
    bLast = b->left;

    join(aLast, b);
    join(bLast, a);

    return(a);
}

Node treeToList(Node root)
{
    Node aList, bList;

    if(root==NULL) return (NULL);

    aList = treeToList(root->left);
    bList = treeToList(root->right);

    root->left = root;
    root->right = root;

    aList = append(aList, root);
    aList = append(aList, bList);

    return (aList);
}

//Function prints Doubly Linked Tree

void printList(Node root, int qty)
{
    if(root==NULL) return;

    while(qty--)
    {
        if(root==NULL)
        {
            return;
        }
        printf("%6d %s\n", root->amount, root->data);
        root=root->right;
    }
}
//**************************SORTING**************************

//Sequence of functions related to sorting Doubly Linked List by amount of occurrence of particular word

//Auxiliary recursive quicksort function which sorts part of doubly linked list between two pointers provided as function argument

void _quickSort(Node l, Node h)
{

    if(h!=NULL && l!=h && l!=h->right)
    {
        Node p = partition(l, h);
        _quickSort(l, p->left);
        _quickSort(p->right, h);
    }
}

//Head function to quickSort doubly linked list provided as function parameter

void quickSort(Node head)
{

    Node h = lastNode(head);

    _quickSort(head, h);
}

//Core quicksort function which swaps content of two doubly linked list elements

Node partition(Node l, Node h)
{
    int x = h->amount;

    Node i = l->left;

    for(Node j = l; j!=h; j=j->right)
    {
        if(j->amount > x)
        {
            i = (i == NULL) ? l : i->right;

            swapAmount(&(i->amount), &(j->amount));
            swapData(&(i->data), &(j->data));
        }
    }
    i = (i == NULL) ? l : i->right;
    swapAmount(&(i->amount), &(h->amount));
    swapData(&(i->data), &(h->data));

    return i;
}

//Function which finds last element of doubly linked list provided as parameter

Node lastNode(Node root)
{
    while(root && root->right)
    {
        root = root ->right;
    }


    return root;
}

//Function which swaps values of two ints

void swapAmount(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//Function which swaps two char tables

void swapData(char** tab1, char** tab2)
{
    int tmp = (int)(*tab1);
    *tab1 = *tab2;
    *tab2 = (char*)tmp;
}

//**************************PRINTING OUTPUT TO FILE**************************

//Function prints Binary Tree of words with specific amount of occurrences

void printTreeAm(Node node, int amount)
{
    if (node == NULL) return;

    printTreeAm(node->left, amount);

    int iter = 0;
    printf("%6d ", amount);

    while(node->data[iter]!='\0')
    {
        printf("%c", node->data[iter]);
       	iter++;
    }

    printf("\n");

    printTreeAm(node->right, amount);
}

//Function deallocates tree

void deleteTree(Node node)
{
    if (node == NULL) return;

    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);

    /* then delete the node */

    free(node);
}

//Function saves output of program into text file

void AlpOrdToFile(Node head, int quantity, char* output)
{
    int amount = 0;

	//printf("File %s succesfully created in program folder.\n", output);

	FILE *fp;

	if((fp = freopen(output, "w", stdout)) == NULL)
	{
		printf("Error: Cannot open file.\n");
		exit(0);
	}

    while(head!=0)
    {

        amount = head->amount;
        Node tree = NULL;

        while(amount==head->amount)
        {
            if(quantity>0)
            {
                tree = addTree(tree, head->data);
            }
            quantity--;
            head=head->right;
            if(head==0) break;

        }

        printTreeAm(tree, amount);
        deleteTree(tree);

	}

	fclose(fp);



    return;
}


