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
		cout << "i번째 인자" << arr[i] << "\n";
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
	student.push_back("이일호");
	student.push_back("이삼호");
	student.push_back("이사호");
	student.push_back("이오호");
	student.push_back("이육호");
	double average = 0;
	for (int i = 0; i < 5; i++)
		average += gpa[i];
	cout << "5명의 평균 학점: " << average / 5 << "\n";
	return 0;
}

/*
추가해야 할 것
1. 대입연산자로 값 바꿔주기
2. push_back 쓰지않고 바로 초기화할 수 있도록 하기
*/