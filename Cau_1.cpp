#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;
int Bool[5]={0};
int A[5];
vector<int> v,u;
int S(){
	for(int i=1;i<5;++i){
		u.push_back(A[i]);
	}
	return min(u[0],u[2])*min(u[1],u[3]);
}
void solve(int k,int a[]){
	for(int i=1;i<5;++i){
		if(!Bool[i]){
			A[k]=a[i];
			Bool[i]=1;
			if(k==4) {
				v.push_back(S());
				u.clear();
			}
			else solve(k+1,a);
			Bool[i]=0;
		}
	}
}

main(){
	int a[5];
	for(int i=1;i<5;++i) cin>>a[i];
	solve(1,a);
	cout<<*max_element(v.begin(),v.end());
}