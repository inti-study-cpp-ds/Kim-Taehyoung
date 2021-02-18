#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class SlotMachine {
private:
	vector<pair<string, int>> drink_pay;
	int cash = 0;
public:
	void setDrink(string drink, int pay) {
		pair<string, int> temp;
		temp.first = drink;
		temp.second = pay;
		drink_pay.push_back(temp);
	}
	void setCash(int _cash) {
		cash = _cash;
	}
	void chooseDrink(int menu) {
		if (cash < drink_pay[menu].second) {
			cout << "�ܾ׺���! ���� �ܾ�: " << cash << "\n";
			return;
		}
		else {
			cash -= drink_pay[menu].second;
			cout << drink_pay[menu].first << "�� �����ϼ̽��ϴ�! ���� �ܾ�: " << cash << "��\n";
			return;
		}
	}
	void menu() {
		int menu = 0;
		cout << "��� �޴��� ��ȣ�� ����ּ���!\n";
		for (int i = 0; i < drink_pay.size(); i++)
			cout << i + 1 << "." << drink_pay[i].first << " " << drink_pay[i].second << "��\n";
		cout << "�ܵ���ȯ->0\n";
		while (true) {
			cin >> menu;
			if (menu > drink_pay.size() + 1) {
				cout << "�޴��� �߸� �Է��ϼ̽��ϴ� �ٽ� �Է����ּ���!\n";
				continue;
			}
			if (menu == 0) {
				cout << "�ܵ���ȯ: " << cash << "\n";
				break;
			}
			else {
				chooseDrink(menu - 1);
			}
		}
	}
};

int main() {
	SlotMachine slot_machine;
	int n = 0;
	cout << "����� ������ �Է�\n";
	cin >> n;
	string name;
	int pay=0;
	int cash = 0;
	cout << "����� �̸�,���� �Է�\n";
	for (int i = 0; i < n; i++) {
		cin >> name >> pay;
		slot_machine.setDrink(name, pay);
	}
	cout << "---------------------------------------\n������ �־��ּ���\n";
	cin >> cash;
	slot_machine.setCash(cash);
	slot_machine.menu();
}