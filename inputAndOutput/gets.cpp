#include <stdio.h>
#include <string.h>
int main(){
	char buf[100];
	gets(buf);

	printf("%d\n",strlen(buf));
	puts(buf);	
	return 0;
}