#include <stdio.h>
#include "exch.h"

int strtoint(unsigned char *str)
{
	int val=0;
	while(*str)
	{
		//printf("val_raw=%x\n",*str);
		val=(int)val*10+asctohex(*str);
		//printf("tempval=%d\n",val);
		str++;
	}
	return val;
}

unsigned char asctohex(unsigned char asc)
{
	unsigned char hex=0;
	if(asc>=0x30&&asc<=0x39)	hex=asc-0x30;
	else if(asc>='a'&&asc<='f')	hex=10+asc-'a';
	else if(asc>='A'&&asc<='Z')	hex=10+asc-'A';
	return hex;
}
