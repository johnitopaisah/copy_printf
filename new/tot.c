#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int main(void)
{
	int arr[] = {3, 6, 7};
	int i;
	int *ptr = arr;
	
	for (i = 0; i < MAX; i++)
	{
		printf("%d\n", *(ptr+i));
		printf("%d\n", *ptr++);
/**
 * printf("The memory address of arr[%d] is %p \n", i, ptr);
 *
 *		ptr++;
 */
	}
	
	return (0);
}
