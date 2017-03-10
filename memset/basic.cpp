#include <stdio.h>
#include <string.h>

int main(){
	char buf[10];
	// memset(buf,'H',1);
	// "H"
	// memset(buf,'H',sizeof(buf));//也就是10
	// "HHHHHHHHHH"

	printf("%s\n",buf);
	return 0;
}