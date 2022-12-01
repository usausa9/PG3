#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <iostream>

#include "List.h"

enum State 
{
	MENU,
	OUTPUT,
	INSERT,
	EDIT,
	DELETE,
	SORT
};

using namespace std;

int main() 
{
	list<const char*> lst(0);
	auto itr = lst.begin();
	itr = lst.insert(itr, "banana");
	++itr;
	itr = lst.insert(itr, "apple");
	++itr;
	itr = lst.insert(itr, "orange");

	int state = 0;
	int state2[3] = {};
	
	char str[16] = {};
	int userInput[3] = {};

	while (true)
	{
		if (state < OUTPUT || state > SORT) 
		{
			// 画面クリア
			system("cls");

			printf("[要素の操作]\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");
			printf("3.要素の編集\n");
			printf("4.要素の削除\n");
			printf("5.要素の並び替え(オプション)\n");
			printf("\n");
			printf("-------------------------------\n");
			printf("操作を選択してください。\n");
			scanf_s("%d", &userInput[0]);
			state = userInput[0];
		}

		if (state == OUTPUT) 
		{
			// 要素の表示
			if (state2[0] == 0) 
			{
				// 画面クリア
				system("cls");

				userInput[0] = 0;
				printf("[要素の表示]\n");
				printf("1.要素の一覧表示\n");
				printf("2.順番を指定して要素を表示\n");
				printf("9.要素操作に戻る\n");
				printf("\n操作を選択してください。\n");
				scanf_s("%d", &userInput[0]);
				state2[0] = 1;
			}

			// 要素の一覧表示
			if (userInput[0] == 1 && state2[1] == 0) 
			{
				// 画面クリア
				system("cls");

				printf("[要素の一覧表示]\n");
				printf("要素一覧: {\n");

				int i = 0;

				for (auto itr = lst.begin(); itr != lst.end(); ++itr) 
				{
					printf(" %d: \"", i);
					cout << *itr << "\",\n";
					i++;
					
				}

				printf("}\n");
				printf("\n");

				printf("要素数: ");
				cout << lst.size() << "\n";

				printf("\n-------------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");

				scanf_s("%d", &userInput[1]);

				state2[1] = 1;
			}

			// 順番を指定して要素を表示
			if (userInput[0] == 2 && state2[2] == 0) 
			{
				// 画面クリア
				system("cls");

				printf("[順番を指定して要素を表示]\n");

				printf("表示したい要素の順番を指定してください。\n");

				// ここに入力された要素の出力
				scanf_s("%d", &userInput[2]);
				printf("\n%d: ", userInput[2]);
				itr = lst.begin();
				for (int i = 0; i < userInput[2]; i++) 
				{
					++itr;
				}
				cout << *itr << "\n";

				printf("\n-------------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");

				scanf_s("%d", &userInput[1]);

				state2[2] = 1;
			}

			if (userInput[1] == 1) 
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
			}

			// 要素操作に戻る
			if (userInput[0] == 9 || userInput[1] == 2) 
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
				state = MENU;
			}
		}

		// 要素の挿入
		if (state == INSERT) 
		{
			if (state2[0] == 0) 
			{
				// 画面クリア
				system("cls");

				printf("[リスト要素の挿入]\n");
				printf("要素を追加する場所を指定してください。");
				printf("最後尾に追加する場合は何も入力しないでください。\n");
				scanf_s("%d", &userInput[0]);

				printf("追加する要素の値を入力してください。\n");
				scanf_s("%s", str, 16);
				const char* newstr;
				newstr = str;

				printf("要素\"%s\"が%d番目に挿入されました。\n", str, userInput[0]);

				printf("\n9.要素操作に戻る\n");
				scanf_s("%d", &userInput[2]);
				state2[0] = 1;
			}

			if (userInput[2] == 9) 
			{
				state2[0] = 0;
				state = MENU;
			}
		}

		if (state == EDIT) 
		{
			// 画面クリア
			system("cls");
		}

		if (state == DELETE) 
		{
			// 画面クリア
			system("cls");
		}

		if (state == SORT) 
		{
			// 画面クリア
			system("cls");
		}
	}

	return 0;
}