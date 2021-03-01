#include<iostream>
#include<string>
using namespace std;

template <typename T>
class Node {
	template<typename T> friend class List;
private:
	T value;
	Node<T>* next;
	Node(T v, Node<T>* n) :value(v), next(n) {}
};

template<typename T>
class List {
private:
	Node<T>* tail;
	Node<T>* head;
	int size;
public:
	//생성자 오버로드, 초기화 없을땐 빈 리스트 생성
	List() {
		head = tail = NULL;
		size = 0;
	}
	// 리스트 초기화 값이주어질때는 size 1로 바로생성
	List(T v) {
			head = tail = new Node<T>(v, NULL);
			size = 1;
	}
	// 가장 뒤쪽에 원소 추가
	void push_back(T v) {
		Node<T>* new_Node = new Node<T>(v, NULL);
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
			Node<T>* pop_Node = head->next;
			delete head;
			head = pop_Node;
			size -= 1;
		}
	}
	// 원하는 위치(i)에 뒤에 v의 값을 가진 리스트원소 추가
	void insert_value(int i, T v) {
		Node<T>* insert_Node;
		insert_Node = head;
		if (i >= size) {
			cout << "out of bound\n";
			return;
		}
		while (i != 0) {
			insert_Node = insert_Node->next;
			i -= 1;
		}
		Node<T>* created_Node = new Node<T>(v, insert_Node->next);
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
	T operator[](int i) {
		if (i >= size) {
			cout << "out of bound, return tail\n";
			return tail->value;
		}
		Node<T>* insert_Node = head;
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
	List<string> student_list;
	student_list.push_back("이일호");
	student_list.push_back("이이호");
	student_list.push_back("이삼호");
	student_list.push_back("이사호");
	student_list.push_back("이오호");
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번째 학생: " << student_list[i] << "\n";
	}
	List<int> student_id;
	student_id.push_back(12181760);
	student_id.push_back(12181761);
	student_id.push_back(12181762);
	student_id.push_back(12181763);
	student_id.push_back(12181764);
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번째 학생의 학번: " << student_id[i] << "\n";
	}
	List<double> gpa_list;
	double average = 0;
	gpa_list.push_back(2.0);
	gpa_list.push_back(2.5);
	gpa_list.push_back(3.1);
	gpa_list.push_back(3.7);
	gpa_list.push_back(4.2);
	cout << "학점 평균: ";
	for (int i = 0; i < gpa_list.list_size(); i++) {
		average += gpa_list[i];
	}
	cout << average / gpa_list.list_size() << "\n";

	return 0;
}