#include"function.h"
#include<time.h>

///////////current date and time///////////////////
int date(){
	time_t now;
	struct tm *timeinfo;
	time(&now);
	timeinfo = localtime(&now);
	printf ("\t\t\t\ttime and date: %s\n", asctime(timeinfo));
	return 0;
}
//////////////readline input//////////////////
list readline() {
	list L1;
	init(&L1);
	char ch;
	while((ch = getchar()) != '\n') {
		append(&L1, ch);
	}
	return (L1);
	//while printing use %c//
}


///////////////////get number/////////////////////
list get_number() {
	list L1;
	init(&L1);
	int ch;
	while((ch = getchar()) != '\n') {
		insert_beg(&L1, ch-'0');
	}
	reverse(&L1);
	node *p = L1;
	//removes zeros
	while(p && p->data == 0 && len(L1) > 1) {//we included len(L1) > 1 bcz the number can be zero
		pop_First(&L1);
		p = p->next;
	}
	reverse(&L1);
	return (L1);
}
list remove_zeros(list N1) {
	reverse(&N1);
	node *x = N1;
	//removes zeros
	while(x && x->data == 0 && len(N1) > 1) {//we included len(L1) > 1 bcz the number can be zero
		pop_First(&N1);
		x = x->next;
	}
	reverse(&N1);
	return N1;
}
	
int compare(list N1, list N2) {
	/////////////////////////////////
	//i have included this part to ensure that extra zeros are removed 
	//(in division code i am comparing with subtraction result so it removes zeros)
	remove_zeros(N1);
	remove_zeros(N2);
	///////////////////////////
	if(len(N1) > len(N2))
		return 1;
	else if(len(N1) < len(N2))
		return 2;
	else {
		reverse(&N1);
		reverse(&N2);
		node *p = N1, *q = N2;
		while(p && q) {
			if(p->data > q->data) {
				reverse(&N1);
				reverse(&N2);
				return 1;
			}
			if(p->data < q->data) {
				reverse(&N1);
				reverse(&N2);
				return 2;
			}
			p = p->next;
			q = q->next;
		}
		reverse(&N1);
		reverse(&N2);
		return 3;
	}	
}

////////////////////////////addition of number///////////////////////
list add_number(list N1, list N2) {
	list L1;
	init(&L1);
	int sum = 0, carry = 0;
	node *p = N1, *q = N2;
	while(p && q) {
		sum = p->data + q->data + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert_beg(&L1, sum);
		p = p->next;
		q = q->next;
	}
	while(p) {
		sum = p->data + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert_beg(&L1, sum);
		p = p->next;
	}
	while(q) {
		sum = q->data + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert_beg(&L1, sum);
		q = q->next;
	}
	if(!p && !q && carry != 0) {
		insert_beg(&L1, carry);
	}
	reverse(&L1);
	remove_zeros(L1);
	return L1;
}

//////////////////////subtraction of number////////////////////////
list subtract_number(list N1, list N2) {
	//assuming that user does subtraction from larger number
	if(compare(N1, N2) == 2) {
		printf("\nERROR:subtraction from smaller number");
		exit (0);
	}
	list L1;
	init(&L1);
	int diff = 0;
	node *p = N1, *q = N2;
	while(p && q) {
		if(p->data < q->data) {
			p->next->data -= 1;
			p->data += 10;
		}
		diff = p->data - q->data;
		insert_beg(&L1, diff);
		p = p->next;
		q = q->next;
	}
	while(p) {
		if(p->data < 0) {//if two carry required e.g. 100-3
			p->next->data -= 1;
			p->data += 10;
		}
		diff = p->data;
		insert_beg(&L1, diff);
		p = p->next;
	}
	reverse(&L1);
	remove_zeros(L1);
	return L1;
}	

//////////////////////multiplication of  number////////////////////////////
list mul_number(list N1, list N2) {
	list M;
	init(&M);
	append(&M, 0);
	int i, count = 0;//stores number of digits of second number
	node *q = N2;
	while(q) {
		list L1;
		init(&L1);
		node *p = N1;
		int carry = 0, mul;
		for(i = 0; i < count; i++) {
			insert_beg(&L1, 0);
		}
		while(p) {
			mul = p->data * q->data + carry;
			insert_beg(&L1, mul % 10);
			carry = mul / 10;
			p = p->next;
		}
		//if carry is remaining from last multiplication
		if(carry > 0) {
			insert_beg(&L1, carry);
		}
		reverse(&L1);
		M = add_number(M, L1);
		destroy(&L1);
		count++;
		q = q->next;
	}
	remove_zeros(M);
	return M;
}

//////////////////////subfloor division of  number////////////////////////////
//using subtraction
list subfloordivision_number(list N1, list N2) {
	list L1, count;
	init(&L1);
	init(&count);
	reverse(&N1);
	reverse(&N2);
	node *p = N1, *q = N2;
	reverse(&N1);
	reverse(&N2);
	append(&count, 0);// count is initially 0
	append(&L1, 1); // for adding 1 to count;
	int a = compare(N1 ,N2);
	if(q->data == 0) {
		printf("\nZero division error");
		exit(0);
	} 
	while(a == 1) {
		count = add_number(count, L1);
		N1 = subtract_number(N1, N2);
		a = compare(N1 ,N2);
	}
	if(a == 3) {
		count = add_number(count, L1);
		return count;
	}
	if(a == 2) {
		return count;
	}
	return count;
}

//////////////////////submodulo division of  number////////////////////////////
//using subtraction
list submodulodivision_number(list N1, list N2) {
	list count;
	init(&count);
	reverse(&N1);
	reverse(&N2);
	node *p = N1, *q = N2;
	reverse(&N1);
	reverse(&N2);
	insert_beg(&count, 0);// count is initially 0
	int a = compare(N1 ,N2);
	if(q->data == 0) {
		printf("\nZero division error");
		exit(0);
	}
	while(a == 1) {
		N1 = subtract_number(N1, N2);
		a = compare(N1 ,N2);
		//printf("%d",a);
	}
	if(a == 2) {
		return N1;
	} 
	if(a == 3) {
		return count;
	}
	return N1;
}

//////////////////////actual floor division of  number////////////////////////////
//using subfloordivision and submodulodivision
list floordivision_number(list N1, list N2) {
	list P, Q, temp;
	init(&P);
	init(&Q);
	init(&temp);
	reverse(&N1);
	reverse(&N2);
	node *p = N1;
	reverse(&N1);
	reverse(&N2);
	while(p) {
		insert_beg(&temp, p->data);
		int a = compare(temp, N2);
		while(a == 2 && p->prev){
			insert_beg(&Q, 0);
			p = p->prev;
			insert_beg(&temp, p->data);
			a = compare(temp, N2);
		}
		P = subfloordivision_number(temp, N2);
		temp = submodulodivision_number(temp, N2);
		node *x = P;
		while(x) {
			insert_beg(&Q, x->data);
			x = x->next;
		}
		p = p->prev;
	}
	return Q;
}

//////////////////////actual modulo division of  number////////////////////////////
//using subfloordivision and submodulodivision
list modulodivision_number(list N1, list N2) {
	list P, Q, temp;
	init(&P);
	init(&Q);
	init(&temp);
	reverse(&N1);
	reverse(&N2);
	node *p = N1;
	reverse(&N1);
	reverse(&N2);
	while(p) {
		insert_beg(&temp, p->data);
		int a = compare(temp, N2);
		while(a == 2 && p->prev){
			insert_beg(&Q, 0);
			p = p->prev;
			insert_beg(&temp, p->data);
			a = compare(temp, N2);
		}
		P = subfloordivision_number(temp, N2);
		temp = submodulodivision_number(temp, N2);
		node *x = P;
		while(x) {
			insert_beg(&Q, x->data);
			x = x->next;
		}
		p = p->prev;
	}
	return temp;
}
//////////////////////sub power of  number////////////////////////////
list subpower(list N1, list N2){
	list L1, P, zero;
	init(&P);
	init(&L1);
	init(&zero);
	append(&L1, 1);
	append(&P, 1);
	insert_beg(&zero, 0);
	if(compare(N2, zero) == 3) {// i.e. power is 0
		return P;
	}
	if(compare(N2, L1) == 3) { // i.e. power is 1
		return N1;
	}
	if(compare(N2, L1) != 3) {
		N2 = subtract_number(N2, L1);
		P = mul_number(N1, power(N1, N2));
	}
	return P; 
}

//////////////////////power of  number////////////////////////////
//using subpower
list power(list N1, list N2){
	list four;
	init(&four);
	append(&four, 4);
	//x^(m+n) = x^m * x^n  this will be useful for large calculations
	//we are dividing number into four parts if N2 is greater than 4
	if(compare(N2, four) != 2) {
		list two;
		init(&two);
		append(&two, 2);
		list A1, A2, A3, A4, Af, Am1, Am2;
		init(&A1); init(&A2); init(&A3); init(&A4);
		Af = floordivision_number(N2, two);
		Am1 = modulodivision_number(N2, two);
		A1 = add_number(A1, Af);
		A2 = add_number(Af, Am1);
		
		Af = floordivision_number(A1, two);
		Am2 = modulodivision_number(A1, two);
		A1 = add_number(Af, A3); //added A3 bcz it is 0
		A2 = add_number(Af, Am2);
		A3 = add_number(Af, A3);
		A4 = add_number(Af, Am1);
		
		A1 = subpower(N1, A1);
		A2 = subpower(N1, A2);
		A3 = subpower(N1, A3);
		A4 = subpower(N1, A4);
		
		A1 = mul_number(A1, A2);
		A2 = mul_number(A3, A4);
		A1 = mul_number(A1, A2);
		return A1;
	}
	else {
		return (subpower(N1, N2));
	}
}

list exponent(list N2) {
//returns result without decimal
	list N1;
	init(&N1);
	int i;
	char e[] = "2718281828459045";
	for(i = 0; i < 16; i++) {
		insert_beg(&N1, e[i]-'0');
	}
	return (power(N1, N2));
}

list fact(list N1) {
	list L1, P, zero;
	init(&P);
	init(&L1);
	init(&zero);
	//append(&L1, 1);
	append(&P, 1);
	insert_beg(&zero, 0);
	if(compare(N1, zero) == 3) {// i.e. number is 0
		return P;
	}
	L1 = mul_number(N1, fact(subtract_number(N1, P)));
	return L1;
}

list sqroot(list N1) {  //5 digits works fine otherwise takes more time
	//NEWTON RAPHSON METHOD
	list L1, two, count, one;
	init(&count);
	init(&L1);
	init(&one);
	init(&two);
	append(&one, 1);
	append(&two, 2);
	append(&count, 1);
	L1 = floordivision_number(add_number(N1, one), two);
	while(compare(count , N1) != 3) {
		L1 = floordivision_number(add_number(L1, floordivision_number(N1, L1)), two);
		count = add_number(count, one);
	}
	return L1;
}

float sine(list N) {
	float rad, sine = 0;
	int j, sign = 1, n = 0;
	node *p = N;
	while(p && p->next) {
		p = p->next;
	}
	while(p) {
		n = n * 10 + p->data;
		p = p->prev;
	}
	n = n % 360;
	if(n > 180 && n <= 360) {
		n = n % 180;
		sign *= -1;
	}
	if(n > 90 && n <= 180) {
		n = n % 90;
		n = 90 - n;
	}
	if(n == 90) {
		return 1;
	}
	rad =  n * 3.14159 / 180;
	for(j = 1; j <= 30; j = j + 2) {
		sine += (pow(rad, j) / fact_int(j)) * sign;
		sign *= -1;	
	} 
	return sine;
}

float cosine(list N) {
	float rad, cos = 0;
	int j, sign = 1, n = 0;
	node *p = N;
	while(p && p->next) {
		p = p->next;
	}
	while(p) {
		n = n * 10 + p->data;
		p = p->prev;
	}
	n = n % 360;
	if((n > 90 && n <= 180)) {
		n = n % 90;
		n = 90 - n;
		sign *= -1;
	}
	if((n > 180 && n <= 270)) {
		n = n % 180;
		sign *= -1;
	}
	if(n > 270 && n <= 360) {
		n = n % 90;
		n = 90 - n;
	}
	if(n == 90) {
		return 0;
	}
	rad =  n * 3.14159 / 180;
	for(j = 0; j <= 30; j = j + 2) {
		cos += (pow(rad, j) / fact_int(j)) * sign;
		sign *= -1;	
	} 
	return cos;
}

float ln(list N) {
	float n = 0;
	double ln = 0;
	int j, sign = 1;
	node *p = N;
	while(p && p->next) {
		p = p->next;
	}
	while(p) {
		n = n * 10 + p->data;
		p = p->prev;
	}
	
	ln = log(n);
	/*
	for(j = 1; j <= 2; j++) {
		log += (pow(n, j) / j) * sign;
		sign *= -1;	
	} */
	return ln;
}


int fact_int(int n) {
	int i, f = 1;
		if(n == 0) {
			f = 1;
		}
		else {
			for(i = 1; i <= n; i++) {
			f *= i;
			}
		}
	return f;
}
/*
list sine(list N){
	list L1, P, sine, increment, check, sine2;
	//check contains 100
	init(&check);
	init(&P);
	init(&L1);
	init(&sine);
	init(&sine2); //contains point also
	init(&increment);
	append(&P, 1);
	append(&sine, 0);
	append(&increment, 4);
	
	append(&check, 1);
	append(&check, 0);
	if(compare(N, sine) == 3) {
		return sine;
	}
	int i;
	char rad[9] = "174532925";  //value of pi/180
	//point after 10 digit
	for(i = 0; i < 9; i++) {
		append(&L1, rad[i] - '0');
	}
	N = mul_number(N, L1);  //converted to radian
	//first add all positive terms
	while(compare(P, check) != 3) {
		sine = add_number(sine, floordivision_number(power(N, P), fact(P)));
		P = add_number(increment, P);
	}
	destroy(&P);
	init(&P);
	append(&P, 3);
	while(compare(P, check) != 3) {
		sine = subtract_number(sine, floordivision_number(power(N, P), fact(P)));
		P = add_number(increment, P);
	}
	return sine;
}
*/	
int precedence(char c){
    if(c == '+')
        return 10;
    else if(c == '-')
        return 10;
    else if(c == '*')
        return 20;
    else if(c == '/')
        return 20;
    else if(c == '%')
        return 20;
    else if(c == '^')
        return 30;
    else if(c == '(')
    	return 5;
    return 0;
}
list applyOp(list a, list b, char c) {
	list result;
	init(&result); 
    if(c == '+')
        result = add_number(a, b);
    else if(c == '-')
        result = subtract_number(a, b);
    else if(c == '*')
        result = mul_number(a, b);
    else if(c == '/')
        result = floordivision_number(a, b);
    else if(c == '%')
        result = modulodivision_number(a, b);
    else if(c == '^')
		result = power(a, b);	
    return result;
}


