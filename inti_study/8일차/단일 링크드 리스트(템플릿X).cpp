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
	// v=0�϶��� �� ����Ʈ�� �ʱ�ȭ,�ٸ� ���� 1ũ���� ����Ʈ
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
	// ���� ���ʿ� ���� �߰�
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
	// ���� ���ʿ� ���� ����
	void pop_front() {
		if (head != NULL) {
			Node* pop_Node = head->next;
			delete head;
			head = pop_Node;
			size -= 1;
		}
	}
	// ���ϴ� ��ġ(i)�� �ڿ� v�� ���� ���� ����Ʈ���� �߰�
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
	// �迭 ũ�� ���,����
	void print_size() {
		cout << "size: " << size << "\n";
	}
	int list_size() {
		return size;
	}
	// �����ϰ� ���� ���� [] ���۷�����
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
	// �Ҹ���
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
�߰��غ��� �� ��
1. ����⸮��Ʈ�� pop_back������
2. ���ø������ؼ� �ٸ� �ڷ������ε� �����ϰ� ������
*/