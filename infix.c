#include"function.h"

list infix(list E) {
	token t;
	node *p = E;
	//operand stack
	oprnd s1;
	init_oprnd(&s1);
	//operator stack
	oprator s2;
	init_oprator(&s2);
	int curr_state;
	char op;
	while(p) {
		t = gettoken(p, &s1, &s2);
		curr_state = t.type;
		if(curr_state == error) {
			printf("\nERROR\n");
			exit(0);
		}
		switch(curr_state) {
			case operator:
				op = t.value.op;
				pop_oprator(&s2);
				while(!isEmpty_oprator(s2) && precedence(peek_oprator(s2)) >= precedence(op)) {
					list n2 = pop_oprnd(&s1);
					list n1 = pop_oprnd(&s1);
					char op2 = pop_oprator(&s2);
					list R = applyOp(n1, n2, op2);
					push_oprnd(&s1, R);
				}
				push_oprator(&s2, op);  //works fine
				break;
				
			case left:
				push_oprator(&s2, op);
				break;
			
			case right:
				while(!isEmpty_oprator(s2) && peek_oprator(s2) != '(') {
					list n2 = pop_oprnd(&s1);
					list n1 = pop_oprnd(&s1);
					char op = pop_oprator(&s2);
					list R = applyOp(n1, n2, op);
					push_oprnd(&s1, R);
				}
				if(peek_oprator(s2) == '(')
					pop_oprator(&s2);
				break;
				
			default:
				exit;
				break;
		}
		p = p->next;
		printf(" ");
	}
	//if after operator list is empty
	if(!p && curr_state == 2) {
		printf("\nERROR\n");
		exit(0);
	}
	//stop case i.e. list is empty
	while(!isEmpty_oprator(s2)) {
		list n2 = pop_oprnd(&s1);
		list n1 = pop_oprnd(&s1);
		char op = pop_oprator(&s2);
		list R = applyOp(n1, n2, op);
		push_oprnd(&s1, R);
	}
	if(!isEmpty_oprnd(s1)) {
		list Num =  pop_oprnd(&s1);
		return Num;
	}
}
			
