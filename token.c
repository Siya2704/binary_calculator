#include"function.h"

//list elements are stored as characters
token gettoken(list E, oprnd *s1, oprator *s2) {
	node *p = E;
	token t, t1;
	static int currentstate = start;
	char c = p->data;
	while(1) {
		c = p->data;
		switch(currentstate) {
			case start:
				if(isdigit(c)) {
					list n1;
					init(&n1);
					insert_beg(&n1, c - '0');
					push_oprnd(s1, n1);
					currentstate = digit;
					t.type = digit;
					return t;
				}
				else if(c == ' ' || c == '\t') {
					t.type = space;
					currentstate = space;
					return t;
				}
				/*else if(c == '(') {
					currentstate = left;
					t.type = left;
					t.value.op = c;
					return t;
				}*/
				else {
					currentstate = error;
					t.type = error;
					return t;
				}
				break;

			case digit:
				if(c == ' ' || c == '\t') {
					t1 = t;
					t.type = space;
					currentstate = space;
					return t1;
				}
				else if(isdigit(c)) {
					list n1 = pop_oprnd(s1);
					insert_beg(&n1, c - '0');
					push_oprnd(s1, n1);
					currentstate = digit;
					t.type = digit;
					return t;
				}
				else if(c == ')') {
					currentstate = right;
					t.type = right;
					t.value.op = c;
					return t;
				}
				else {
					currentstate = error;
					t.type = error;
					return t;
				}
				break;
				
			case operator:
				if(c == ' ' || c == '\t') {
					t1 = t;
					t.type = space;
					currentstate = space;
					return t1;
				}
				else {
					currentstate = error;
					t.type = error;
					return t;
				}
				break;
				
			case space:
				if(isdigit(c)) {
					list n1;
					init(&n1);
					insert_beg(&n1, c - '0');
					push_oprnd(s1, n1);
					currentstate = digit;
					t.type = digit;
					return t;
				}
				else if(c == '+' || c == '-' || c == '*'|| c == '/' || c == '%' || c == '^') {
					push_oprator(s2, c);
					currentstate = operator;
					t.type = operator;
					t.value.op = c;
					return t;
				}
				else if(c == '(') {
					currentstate = left;
					t.value.op = c;
					t.type = left;
					return t;
				}
				else if(c == ')') {
					currentstate = right;
					t.type = right;
					t.value.op = c;
					return t;
				}
				else if(c == ' ' || c == '\t') {
					t.type = space;
					currentstate = space;
					return t;
				}
				else {
					currentstate = error;
					t.type = error;
					return t;
				}
				break;
			
			case left:
				if(c == ' ' || c == '\t') {
					t1 = t;
					t.type = left;
					currentstate = left;
					pop_oprator(s2);
					return t1;
				}
				else if(isdigit(c)) {
					list n1;
					init(&n1);
					insert_beg(&n1, c - '0');
					push_oprnd(s1, n1);
					currentstate = digit;
					t.type = digit;
					return t;
				}
				else {
					currentstate = error;
					t.type = error;
					return t;
				}
				break;
			
			case right:
				if(c == ' ' || c == '\t') {
					t1 = t;
					t.type = right;
					currentstate = right;
					return t1;
				}
				else {
					currentstate = error;
					t.type = error;
					return t;
				}
				break;
				
			case error:
				t.type = error;
				printf("ERROR\n");
				exit (0);
		}
		
	}
}




