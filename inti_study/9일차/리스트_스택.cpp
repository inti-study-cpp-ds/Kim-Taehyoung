#include<iostream>
#include<string>
using namespace std;

class Node {
	friend class Stack;
private:
	int value;
	Node* before;
	Node(int v, Node* n) :value(v), before(n) {}
};
class Stack {
private:
	Node* tail;
	int size;
public:
	// ���� �ʱ�ȭ
	Stack(int v) {
		tail = new Node(v, NULL);
		size = 1;
	}
	Stack() {
		tail = new Node(NULL, NULL);
		size = 0;
	}
	// ���� ���ʿ� ���� �߰�
	void push_back(int v) {
		Node* new_Node = new Node(v, tail);
		tail = new_Node;
		size += 1;
	}
	// ���� ���ʿ� ���� ����
	void pop_back() {
		if (tail != NULL) {
			Node* pop_Node = tail;
			tail = pop_Node->before;
			delete pop_Node;
			size -= 1;
		}
	}
	// �ǵ��� ���� ���
	int top() {
		return tail->value;
	}
	// �迭 ũ�� ���,����
	int arr_size() {
		return size;
	}
	// ����ִ��� Ȯ��(empty)
	bool empty() {
		if (size == 0)
			return true;
		else
			return false;
	}
	// �Ҹ���
	~Stack() {
		while (size != 0)
			pop_back();
	}
};

int main() {
	Stack stack;
	stack.push_back(1);
	stack.pop_back();
	if (stack.empty())
		cout << "empty !\n";
	else
		cout << "not empty !\n";
	stack.push_back(7);
	stack.push_back(9);
	stack.push_back(124);
	stack.pop_back();
	cout << "top: " << stack.top() << "\n";
	cout << "size: " << stack.arr_size();
	return 0;
}
