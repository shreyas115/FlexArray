/* FlexArray.c */
#include "FlexArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define typename(x) _Generic((x),                                                 \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")
char* addr[10];
int *intArray[10];
char *charArray[10];
float *floatArray[10];
int intCount = -1;
int charCount = -1;
int floatCount = -1;
int codedIndex[30];
int totalCount=0;
char* CreateFlexArray(){
	//addr[1] = malloc(10);
	//addr[2] = malloc(10);
	//addr[3] = malloc(10);
	//printf("addr is '%p'\n", addr[1]);
	//printf("addr is '%p'\n", addr[2]);
	//printf("addr is  %p\n",addr[3]);
	//addr[1][0] = 100;
	//addr[2][0] = malloc(100);
	//if (addr[2][0] == NULL) {
      //  printf("Cannot allocate %zu bytes for string\n", 100);
       // exit(EXIT_FAILURE);
    //}
	strcpy(&addr[2][0], (char*)"test123");
	return &addr;
}

void AddElement(void* value, char* type)
{
	if(strcmp(type, "char") ==0 || strcmp(type, "pchar") ==0){
		charArray[++charCount] = (char *)malloc(sizeof(char));
		strcpy(charArray[charCount], (char *)value);
		codedIndex[totalCount++]=1;
		/*printf("this is value '%s'\n", value);
		printf("type is '%s'\n", type);
		printf("this is '%s'\n", charArray[charCount]);
		addr[2]=charArray;
		printf("value is '%d'\n", (&addr[2])[0]);*/
		
	}
	else if(strcmp(type, "int") ==0 || strcmp(type, "pint") ==0){
		intArray[++intCount] = (int *)malloc(sizeof(int));
		intArray[intCount] = (int)value;
		codedIndex[totalCount++]=2;
		/*printf("this is value '%d'\n", value);
		printf("this is '%s'\n", type);
		printf("this is '%d'\n", intArray[intCount]);
		addr[1]=intArray;
		printf("pointer is '%d'\n", addr[1]);*/
	}
	else if(strcmp(type, "float") ==0 || strcmp(type, "pfloat") ==0){
		floatArray[++floatCount] = (float *)malloc(sizeof(float));
		floatArray[floatCount] = ((float *)value);
		codedIndex[totalCount++]=3;
		//printf("this is value '%f'\n", *((float *)value));
		//printf("this is '%s'\n", type);
		//printf("this is '%f'\n", floatArray[floatCount]);
		//addr[3]=floatArray;
		//printf("pointer is '%d'\n", addr[3]);
	}
	
}

void* GetElement(int index)
{
	int type = codedIndex[index];
	int i=0,count=0;
	for(int i=0;i<index;i++)
	{
		if(codedIndex[i]==type)
			count++;
	}
	if(type==1)
		return charArray[count];
	else if(type==2)
		return intArray[count];
	else
		return floatArray[count];
	//printf("getelement value is '%f'\n", *floatArray[0]);
	//return floatArray[0];
	//return floatArray[0];
}
char* GetType(int index)
{	int type1= codedIndex[index];
	if(type1==1)
		return "char";
	if(type1==2)
		return "int";
	if(type1==3)
		return "float";
}	