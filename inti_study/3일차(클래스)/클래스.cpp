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
			cout << "잔액부족! 현재 잔액: " << cash << "\n";
			return;
		}
		else {
			cash -= drink_pay[menu].second;
			cout << drink_pay[menu].first << "를 선택하셨습니다! 남은 잔액: " << cash << "원\n";
			return;
		}
	}
	void menu() {
		int menu = 0;
		cout << "드실 메뉴의 번호를 골라주세요!\n";
		for (int i = 0; i < drink_pay.size(); i++)
			cout << i + 1 << "." << drink_pay[i].first << " " << drink_pay[i].second << "원\n";
		cout << "잔돈반환->0\n";
		while (true) {
			cin >> menu;
			if (menu > drink_pay.size() + 1) {
				cout << "메뉴를 잘못 입력하셨습니다 다시 입력해주세요!\n";
				continue;
			}
			if (menu == 0) {
				cout << "잔돈반환: " << cash << "\n";
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
	cout << "음료수 가짓수 입력\n";
	cin >> n;
	string name;
	int pay=0;
	int cash = 0;
	cout << "음료수 이름,가격 입력\n";
	for (int i = 0; i < n; i++) {
		cin >> name >> pay;
		slot_machine.setDrink(name, pay);
	}
	cout << "---------------------------------------\n현금을 넣어주세요\n";
	cin >> cash;
	slot_machine.setCash(cash);
	slot_machine.menu();
}