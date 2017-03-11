#include <stdio.h>
#include <string.h>

int main(){
	char buf[100][10];
	for (int i = 0; i < 100; ++i)
	{
		// memset(buf[i],'1',sizeof(buf[i]-1));
		strcpy(buf[i],"123456789");
	}
	for (int i = 0; i < 100; ++i)
	{
		printf("%s\n",buf[i]);
	}


	printf("%d\b",sizeof(buf[0]));
	
	return 0;
}

