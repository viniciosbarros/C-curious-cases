/*

	Vinicios Barros
vinicios.ec@gmail.com
		2013

Esse código não executa nada realmente útil e
tem a finalidade apenas de mostrar alguns casos
de uso incomuns em C. E de uma maneira universal 
utiliza várias tecnicas, e usos da linguagem C
que normalmente são incomuns e podem até chegar
a serem utéis.


This is not a typical approach of use of C 
language the target here is take some useful 
(or not useful at all) tricks that C language
can reveal. Some cases can be regular code 
even find in gnu/linux kernel, or posix codes
but the enthrall here is to demonstrate 
illustrate and explain this cases.
by the way, sorry for lame english all along 
the text :D 
Any doubt or suggestion just call me.

*/

  
#include "stdio.h"	/* will try locally then will 
				try to find in standard directory */
#include "stdlib.h"	
#include "string.h"	
#include <time.h>	/* will try just in the 
					standard derectory of libs */

/* Macro Definitions */
#define INCREMENT(x) ++x
#define MULTIPLY(a, b) a*b
#define merge(a, b) a##b   /* [3:cn] concatenated 
							using Token-Pasting */
#define PRINT(i, limit) while (i < limit)       \
                        {                       \
                            printf("macro\n");  \
                            i++;                \
                        }

struct nible {

	unsigned char nible: 4;	/* just 4 bits wide */
};

/* [2:pf] Case where you have a function pointer */
typedef int (*t_somefunc)(int,int);


int product(int u, int v) {
  return u*v;
}

int division(int u, int v) {
  return u/v;
}
/* end [2:pf] */

int main(int argc, char *argv[]) {


int const *a;	/* a pointer to a constant variable 
				can change the address but not the 
				value of a */
int *const b;	/* a constante pointer to a variable 
				can change value of 'b' but not the 
				address */
int val1 = 1, 
	val2 = 2,
	x 	 = 10,
	i 	 = 0;

/* [2:pf] Case where you have a function pointer */
t_somefunc area = &product;
	
	/* curious as hell, this line below do the addition 
	between value of val1 and val2 */
	printf("%d\n",printf("%*s%*s",val1,"",val2,""));
	/* this was so charmin at all :P */

	printf("INCREMENT: %d\n", INCREMENT(x));	
	/* uses the macro over there ^ */

	printf("MULTIPLY: %d\n", MULTIPLY((4+2), (3+3))); 
	
	printf("merge: %d\n", merge(12, 34));

	PRINT(i, 3);  /* uses the macro over there ^  */

	/* [2:pf] Case where you have a function pointer */
	int sideA, sideB;
	sideA = sideB = 50; /* rectangle in which two 
						adjacent sides have equal length */
	int x2 = (*area)(sideA, sideB); /* do the 
									operation to get the
									result of area */
	printf("function pointer result rectangle: %d\n",x2);
	area = &division;
	x2 = (*area)(x2, 2);
	printf("function pointer result area of triangle: %d\n",x2);
	/* end [2:pf] */

	/* [4:sz] unevaluation of expression */
	int num = 12;
  	int size = sizeof( ++num );
  	printf( "%d\n", num );
  	++num;
  	printf( "%d\n", num );
	/* end [4:sz] */

return 0;

}


/*

This is a (the) One file :) to explain (rule) some curious (or not so all) cases in C
below here I will try extend the illustration of the cases based in a indice that
could be found in the comments of the code above.

[2:pf] function pointer: using typedef improve the readability of such declarations
and the the syntax is appropriate to have a return value and parameters, 
thus the need to use more keywords and parentheses to write the 
function declaration. The readability 
may start to be really tricky with pointers to functions arrays, and some other 
even more indirect flavors. So typedef ease readability for pointers to functions.
And a function pointer stores the address of a function. This has nothing to do 
with the typedef construct which only ease the writing/reading of a program
the compiler just expands the typedef definition before compiling the actual code.

[3:cn] This is called token pasting or token concatenation. 
The ‘##’ preprocessing operator performs token pasting. 
When a macro is expanded, the two tokens on either side 
of each ‘##’ operator are combined into a single token
which then replaces the ‘##’ and the two original tokens
in the macro expansion. It is also possible to concatenate
two numbers (or a number and a name, such as 1.5 and e3)
into a number. Also, multi-character operators such as += can
be formed by token pasting. (sic)

[4:sz] The expression used in a sizeof operator is an unevaluated expression 
in C and C++. This can make for some surprising situations if you are unaware 
of it. The code will print 12 instead of 13 because 
the expression ++a is unevaluated.
So what does it mean for an expression to be unevaluated? Basically, it means
that the expression is used at compile time only as a way to determine a 
type, which is then used to evaluate the result of the sizeof operator. 
In the example, a’s type is determined, and the resulting 
type for ++ is determined, but no code is generated to execute the ++.


------------------------------------
References:
[2:pf] - http://goo.gl/VXnaat
[3:cn] - http://goo.gl/7JFt1t
[4:sz] - http://goo.gl/XeQ98O
------------------------------------
*/
