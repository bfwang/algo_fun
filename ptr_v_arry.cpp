#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define SIZE_D1 16
#define SIZE_D2 12
#define SIZE_D3 7

using namespace std; 
void foo_arry2d(char _array[][SIZE_D1])
{
	for(int i=0; i<SIZE_D2 ;i++)
	{
		for(int j=0; j<SIZE_D1 ;j++) //now go through inside d1_ptr[i]
		{
			printf("%c ",_array[i][j]);//row first visit is in the most inner loop.
		}
		printf("\n ");
	}
}
void foo_arry3d(char _array[][SIZE_D2][SIZE_D1])
{
	for(int k=0; k<SIZE_D3 ;k++)
	{
		for(int i=0; i<SIZE_D2 ;i++) //now go through inside d1_ptr[k] total SIZE_D2*SIZE_D1 element
		{
			for(int j=0; j<SIZE_D1 ;j++) //now go through inside d1_ptr[k][i]
			{
				printf("%c ",_array[k][i][j]);//row first visit is in the most inner loop.
			}
			printf("\n ");
		}
	}
}
void foo(char* d2_arry_ptr, int d2, int d1) //flatten to char*
{
	
	for(int i=0; i<d2 ;i++)
	{
		for(int j=0; j<d1 ;j++)
		{
			printf("%c ",(d2_arry_ptr)[j+i*d1] );
		}
		printf("\n ");
	}
}

void foo2d(char** d2_arry_ptr, int d2, int d1)
{
	
	for(int i=0; i<d2 ;i++)
	{
		for(int j=0; j<d1 ;j++)
		{
			printf("%c ",(*d2_arry_ptr)[j+i*d1] );
		}
		printf("\n ");
	}
}

void foo3d(char** d3_arry_ptr, int d3, int d2, int d1)// d3_arry_ptr is flattened to an 1D array
{
	for(int k=0; k<SIZE_D3 ;k++)
	{
		for(int i=0; i<SIZE_D2 ;i++)
		{
			for(int j=0; j<SIZE_D1 ;j++) 
			{
				printf("%c ",(*d3_arry_ptr)[i*d1+j+k*d1*d2] );
			}
			printf("\n ");
		}
		printf("\n ===================================== \n");
	}
}

void main()  
{  
    const char *pInputStr="xxxyyyeeeellllllllddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddkkkkkkkkkkkkzzzzzzzzzzzzdddddddddgggggggzza";

	char (*d1_ptr) [SIZE_D1] = (char (*)[SIZE_D1]) pInputStr; //then d1_ptr++ means a SIZE_D1(16) byte offset!
	for(int i=0; i<SIZE_D2 ;i++)
	{
		for(int j=0; j<SIZE_D1 ;j++) //now go through inside d1_ptr[i]
		{
			printf("%c ",d1_ptr[i][j]);//row first visit is in the most inner loop.
		}
		printf("\n ");
	}
	
	char (*a_d1_ptr) [SIZE_D2][SIZE_D1] = (char (*)[SIZE_D2][SIZE_D1]) pInputStr;
	for(int k=0; k<SIZE_D3 ;k++)
	{
		for(int i=0; i<SIZE_D2 ;i++)
		{
			for(int j=0; j<SIZE_D1 ;j++) //now go through inside d1_ptr[i]
			{
				printf("%c ",a_d1_ptr[k][i][j]);//row first visit is in the most inner loop.
			}
			printf("\n ");
		}
		printf("\n ===================================== \n");
	}

	foo((char*)d1_ptr,SIZE_D2, SIZE_D1);
	foo2d((char**)&d1_ptr, SIZE_D2, SIZE_D1);
	foo3d((char**)&d1_ptr, SIZE_D3,SIZE_D2, SIZE_D1);
	foo_arry2d(d1_ptr);
	foo_arry3d(a_d1_ptr);
	printf("\n ");
}

