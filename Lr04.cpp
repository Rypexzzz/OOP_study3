#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void smeta(string inp_name1, string inp_name2, string out_name) {
	ifstream inp1(inp_name1);
	ifstream inp2(inp_name2);
	ofstream out(out_name, ios::app);

	string obr;
	getline(inp1, obr);
	out << "Структурное подразделение: " << obr << endl;
	out << "--------------------------------------------------" << endl;
	int spis = 1, money, min_mon=100000000;
	while (getline(inp1, obr)) {
		obr.erase(std::remove(obr.begin(), obr.end(), '\t'), obr.end());//удаление всех ненужных tab-ов
		inp2 >> money;
		out << setw(2) << left << spis << " " << setw(40) << setfill('.') << obr << setw(6) << right << money << setfill(' ') << endl;
		spis++;
		if (min_mon > money) {
			min_mon = money;
		}
	}
	out << "--------------------------------------------------" << endl;
	out << "Минимальное значение: " << min_mon << endl << endl;

	inp1.close();
	inp2.close();
	out.close();
}

int main() {
	setlocale(LC_ALL, "Russian");
	smeta("11.txt", "12.txt", "result.txt");
	smeta("21.txt", "22.txt", "result.txt");
	smeta("31.txt", "32.txt", "result.txt");
	cout << "Работа программы завершена, результат хранится в файле " << "result.txt" << endl;
}
