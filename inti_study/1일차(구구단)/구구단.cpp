#include<iostream>
#include<algorithm>
using namespace std;

void gugudan(int num);

int main() {
	int n = 0;
	cout << "1~9���� ����ϰ� ���� ���� �Է����ּ���\n";
	cin >> n;
	gugudan(n);
}

void gugudan(int num) {
	if (num > 9 || num < 1)
		cout << "���� �߸� �Է��ϼ̽��ϴ�\n";
	else {
		for (int i = 1; i <= 9; i++)
			cout << num << " * " << i << " = " << num * i << "\n";
	}
	return;
}