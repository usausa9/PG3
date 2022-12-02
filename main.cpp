#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <iostream>
#include <string>

#include "List.h"

enum class State 
{
	MENU,
	OUTPUT,
	INSERT,
	EDIT,
	DELETE,
	ALL_DELETE
};

using namespace std;

int main() 
{
	List<string> myList;
	myList.PushBack("banana");
	myList.PushBack("apple");
	myList.PushBack("orange");

	State state = State::MENU;
	int state2[3] = {};
	
	char str[64] = {};
	int selectInput[3] = {};
	string input;	// 改行のみの場合

	unsigned int cellNum = 0;	// index用

	while (true)
	{
		if (state == State::MENU || (int)state > (int)State::ALL_DELETE)
		{
			// 画面クリア
			system("cls");

			printf("[要素の操作]\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");
			if (myList.GetBegin() != nullptr)
			{
				printf("3.要素の編集\n");
				printf("4.要素の削除\n");
				printf("5.要素の全削除\n");
			}
			printf("\n");
			printf("-------------------------------\n");
			printf("操作を選択してください。\n");
	
			do {
				scanf_s("%d", &selectInput[0]);
				scanf_s("%*[^\n]%*c");
			} while (selectInput[0] <= 1 && selectInput[0] >= 5);

			state = (State)selectInput[0];
		}
		else if (state == State::OUTPUT)
		{
			// 要素の表示
			if (state2[0] == 0)
			{
				// 画面クリア
				system("cls");

				selectInput[0] = 0;
				printf("[要素の表示]\n");
				printf("1.要素の一覧表示\n");
				printf("2.順番を指定して要素を表示\n");
				printf("9.要素操作に戻る\n");
				printf("\n操作を選択してください。\n");

				do {
					scanf_s("%d", &selectInput[0]);
					scanf_s("%*[^\n]%*c");
				} while (selectInput[0] != 1 && selectInput[0] != 2 && selectInput[0] != 9);
				state2[0] = 1;
			}

			// 要素の一覧表示
			if (selectInput[0] == 1 && state2[1] == 0)
			{
				// 画面クリア
				system("cls");

				printf("[要素の一覧表示]\n");
				printf("要素一覧: {\n");

				cellNum = 0;

				for (auto cell = myList.GetBegin(); cell != nullptr; cell = cell->next)
				{

					if (cell != myList.GetEnd())
					{
						printf(" %d: \"%s\",\n", cellNum, cell->data.c_str());
					}
					else
					{
						printf(" %d: \"%s\"\n", cellNum, cell->data.c_str());
					}

					cellNum++;
				}

				printf("}\n");
				printf("\n");

				printf("要素数: %d\n", cellNum);

				printf("\n------------------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");

				do {
					scanf_s("%d", &selectInput[1]);
					scanf_s("%*[^\n]%*c");
				} while (selectInput[1] != 1 && selectInput[1] != 2);

				state2[1] = 1;
			}

			// 順番を指定して要素を表示
			if (selectInput[0] == 2 && state2[2] == 0)
			{
				// 画面クリア
				system("cls");

				printf("[順番を指定して要素を表示]\n");

				printf("表示したい要素の順番を指定してください。\n");

				// ここに入力された要素の出力
				scanf_s("%d", &selectInput[2]);
				scanf_s("%*[^\n]%*c");

				printf("\n%d: \"%s\"\n\n", selectInput[2], myList.GetData(selectInput[2])->c_str());

				printf("\n------------------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");

				do {
					scanf_s("%d", &selectInput[1]);
					scanf_s("%*[^\n]%*c");
				} while (selectInput[1] != 1 && selectInput[1] != 2);

				state2[2] = 1;
			}

			if (selectInput[1] == 1)
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
			}

			// 要素操作に戻る
			if (selectInput[0] == 9 || selectInput[1] == 2)
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
				state = State::MENU;
			}
		}
		else if (state == State::INSERT)	// 要素の挿入
		{
			if (state2[0] == 0)
			{
				// 画面クリア
				system("cls");

				printf("[リスト要素の挿入]\n");
				printf("要素を追加する場所を指定してください。");
				printf("最後尾に追加する場合は何も入力しないでください。\n");

				cin.clear();
				cin.ignore(1024, '\n');
				
				getline(cin, input);

				if (input == string(""))
				{
					printf("\n");
					printf("追加する要素の値を入力してください。\n");

					scanf_s("%s", str, 64);
					const char* newstr;
					newstr = str;

					myList.PushBack(str);

					printf("\n");
					printf("要素\"%s\"が最後尾に挿入されました。\n", str);
				}
				else
				{
					try
					{
						selectInput[0] = stoi(input);
					}
					catch (invalid_argument)
					{
						continue;
					}

					printf("\n");
					printf("追加する要素の値を入力してください。\n");

					scanf_s("%s", str, 64);
					const char* newstr;
					newstr = str;

					myList.Insert(myList.GetCell(selectInput[0]), string(str));

					printf("\n");
					printf("要素\"%s\"が%d番目に挿入されました。\n", str, selectInput[0]);
				}

				printf("\n------------------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");

				do {
					scanf_s("%d", &selectInput[1]);
					scanf_s("%*[^\n]%*c");
				} while (selectInput[1] != 1 && selectInput[1] != 2);

				state2[2] = 1;
			}

			if (selectInput[1] == 1)
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
			}

			if (selectInput[0] == 9 || selectInput[1] == 2)
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
				state = State::MENU;
			}
		}
		else if (state == State::EDIT)
		{
			if (state2[0] == 0)
			{
				// 画面クリア
				system("cls");
				selectInput[0] = -1;

				printf("[要素の編集]\n");
				printf("編集したい要素の番号を指定してください。\n");

				scanf_s("%d", &selectInput[0]);
				scanf_s("%*[^\n]%*c");

				if (selectInput[0] == -1) continue;

				printf("\n");

				if (myList.GetCell(selectInput[0]))
				{
					printf("%d番目の要素の変更する値を入力してください。\n", selectInput[0]);

					scanf_s("%s", str, 64);

					myList.GetCell(selectInput[0])->data = string(str);

					printf("\n");
					printf("%d番目の要素の値が\"%s\"に変更されました\n", selectInput[0], str);
				}
				else
				{
					printf("%d番目の要素が見つかりませんでした。\n", selectInput[0]);
				}

				printf("\n------------------------------------\n");
				printf("1.要素の編集に戻る\n");
				printf("2.要素の操作に戻る\n");

				do {
					scanf_s("%d", &selectInput[1]);
					scanf_s("%*[^\n]%*c");
				} while (selectInput[1] != 1 && selectInput[1] != 2);

				state2[2] = 1;
			}

			if (selectInput[1] == 2)
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
				state = State::MENU;
			}
		}
		else if (state == State::DELETE)
		{
			if (state2[0] == 0)
			{
				// 画面クリア
				system("cls");
				selectInput[0] = -1;

				printf("[要素の削除]\n");
				printf("削除したい要素の番号を指定してください。\n");

				scanf_s("%d", &selectInput[0]);
				scanf_s("%*[^\n]%*c");

				if (selectInput[0] == -1) continue;

				printf("\n");

				if (myList.GetCell(selectInput[0]))
				{
					printf("%d番目の要素\"%s\"を削除しました。\n", selectInput[0], myList.GetData(selectInput[0])->c_str());
					myList.Erase(myList.GetCell(selectInput[0]));
				}
				else
				{
					printf("%d番目の要素が見つかりませんでした。\n", selectInput[0]);
				}

				printf("\n------------------------------------\n");
				printf("1.要素の削除に戻る\n");
				printf("2.要素の操作に戻る\n");

				do {
					scanf_s("%d", &selectInput[1]);
					scanf_s("%*[^\n]%*c");
				} while (selectInput[1] != 1 && selectInput[1] != 2);

				state2[2] = 1;

			}

			if (selectInput[1] == 2)
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
				state = State::MENU;
			}
		}
		else if (state == State::ALL_DELETE)
		{
			if (state2[0] == 0)
			{
				// 画面クリア
				system("cls");

				printf("[要素の全削除]\n");
				printf("1.全削除を実行する\n");
				printf("2.要素の操作に戻る\n");

				do {
					scanf_s("%d", &selectInput[1]);
					scanf_s("%*[^\n]%*c");
				} while (selectInput[1] != 1 && selectInput[1] != 2);

				if (selectInput[1] == 1)
				{
					printf("\n本当に実行しますか？\n");
					printf("1.全削除を実行する\n");
					printf("2.要素の操作に戻る\n");

					do {
						scanf_s("%d", &selectInput[1]);
						scanf_s("%*[^\n]%*c");
					} while (selectInput[1] != 1 && selectInput[1] != 2);

					if (selectInput[1] == 1)
					{
						myList.Clear();
						
						printf("\n");
						printf("全削除が実行されました。\n");
					}
				}
				
				printf("\n------------------------------------\n");
				printf("2.要素の操作に戻る\n");

				do {
					scanf_s("%d", &selectInput[1]);
					scanf_s("%*[^\n]%*c");
				} while (selectInput[1] != 2);

				state2[2] = 1;
			}
			if (selectInput[1] == 2)
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
				state = State::MENU;
			}
		}
	}

	return 0;
}