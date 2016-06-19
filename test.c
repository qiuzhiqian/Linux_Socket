#include <stdio.h>
#include "exch.h"

int main()
{
	int input_int=0;
	unsigned char input[10];
	printf("Input key:\n");
	scanf("%s",&input);
	input_int=strtoint(input);
	printf("val=%d\n",input_int);
}