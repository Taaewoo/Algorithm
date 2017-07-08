#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

string num;

int main(){
	cin>>num;

	sort(num.begin(), num.end());

	reverse(num.begin(), num.end());

	cout<<num;
}
