#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int strlen(char p[]){
	int l = 0;
	while(p[l]!='\0'){
		l++;
	}
	return l;
}
//向后移动且有重叠时候，可以使用这个函数 2017年2月14日 23:28:04
int strncpys(char *dest,char *sour,int n){
	char *t = (char *)malloc(sizeof(char)*n);
	strncpy(t,sour,n);
	strncpy(dest,t,n);
	free(t);
}
int find(char p[],char c){
	int i = 0;
	while(p[i]!='\0'&&p[i]!=c){
		i++;
	}
	if(p[i]=='\0'){
		return -1;
	}else{
		return i;
	}
}
int find(char p1[],char p2[]){
	int len1 = strlen(p1);
	int len2 = strlen(p2);
	if(len2>len1){return -1;}

	for (int i = 0; i < len1-len2+1; ++i)
	{
		if(strncmp(p1+i,p2,len2)==0){
			return i;
		}
	}
	return -1;
}
int rfind(char p[],char c){
	for (int i = strlen(p)-1; i >=0 ; i--)
	{
		if(p[i]==c){
			return i;
		}
	}
	return -1; 
}

int erase(char p[],int pos){
	int len = strlen(p);
	if(pos>=len) return 0;
	int i;
	for (i = pos; i < len-1; ++i)
	{
		p[i] = p[i+1];
	}
	p[i] = '\0';
}

int erase(char p[],int start,int len){
	int str_len = strlen(p);
	for (int i = 0; i < str_len-start+len; ++i)
	{
		p[start+i] = p[start+len+i];
	}
}

// 2017年2月14日 23:34:36
int insert(char origin[],char pattern[]){
	int pl = strlen(pattern);	
	strncpy(origin+pl,origin,strlen(origin));
	strncpy(origin,pattern,pl);
}

int insert(char origin[],int pos,char pattern[]){
	insert(origin+pos,pattern);
}


//2017年2月15日 00:03:00
int replace(char origin[],char patternMatch[],char patternRepalce[]){
	int hasReplace = 0;
	int pos ;
	if((pos = find(origin,patternMatch))!=-1){
	}
	return hasReplace;
}

bool split(char origin[],char **dest,int *n){

}