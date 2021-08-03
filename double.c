#include "function.h"

void init(list *l) {
	*l = NULL;
	return;
}

int isempty(list l) {
    if(l == NULL)
        return 1;
    else
        return 0;
}

void append(list *l, int d) {
	node *newnode, *p = *l;
	newnode = (node*)malloc(sizeof(node));
	if(newnode) {
		newnode -> data = d;
		newnode -> prev = NULL;
		newnode -> next = NULL;
	}
	else return;
	//if list is empty
	if(*l == NULL) {
		*l = newnode;
		return;
	}
	//traversing and appending
	while(p -> next) {
		p = p -> next;
	}
	p -> next = newnode;
	newnode -> prev = p;
	return;
}
//printing in reverse order bcz i have stored number in reverse order
void traverse(list l) {
	remove_zeros(l);
	node *p = l;
	while(p && p->next) {
		p = p->next;
	}
	while(p) {
		printf("%d", p->data);
		p = p->prev;
	}
	return;
}
/*
void traverse(list l) {
	node *p = l;
	while(p) {
		printf("%d", p->data);
		p = p->next;
	}
	return;
}
*/
void ctraverse(list l) {
	node *p = l;
	while(p) {
		printf("%c", p->data);
		p = p->next;
	}
	return;
}

void reverse(list *l) {
	node *p = *l, *q = NULL;
	if(*l == NULL || p->next == NULL) {
		return;
	}
	//should have more than one nodes
	while(p) {
		q = p->prev;
		p->prev = p->next;
		p->next = q;
		p = p->prev;
	}
	*l = q->prev;
	return;
}

void pop_First(list *l) {
	node *p = *l;
	if(*l == NULL){
		return;
	}
	*l = p -> next;
	p -> next -> prev = NULL;
	free(p);
	return;
}

void pop_Last(list *l) {
	node *p = *l;
	while(p->next) {
		p = p->next;
	}
	p->prev->next = NULL;
	free(p);
	return;
}

void Remove(list *l, int d) {
	node *p = *l;
	//if list is empty 
	if (*l == NULL) {
		return;
	}
	while(p && p->data != d) {
		p = p->next;
	}
	//if first element
	if(p && p == *l) {
		*l = p->next;
		p -> next -> prev = NULL;
		free(p);
		return;
	}
	if(p) {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		return;
	}
	return;
}

int len(list l) {
	node *p = l;
	int count = 0;
	while(p) {
		count ++;
		p = p->next;
	}
	return count;
}

int search(list l, int d) {
	node *p = l;
	int flag = 0;
	while(p) {
		if(p->data == d) {
			flag = 1;
		}
		p = p->next;
	}
	return flag;	
}

void insert_beg(list *l, int d) {
	node *newnode;
	node *p = *l;
	newnode = (node*)malloc(sizeof(node));
	if(newnode) {
		newnode -> data = d;
		newnode -> prev = NULL;
		newnode -> next = NULL;
	}
	else return;
	if(*l == NULL) {
		*l = newnode;
		return;
	}
	newnode -> next = *l;
	p ->prev = newnode;
	*l = newnode;
	return;
}
void insert_At(list *l, int i, int d) {
	if(i == 0) {
		insert_beg(l, d);
		return;
	}
	if(i >= len(*l)) {
		append(l, d);
		return;
	}
	node *p = *l;
	node *newnode;
	newnode = (node*)malloc(sizeof(node));
	if(newnode) {
		newnode -> data = d;
		newnode -> prev = NULL;
		newnode -> next = NULL;
	}
	int j = 0;
	while(j <= i - 1) {
		p = p->next;
		j++;
	}
	p->prev->next = newnode;
	newnode->prev = p->prev;
	p->prev = newnode;
	newnode->next = p;
	return;
}

void destroy(list *l) {
	node *p = *l, *q = NULL;
	while(p) {
		q = p;
		p = p->next;
		free(q);
	}
	*l = NULL;
	return;
}


	





