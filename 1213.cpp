#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

int main() {
	int arr[100];

	memset(arr, 0, sizeof(arr));

	string s; cin >> s;

	for (int i = 0; i < s.size(); i++) arr[s[i] - 'A']++;

	bool flag = false;
	int index;
	if (s.size() % 2 == 1) { // 문자열이 홀수일 경우
		for (int i = 0; i < 26; i++) { // 갯수가 홀수인 알파벳은 1개만 허용
			if (arr[i] % 2 == 1) {
				if (flag) {
					cout << "I'm Sorry Hansoo";
					return 0;
				}
				flag = true;
				index = i;
			}
		}

		for (int i = 0; i < 26; i++) arr[i] /= 2; // 각 갯수를 절반으로 나눠줌

		for (int i = 0; i < 26; i++)  // 가운데를 기준으로 앞부분 출력
			for (int j = 0; j < arr[i]; j++) 
				printf("%c", i + 'A'); 
		
		printf("%c", index + 'A');

		for (int i = 25; i >= 0; i--)  // 가운데를 기준으로 뒷부분 출력
			for (int j = 0; j < arr[i]; j++) 
				printf("%c", i + 'A');

	}
	else { // 문자열이 짝수인 경우
		for (int i = 0; i < 26; i++) {
			if (arr[i] % 2 == 1) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}

		for (int i = 0; i < 26; i++) arr[i] /= 2;

		for (int i = 0; i < 26; i++)  // 가운데를 기준으로 앞부분 출력
			for (int j = 0; j < arr[i]; j++) 
				printf("%c", i + 'A');

		for (int i = 25; i >= 0; i--)  // 가운데를 기준으로 뒷부분 출력
			for (int j = 0; j < arr[i]; j++) 
				printf("%c", i + 'A');
		
	}
}
