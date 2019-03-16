
#include <iostream>
#include <vector>

void quick_sort(std::vector<int> &v,int start,int end){
	int s = start;
	int e = end;
	int pivit = v[start];
	if (start>end){
		return ;
	}
	while(start<end){
		while(start<end && v[end]>=pivit){
			end--;
		}
		v[start] = v[end];
		while(start<end && v[start]<=pivit){
			start++;
		}
		v[end] = v[start];
	}
	v[start] = pivit;
	quick_sort(v,s,start-1);
	quick_sort(v,start+1,e);
}

void print(std::vector<int> &v){
	for(int i=0;i<v.size();i++){
		std::cout<<v[i]<<" ";
	}
	std::cout<<std::endl;
}

int main(){
	std::vector<int> v = {6,3,7,5,9,5,4,1,2};
	print(v);
	quick_sort(v,0,v.size()-1);
	print(v);
	return 0;
}
