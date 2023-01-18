#include <stdio.h>
#include <iostream>

#include <list>
using namespace std;

int main(void) {
	
	list<const char*> list
	{
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"Shin - Okubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		"Tamachi",
		"Hamamatsucho",
		"Shimbashi",
		"Yurakucho"
	};

	cout << "1970年" << "\n";
	for (auto itr = list.begin(); itr != list.end(); itr++) {
		cout << *itr << "\n";
	}
	// 西日暮里を挿入する
	list.insert(next(list.begin(), 7), "Nishi - Nippori");

	cout << "\n2019年" << "\n";
	for (auto itr = list.begin(); itr != list.end(); itr++) {
		cout << *itr << "\n";
	}
	// 高輪ゲートウェイを挿入する
	list.insert(next(list.begin(), 25), "Takanawa - Gateway");
	cout << "\n2022年" << "\n";

	for (auto itr = list.begin(); itr != list.end(); itr++) {
		cout << *itr << "\n";
	}

	return 0;
}