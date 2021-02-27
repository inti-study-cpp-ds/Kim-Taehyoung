#include <iostream>
#include <string>
using namespace std;

template<typename T,size_t N>
class Vector {
private:
	T* arr;
	int capacity;
	int length;
public:
	Vector() :arr(new T[N]), capacity(N), length(0) {
	}
	void push_back(T m) {
		if (length >= capacity) {
			cout << "out of memory\n";
			return;
		}
		arr[length] = m;
		length += 1;
	}
	int operator[](int i) { return arr[i]; }
	void print_arr(int i) {
		cout << "i��° ����" << arr[i] << "\n";
	}
	bool is_empty() {
		if (length == 0)
			return true;
		else
			return false;
	}
	int size() {
		return length;
	}
	int use_capacity() {
		return capacity;
	}
	~Vector() {
		if (arr) {
			delete[]arr;
		}
	}
};

int main() {
	Vector<int, 5> classNum;
	classNum.push_back(12181760);
	classNum.push_back(12181761);
	classNum.push_back(12181762);
	classNum.push_back(12181763);
	classNum.push_back(12181764);
	Vector<double, 5> gpa;
	gpa.push_back(1.9);
	gpa.push_back(2.5);
	gpa.push_back(3.1);
	gpa.push_back(3.7);
	gpa.push_back(4.3);
	Vector<string, 5>student;
	student.push_back("����ȣ");
	student.push_back("�̻�ȣ");
	student.push_back("�̻�ȣ");
	student.push_back("�̿�ȣ");
	student.push_back("����ȣ");
	double average = 0;
	for (int i = 0; i < 5; i++)
		average += gpa[i];
	cout << "5���� ��� ����: " << average / 5 << "\n";
	return 0;
}

/*
�߰��ؾ� �� ��
1. ���Կ����ڷ� �� �ٲ��ֱ�
2. push_back �����ʰ� �ٷ� �ʱ�ȭ�� �� �ֵ��� �ϱ�
*/