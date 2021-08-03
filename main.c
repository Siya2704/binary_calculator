#include"function.h"

int main() {
	//printing basic info.
	printf("\n\t\t\t\t   ======Mis_no.: 111903106=====\n\t\t\t\t   ======Binary Calculator======\n\t\t\t\t   ======Project 2020-2021======\n\t\t\t\t   =========NO WARRANTY=========\n\t\t\t\t  (use space to seperate tokens)\n\t\t\t\t   (evaluates INFIX expressions)\n\n");
	date();
	//////////////////////////////////////////////////////////
	//compare (cmp)											//
	//length (length)										//
	//squareroot (sqrt)										//
	//factorial (fact)										//
	//sine (s)												//
	//cosine (c)											//
	//logarithm (l)											//
	//exponential (exp)										//
	//														//
	//////////////////////////////////////////////////////////
	
	//storing data into file
	FILE *fm;
	fm = fopen("data.txt", "w");
	fclose(fm);
	
	while(1){
		list E = readline();
		node *p = E;
		fm = fopen("data.txt", "a");
		node *x = E;
		while(x) {
			fprintf(fm, "%c", x->data);
			x = x->next;
		}
		fprintf(fm, "\n");
		fclose(fm);
		/////////////////////////////////////////////
		//compare function
		if(p && (p->data == 'c' || p->data == 'C') && (p->next->data == 'm' || p->next->data == 'M') && (p->next->next->data == 'p' || p->next->next->data == 'P')) {
			char c;
			int cmp = 0;
			list N1, N2;
			init(&N1);
			init(&N2);
			while(p && !isdigit(p->data)) {
				p = p->next;
			}
			while(p && p->data != ' ' && p->data != ',') {
				c = p->data;
				insert_beg(&N1, c - '0');
				p = p->next;	
			}
			while(p && !isdigit(p->data)) {
				p = p->next;
			}
			while(p && p->data != ')') {
				c = p->data;
				insert_beg(&N2, c - '0');
				p = p->next;	
			}
			node *n1 = N1, *n2 = N2;
			if(!n1 || !n2) {
				printf("\nERROR\n");
				continue;
			}
			cmp = compare(N1, N2);
			if(cmp == 1)
				printf("number 1 is greater\n");
			else if(cmp == 2)
				printf("number 2 is greater\n");
			else if(cmp == 3)
				printf("numbers are equal\n");
			else if(cmp == 0)
				printf("ERROR\n");
			continue;
			
		}
		
		///////////////////////////////////////
		//length of expression
		else if(p && (p->data == 'l' || p->data == 'L') && (p->next->data == 'e' || p->next->data == 'E') && (p->next->next->data == 'n' || p->next->next->data == 'N') && (p->next->next->next->data == 'g' || p->next->next->next->data == 'G') && (p->next->next->next->next->data == 't' || p->next->next->next->next->data == 'T') && (p->next->next->next->next->next->data == 'h' || p->next->next->next->next->next->data == 'H')) {
			list N1;
			init(&N1);
			char c;
			while(p && !isdigit(p->data)) {
				p = p->next;
			}
			while(p && p->data != ')') {
				c = p->data;
				insert_beg(&N1, c - '0');
				p = p->next;	
			}
			node *n1 = N1;
			if(!n1) {
				printf("\nERROR\n");
				continue;
			}
			
			printf("length is : %d", len(N1));
			printf("\n");
			continue;
		}
	
		////////////////////////////////////////////////////////////
		//factorial 
		else if(p && (p->data == 'f' || p->data == 'F') && (p->next->data == 'a' || p->next->data == 'A') && (p->next->next->data == 'c' || p->next->next->data == 'C') && (p->next->next->next->data == 't' || p->next->next->next->data == 'T')) {
			list N1;
			init(&N1);
			char c;
			while(p && !isdigit(p->data)) {
				p = p->next;
			}
			while(p && p->data != ')') {
				c = p->data;
				insert_beg(&N1, c - '0');
				p = p->next;	
			}
			node *n1 = N1;
			if(!n1) {
				printf("\nERROR\n");
				continue;
			}
			N1 = fact(N1);
			printf("factorial is: ");
			traverse(N1);
			printf("\n");
			continue;
		}
		
		////////////////////////////////////////////////////////////
		//squareroot
		else if(p && (p->data == 's' || p->data == 'S') && (p->next->data == 'q' || p->next->data == 'Q') && (p->next->next->data == 'r' || p->next->next->data == 'R') && (p->next->next->next->data == 't' || p->next->next->next->data == 'T')) {
			list N1;
			init(&N1);
			char c;
			while(p && !isdigit(p->data)) {
				p = p->next;
			}
			while(p && p->data != ')') {
				c = p->data;
				insert_beg(&N1, c - '0');
				p = p->next;	
			}
			node *n1 = N1;
			if(!n1) {
				printf("\nERROR\n");
				continue;
			}
			N1 = sqroot(N1);
			printf("squareroot is: ");
			traverse(N1);
			printf("\n");
			continue;
		}
		
		////////////////////////////////////////////////////////////
		//sine of number 
		else if(p && (p->data == 's' || p->data == 'S')) {
			list N1;
			init(&N1);
			char c;
			while(p && !isdigit(p->data)) {
				p = p->next;
			}
			while(p && p->data != ')') {
				c = p->data;
				insert_beg(&N1, c - '0');
				p = p->next;	
			}
			node *n1 = N1;
			if(!n1) {
				printf("\nERROR\n");
				continue;
			}
			float S = sine(N1);
			printf("sine is: ");
			printf("%.3f", S);
			printf("\n");
			continue;
		}
		
		////////////////////////////////////////////////////////////
		//cosine of number 
		else if(p && (p->data == 'c' || p->data == 'C')) {
			list N1;
			init(&N1);
			char c;
			while(p && !isdigit(p->data)) {
				p = p->next;
			}
			while(p && p->data != ')') {
				c = p->data;
				insert_beg(&N1, c - '0');
				p = p->next;	
			}
			node *n1 = N1;
			if(!n1) {
				printf("\nERROR\n");
				continue;
			}
			float C = cosine(N1);
			printf("cos is: ");
			printf("%.3f", C);
			printf("\n");
			continue;
		}
		
		////////////////////////////////////////////////////////////
		//log of number 
		else if(p && (p->data == 'l' || p->data == 'L')) {
			list N1, zero;
			init(&N1);
			init(&zero);
			append(&zero, 0);
			char c;
			while(p && !isdigit(p->data)) {
				p = p->next;
			}
			while(p && p->data != ')') {
				c = p->data;
				insert_beg(&N1, c - '0');
				p = p->next;	
			}
			if(compare(N1, zero) == 3) {	// i.e. number is 0
				printf("ERROR: Not Defined\n");
				continue;
			}
			node *n1 = N1;
			if(!n1) {
				printf("\nERROR\n");
				continue;
			}
			
			float L = ln(N1);
			printf("log is: ");
			printf("%.3f", L);
			printf("\n");
			continue;
		}
		
		///////////////////////////////////////
		//exponent of expression
		else if(p && (p->data == 'e' || p->data == 'E')) {
			list N1;
			init(&N1);
			char c;
			while(p && !isdigit(p->data)) {
				p = p->next;
			}
			while(p && p->data != ')') {
				c = p->data;
				insert_beg(&N1, c - '0');
				p = p->next;	
			}
			node *n1 = N1;
			if(!n1) {
				printf("\nERROR\n");
				continue;
			}
			N1 = exponent(N1);
			printf("Result is: (without point)");
			traverse(N1);
			printf("\n");
			continue;
		}
			/*
			list L1;
			init(&L1);
			append(&L1, 1);
			list count;
			init(&count);
			append(&count, 1);
			append(&count, 5);
			if(compare(N1, L1) == 3) {
				printf("Result is: (without point)");
				traverse(L1);
				printf("\n");
				continue;
			}
		
			
			//to print point 
			list N2;
			init(&N2);
			node *q = N1;
			char ch[MAX];
			remove_zeros(N1);
			while(q && compare(q, mul_number(count, N1)) == 3) {
				sprintf(ch, "%d", q->data);
				insert_beg(&N2, ch[0]);
				//printf(" ");
				q = q->next;
			}
			append(&N2, '.');
			while(q) {
				sprintf(ch, "%d", q->data);
				insert_beg(&N2, ch[0]);
				q = q->next;
			}
			printf("Result is: ");
			ctraverse(N2);
			printf("\n");
			continue;
		}*/
		
		///////////////////////////////////////
		//INFIX evaluation
		//user enters something
		if(p) {
			list L = infix(E);
			printf("\nResult is: ");
			traverse(L);
			printf("\n");
		}	
	}
	return 0;
	
}

