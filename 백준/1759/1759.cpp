#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int l,c;
char al[15];
char ans[15];

void func(int index,int x){
	if(x == l){
		int mo=0;
		int ja=0;
		for(int i=0; i<l; i++){
			if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u' )
				mo++;
			else
				ja++;
			if(mo >= 1 && ja >=2) break;
		}

		if(mo < 1 || ja < 2) return;

		for(int i=0; i<l; i++)
			printf("%c", ans[i]);
		printf("\n");
		return;
	}

	for(int i=index; i<c; i++){
		ans[x] = al[i];
		func(i+1,x+1);
	}
}

int main(){// a c i s t w

	scanf("%d", &l);
	scanf("%d", &c);

	for(int i=0; i<c; i++)
		cin>>al[i];

	char temp;

	for (int i = 0; i < c-1; i++) {  
		for (int j = i + 1; j < c; j++) {
			if (al[i] > al[j]) {  
				temp = al[i];
				al[i] = al[j];
				al[j] = temp;
			}
		}
	}

	func(0,0);
}
