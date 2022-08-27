#include <iostream>
using namespace std;

int n, t = -1;
double stack[10000];
double al[10000];

int empt() {
	if (t == -1) return 1;
	else return 0;
}

double pop() {
	if (empt()) return -1;

	t--;

	return stack[t + 1];
}

void push(double x) {
	t++;
	stack[t] = x;
}

int top() {
	if (empt()) return -1;

	return stack[t];
}

int main() {

	scanf("%d", &n);

	string s; cin >> s;

	for (int i = 0; i < n; i++) scanf("%lf", &al[i]);

	double temp1, temp2;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') push(al[s[i]-'A']);
		else if (s[i] == '+') {
			temp2 = pop();
			temp1 = pop();
			push(temp1 + temp2);
		}
		else if (s[i] == '-') {
			temp2 = pop();
			temp1 = pop();
			push(temp1 - temp2);
		}
		else if (s[i] == '*') {
			temp2 = pop();
			temp1 = pop();
			push(temp1 * temp2);
		}
		else if (s[i] == '/') {
			temp2 = pop();
			temp1 = pop();
			push(temp1 / temp2);
		}
	}

	printf("%.2lf", pop());
}
