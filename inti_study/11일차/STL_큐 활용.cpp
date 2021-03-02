#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main() {
	int movie_num = 3;
	queue<string>* custmor = new queue<string>[movie_num];
	string* movie_name = new string[movie_num];
	movie_name[0] = "귀멸의 칼날";
	movie_name[1] = "소울";
	movie_name[2] = "톰과 제리";
	custmor[0].push("이일호");
	custmor[0].push("이이호");
	custmor[0].push("이삼호");
	custmor[1].push("김태형");
	custmor[1].push("김대형");
	custmor[1].push("김태영");
	custmor[1].push("김대영");
	custmor[2].push("김영우");
	custmor[2].push("김일우");
	for (int i = 0; i < movie_num; i++) {
		cout << movie_name[i] << "- 관객 입장순서 : ";
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