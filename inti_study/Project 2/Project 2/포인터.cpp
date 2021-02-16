#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void change_normal(int num) {
	num = 2;
	return;
}
void change_ptr(int& num) {
	num = 2;
	return;
}

int main() {
	int arr_1[4];
	for (int i = 0; i < 4; i++) {
		arr_1[i] = i;
	}
	int* ptr_1 = arr_1;
	cout << "arr : ";
	for (int i = 0; i < 4; i++) {
		cout << arr_1[i] << " ";
	}
	cout << "\nptr_1 : ";
	for (int i = 0; i < 4; i++) {
		cout << ptr_1[i] << " ";
	}
	cout << "\n-------------------------------\n";
	int num_normal = 1;
	int num_ptr = 1;
	int* ptr_2 = &num_ptr;
	cout << "before num_normal : " << num_normal << " before num_ptr : " << *ptr_2 << "\n";
	change_normal(num_normal);
	change_ptr(num_ptr);
	cout << "after num_normal : " << num_normal << " after num_ptr : " << *ptr_2;
}