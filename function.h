#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAX 1000000

#define start 0
#define digit 1 
#define operator 2
#define space 3
#define error 4
#define left 5
#define right 6

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
}node;
typedef node* list;

typedef struct token {
	int type; // type takes values DIGIT/OPERATOR/STOP/ERROR/START
	union value{ 
		list N;
		char op;
	}value;
}token;

void init(list *l);
void append(list *l, int d);
void traverse(list l);
void ctraverse(list l);
void reverse(list *l);
void pop_First(list *l);
void pop_Last(list *l);
void Remove(list *l, int d);
int len(list l);
int search(list l, int d);
void insert_beg(list *l, int d);
void insert_At(list *l, int i, int d);
void destroy(list *l);

list readline();
int date();
list get_number();
list remove_zeros(list N1);
int compare(list N1, list N2);
list add_number(list N1, list N2);
list subtract_number(list N1, list N2);
list mul_number(list N1, list N2);
list subfloordivision_number(list N1, list N2);
list submodulodivision_number(list N1, list N2);
list floordivision_number(list N1, list N2);
list modulodivision_number(list N1, list N2);
list subpower(list N1, list N2);
list power(list N1, list N2);
list exponent(list N1);
list fact(list N);
list sqroot(list N1);
float sine(list N);
float cosine(list N);
float ln(list N);
////////////////////////////////
int fact_int(int n); //used in sine
int precedence(char c);
list applyOp(list a, list b, char c);

///////////using single linked list////////////////

//////////////operator stack////////////////
typedef struct oprator {
	char opr;
	struct oprator* next;	
}opratornode;

typedef opratornode* oprator;

void init_oprator(oprator *s);
int isEmpty_oprator(oprator s);
void push_oprator(oprator *s, char op);
char pop_oprator(oprator *s);
char peek_oprator(oprator s);
void print_oprator(oprator s);
void empty_oprator(oprator *s);

//////////////operand stack///////////////////
typedef struct oprnd{
	list num; //double linked list
	struct oprnd* next;	
}oprndnode;

typedef oprndnode* oprnd;
void init_oprnd(oprnd *s);
int isEmpty_oprnd(oprnd s);
void push_oprnd(oprnd *s, list num);
list pop_oprnd(oprnd *s);
list peek_oprnd(oprnd s);
void print_oprnd(oprnd s);
void empty_oprnd(oprnd *s);

token gettoken(list E, oprnd *s1, oprator *s2);
list infix(list L);


#endif
