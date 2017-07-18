#include <iostream>
using namespace std;

int n, t = -1;
char stack[10000];
int priority[10000];

int empt() {
	if (t == -1) return 1;
	else return 0;
}

char pop() {
	if (empt()) return -1;

	t--;

	return stack[t + 1];
}

void push(char x, int p) {
	t++;
	stack[t] = x;
	priority[t] = p;
}

void sta(char x, int p) {
	if (p > priority[t] || t == -1) push(x, p);
	else if (p <= priority[t]) {
		while (p <= priority[t] && t != -1){
			printf("%c", pop());
		}
		push(x, p);
	}
}

int top() {
	if (empt()) return -1;

	return stack[t];
}

void print() {
	while (!empt()) {
		if (top() == '(') {
			pop(); 
			break;
		}
		else printf("%c", pop());
	}
}

int main() {
	string s; cin >> s;

	for (int i = 0; i < s.size(); i++) {

		if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]);
		else if (s[i] == '(') push(s[i], 1); 
		else if (s[i] == '+' || s[i] == '-') sta(s[i], 2);
		else if (s[i] == '*' || s[i] == '/') sta(s[i], 3);
		else if (s[i] == ')') print();
	}

	print();
}
