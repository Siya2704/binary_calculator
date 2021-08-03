#include"function.h"

//////////////operator stack////////////////////////
void init_oprator(oprator *s){
    *s = NULL;
}

int isEmpty_oprator(oprator s) {
    if(s == NULL)
        return 1;
    else
        return 0;
}
void push_oprator(oprator *s, char opr){ //similar to append
    opratornode *newnode, *p = *s;
	newnode = (opratornode*)malloc(sizeof(opratornode));
	if(newnode) {
		newnode -> opr = opr;
		newnode -> next = NULL;
	}
	else return;
	//if list is empty
	if(*s == NULL) {
		*s = newnode;
		return;
	}
	//traversing and appending
	while(p -> next) {
		p = p -> next;
	}
	p -> next = newnode;
	return;
}

char pop_oprator(oprator *s){//similar to pop_last
    opratornode *p = *s;
    opratornode *q = NULL;
    char ch;
    if(*s == NULL) 
    	return;
	while(p->next) {
		q = p;
		p = p->next;
	}
	if(p == *s) {//if one node
    	ch = p->opr;
    	*s = p->next;
    	free(p);
		return ch;
    }
	q->next = NULL;
	ch = p->opr;
	free(p);
	return ch;

}

char peek_oprator(oprator s){
		opratornode *p = s;
		if(p == NULL)
    		return;
        while(p->next) {
        	p = p->next;
        }
        char ch = p->opr;
        return ch;
}

void print_oprator(oprator s){
	opratornode *p = s;
	while(p) {
		printf("%c  ", p->opr);
		p = p->next;
	}
	return;
}

void empty_oprator(oprator *s) {
	while(*s != NULL) {
		pop_oprator(s);
	}
	return;
}

/////////////operand stack////////////////////////

void init_oprnd(oprnd *s) {
	*s = NULL;
}

int isEmpty_oprnd(oprnd s) {
    if(s == NULL)
        return 1;
    else
        return 0;
}

void push_oprnd(oprnd *s, list N){
	oprndnode *newnode, *p = *s;
	newnode = (oprndnode*)malloc(sizeof(oprndnode));
	if(newnode) {
		newnode -> num = N;
		newnode -> next = NULL;
	}
	else return;
	//if list is empty
	if(*s == NULL) {
		*s = newnode;
		return;
	}
	//traversing and appending
	while(p -> next) {
		p = p -> next;
	}
	p -> next = newnode;
	return;
}

list pop_oprnd(oprnd *s) {
	oprndnode *p = *s;
    oprndnode *q = NULL;
    list N1;
    if(*s == NULL)//if empty
    	return;
	while(p->next) {
		q = p;
		p = p->next;
	}
	if(p == *s) {//if one node
    	N1 = p->num;
    	*s = p->next;
    	free(p);
		return N1;
    }
	q->next = NULL;
	N1 = p->num;
	free(p);
	return N1;
}

list peek_oprnd(oprnd s){
		oprndnode *p = s;
		if(p == NULL)
    		return;
        while(p->next) {
        	p = p->next;
        }
        list N1 = p->num;
        return N1;
}

void print_oprnd(oprnd s){
	oprndnode *p = s;
	while(p) {
		traverse(p->num);
		printf("  ");
		p = p->next;
	}
	return;
}

void empty_oprnd(oprnd *s) {
	while(*s != NULL) {
		pop_oprnd(s);
	}
	return;
}



