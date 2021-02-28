#include<iostream>
#include<string>
using namespace std;

class Node {
	friend class List;
private:
	int value;
	Node* next;
	Node(int v, Node* n) :value(v), next(n){}
};
class List {
private:
	Node* tail;
	Node* head;
	int size;
public:
	// v=0일때는 빈 리스트로 초기화,다른 경우는 1크기의 리스트
	List(int v = 0) {
		if (v == 0) {
			head = tail = NULL;
			size = 0;
		}
		else {
			head = tail = new Node(v, NULL);
			size = 1;
		}
	}
	// 가장 뒤쪽에 원소 추가
	void push_back(int v) {
		Node* new_Node = new Node(v, NULL);
		if (head == NULL) {
			head = new_Node;
		}
		else {
			tail->next = new_Node;
		}
		tail = new_Node;
		size += 1;
	}
	// 가장 앞쪽에 원소 삭제
	void pop_front() {
		if (head != NULL) {
			Node* pop_Node = head->next;
			delete head;
			head = pop_Node;
			size -= 1;
		}
	}
	// 원하는 위치(i)에 뒤에 v의 값을 가진 리스트원소 추가
	void insert_value(int i, int v) {
		Node* insert_Node;
		insert_Node = head;
		if (i >= size) {
			cout << "out of bound\n";
			return;
		}
		while (i != 0) {
			insert_Node = insert_Node->next;
			i -= 1;
		}
		Node* created_Node = new Node(v, insert_Node->next);
		insert_Node->next = created_Node;
		size += 1;
	}
	// 배열 크기 출력,리턴
	void print_size() {
		cout << "size: " << size << "\n";
	}
	int list_size() {
		return size;
	}
	// 간편하게 보기 위한 [] 오퍼레이터
	int operator[](int i) {
		if (i >= size)
			return 0;
		Node* insert_Node = head;
		while (i != 0) {
			insert_Node = insert_Node->next;
			i -= 1;
		}
		return insert_Node->value;
	}
	// 소멸자
	~List() {
		while (head != NULL)
			pop_front();
	}
};

int main() {
	List gpa_list(0);
	int gpa = 0;
	int average = 0;
	for (int i = 0; i < 5; i++) {
		cin >> gpa;
		gpa_list.push_back(gpa);
	}
	cout << "average: ";
	for (int i = 0; i < gpa_list.list_size(); i++) {
		average += gpa_list[i];
	}
	cout << average / gpa_list.list_size();
	
	return 0;
}

/*
추가해봐야 할 것
1. 양방향리스트로 pop_back만들어보기
2. 템플릿구현해서 다른 자료형으로도 가능하게 만들어보기
*/