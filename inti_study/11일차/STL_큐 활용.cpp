#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main() {
	int movie_num = 3;
	queue<string>* custmor = new queue<string>[movie_num];
	string* movie_name = new string[movie_num];
	movie_name[0] = "�͸��� Į��";
	movie_name[1] = "�ҿ�";
	movie_name[2] = "��� ����";
	custmor[0].push("����ȣ");
	custmor[0].push("����ȣ");
	custmor[0].push("�̻�ȣ");
	custmor[1].push("������");
	custmor[1].push("�����");
	custmor[1].push("���¿�");
	custmor[1].push("��뿵");
	custmor[2].push("�迵��");
	custmor[2].push("���Ͽ�");
	for (int i = 0; i < movie_num; i++) {
		cout << movie_name[i] << "- ���� ������� : ";
		while (!custmor[i].empty()) {
			cout << custmor[i].front() << " ";
			custmor[i].pop();
		}
		cout << "\n";
	}
	delete[] custmor;
	delete[] movie_name;
	
	return 0;
}