/* FlexArray.c */
#include "FlexArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* addr[10];
int *intArray[10];
char *charArray[10];
float *floatArray[10];
int intCount = -1;
int charCount = -1;
int floatCount = -1;
int codedIndex[30];
int totalCount=0;

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
	for(i=0;i<index;i++)
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
}
char* GetType(int index)
{	
	int type1= codedIndex[index];
	if(type1==1)
		return "char";
	if(type1==2)
		return "int";
	if(type1==3)
		return "float";
}
void* DeleteElement(int index)
{	
	int count1=0;
	int type2= codedIndex[index];
	int j=0;
	for(j=0;j<index;j++)
		if(codedIndex[j]==type2)
			count1++;

	for(int i=index;i<totalCount;i++)
			codedIndex[i]=codedIndex[i+1];
	totalCount-=1;
	if(type2==1)
	{	
		char* temp=charArray[count1];
		for(int i=count1;i<charCount+1;i++)   
			charArray[i] = charArray[i+1]; 
		charCount-=1;
		return temp;
	}
	else if(type2==2)
	{	
		int temp1=intArray[count1];
		for(int i=count1;i<intCount+1;i++)   
			intArray[i] = intArray[i+1]; 
		intCount-=1;
		return temp1;
	}
	else
	{	
		float* temp2=floatArray[count1];
		for(int i=count1;i<floatCount+1;i++)   
			floatArray[i] = floatArray[i+1]; 
		floatCount-=1;
		return temp2;
	}
}	