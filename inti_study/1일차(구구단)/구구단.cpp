#include<iostream>
#include<algorithm>
using namespace std;

void gugudan(int num);

int main() {
	int n = 0;
	cout << "1~9단중 출력하고 싶은 값을 입력해주세요\n";
	cin >> n;
	gugudan(n);
}

void gugudan(int num) {
	if (num > 9 || num < 1)
		cout << "값을 잘못 입력하셨습니다\n";
	else {
		for (int i = 1; i <= 9; i++)
			cout << num << " * " << i << " = " << num * i << "\n";
	}
	return;
}