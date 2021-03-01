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
	//������ �����ε�, �ʱ�ȭ ������ �� ����Ʈ ����
	List() {
		head = tail = NULL;
		size = 0;
	}
	// ����Ʈ �ʱ�ȭ �����־������� size 1�� �ٷλ���
	List(T v) {
			head = tail = new Node<T>(v, NULL);
			size = 1;
	}
	// ���� ���ʿ� ���� �߰�
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
	// ���� ���ʿ� ���� ����
	void pop_front() {
		if (head != NULL) {
			Node<T>* pop_Node = head->next;
			delete head;
			head = pop_Node;
			size -= 1;
		}
	}
	// ���ϴ� ��ġ(i)�� �ڿ� v�� ���� ���� ����Ʈ���� �߰�
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
	// �迭 ũ�� ���,����
	void print_size() {
		cout << "size: " << size << "\n";
	}
	int list_size() {
		return size;
	}
	// �����ϰ� ���� ���� [] ���۷�����
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
	// �Ҹ���
	~List() {
		while (head != NULL)
			pop_front();
	}
};

int main() {
	List<string> student_list;
	student_list.push_back("����ȣ");
	student_list.push_back("����ȣ");
	student_list.push_back("�̻�ȣ");
	student_list.push_back("�̻�ȣ");
	student_list.push_back("�̿�ȣ");
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "��° �л�: " << student_list[i] << "\n";
	}
	List<int> student_id;
	student_id.push_back(12181760);
	student_id.push_back(12181761);
	student_id.push_back(12181762);
	student_id.push_back(12181763);
	student_id.push_back(12181764);
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "��° �л��� �й�: " << student_id[i] << "\n";
	}
	List<double> gpa_list;
	double average = 0;
	gpa_list.push_back(2.0);
	gpa_list.push_back(2.5);
	gpa_list.push_back(3.1);
	gpa_list.push_back(3.7);
	gpa_list.push_back(4.2);
	cout << "���� ���: ";
	for (int i = 0; i < gpa_list.list_size(); i++) {
		average += gpa_list[i];
	}
	cout << average / gpa_list.list_size() << "\n";

	return 0;
}