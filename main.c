#include <stdio.h>
#include<string.h>
#include "FlexArray.h"
#define typename(x) _Generic((x),								\
        _Bool: "_Bool",     unsigned char: "uchar",         	\
         char: "char",      signed char: "schar",           	\
    short int: "sint",      unsigned short int: "usint",    	\
          int: "int",       unsigned int: "uint",           	\
     long int: "lint",      unsigned long int: "ulint",     	\
long long int: "llint", 	unsigned long long int: "ullint", 	\
        float: "float",     double: "double",                 	\
  long double: "ldouble",   char *: "pchar",        			\
       void *: "pvoid",     int *: "pint",         				\
      default: "other")
	  
void main()
{
	int i = 121212;
	float f = 13.45f;
	AddElement(i, typename(i));
	AddElement("test", typename("test"));
	AddElement(&f, typename(f));
	AddElement(123, typename(123));
	AddElement("abcd", typename("abcd"));
	float f1 = 12.34f;
	AddElement(&f1, typename(f1));
	
	if(strcmp(GetType(1),"char")==0)
		printf("value is %s\n",GetElement(1));
	if(strcmp(GetType(0),"int")==0)
		printf("value is %d\n",GetElement(0));
	if(strcmp(GetType(2),"float")==0)
		printf("value is %f\n",*((float*)GetElement(2)));
	
	if(strcmp(GetType(0),"int")==0)
		printf("Deleted value is %d\n",DeleteElement(0));
	if(strcmp(GetType(3),"char")==0)
		printf("Deleted value is %s\n",DeleteElement(3));
	if(strcmp(GetType(3),"float")==0)
		printf("Deleted value is %f\n",*((float*)DeleteElement(3)));
}