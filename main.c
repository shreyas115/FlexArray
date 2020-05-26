#include <stdio.h>
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
    //char* a = CreateFlexArray();
	//printf("size is '%p'\n", &a);
	int i = 121212;
	float f = 13.45f;
	char* c = "abcd";
	//AddElement(a,i, typename(i));
	//AddElement(a,"test", typename("test"));
	printf("type name %d \n",&f);
	AddElement("",&f, typename(f));
	//int *intArray = (int *)(&a[1]-33);
	//printf("From main '%d'\n",GetElement(1));
	//printf("From main '%s'\n",(GetElement(1)));
	printf("From main %f\n",*((float*)GetElement(1)));
}