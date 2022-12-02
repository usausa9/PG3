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
	string input;	// ���s�݂̂̏ꍇ

	unsigned int cellNum = 0;	// index�p

	while (true)
	{
		if (state == State::MENU || (int)state > (int)State::ALL_DELETE)
		{
			// ��ʃN���A
			system("cls");

			printf("[�v�f�̑���]\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");
			if (myList.GetBegin() != nullptr)
			{
				printf("3.�v�f�̕ҏW\n");
				printf("4.�v�f�̍폜\n");
				printf("5.�v�f�̑S�폜\n");
			}
			printf("\n");
			printf("-------------------------------\n");
			printf("�����I�����Ă��������B\n");
	
			do {
				scanf_s("%d", &selectInput[0]);
				scanf_s("%*[^\n]%*c");
			} while (selectInput[0] <= 1 && selectInput[0] >= 5);

			state = (State)selectInput[0];
		}
		else if (state == State::OUTPUT)
		{
			// �v�f�̕\��
			if (state2[0] == 0)
			{
				// ��ʃN���A
				system("cls");

				selectInput[0] = 0;
				printf("[�v�f�̕\��]\n");
				printf("1.�v�f�̈ꗗ�\��\n");
				printf("2.���Ԃ��w�肵�ėv�f��\��\n");
				printf("9.�v�f����ɖ߂�\n");
				printf("\n�����I�����Ă��������B\n");

				do {
					scanf_s("%d", &selectInput[0]);
					scanf_s("%*[^\n]%*c");
				} while (selectInput[0] != 1 && selectInput[0] != 2 && selectInput[0] != 9);
				state2[0] = 1;
			}

			// �v�f�̈ꗗ�\��
			if (selectInput[0] == 1 && state2[1] == 0)
			{
				// ��ʃN���A
				system("cls");

				printf("[�v�f�̈ꗗ�\��]\n");
				printf("�v�f�ꗗ: {\n");

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

				printf("�v�f��: %d\n", cellNum);

				printf("\n------------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

				do {
					scanf_s("%d", &selectInput[1]);
					scanf_s("%*[^\n]%*c");
				} while (selectInput[1] != 1 && selectInput[1] != 2);

				state2[1] = 1;
			}

			// ���Ԃ��w�肵�ėv�f��\��
			if (selectInput[0] == 2 && state2[2] == 0)
			{
				// ��ʃN���A
				system("cls");

				printf("[���Ԃ��w�肵�ėv�f��\��]\n");

				printf("�\���������v�f�̏��Ԃ��w�肵�Ă��������B\n");

				// �����ɓ��͂��ꂽ�v�f�̏o��
				scanf_s("%d", &selectInput[2]);
				scanf_s("%*[^\n]%*c");

				printf("\n%d: \"%s\"\n\n", selectInput[2], myList.GetData(selectInput[2])->c_str());

				printf("\n------------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

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

			// �v�f����ɖ߂�
			if (selectInput[0] == 9 || selectInput[1] == 2)
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
				state = State::MENU;
			}
		}
		else if (state == State::INSERT)	// �v�f�̑}��
		{
			if (state2[0] == 0)
			{
				// ��ʃN���A
				system("cls");

				printf("[���X�g�v�f�̑}��]\n");
				printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B");
				printf("�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B\n");

				cin.clear();
				cin.ignore(1024, '\n');
				
				getline(cin, input);

				if (input == string(""))
				{
					printf("\n");
					printf("�ǉ�����v�f�̒l����͂��Ă��������B\n");

					scanf_s("%s", str, 64);
					const char* newstr;
					newstr = str;

					myList.PushBack(str);

					printf("\n");
					printf("�v�f\"%s\"���Ō���ɑ}������܂����B\n", str);
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
					printf("�ǉ�����v�f�̒l����͂��Ă��������B\n");

					scanf_s("%s", str, 64);
					const char* newstr;
					newstr = str;

					myList.Insert(myList.GetCell(selectInput[0]), string(str));

					printf("\n");
					printf("�v�f\"%s\"��%d�Ԗڂɑ}������܂����B\n", str, selectInput[0]);
				}

				printf("\n------------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

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
				// ��ʃN���A
				system("cls");
				selectInput[0] = -1;

				printf("[�v�f�̕ҏW]\n");
				printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");

				scanf_s("%d", &selectInput[0]);
				scanf_s("%*[^\n]%*c");

				if (selectInput[0] == -1) continue;

				printf("\n");

				if (myList.GetCell(selectInput[0]))
				{
					printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n", selectInput[0]);

					scanf_s("%s", str, 64);

					myList.GetCell(selectInput[0])->data = string(str);

					printf("\n");
					printf("%d�Ԗڂ̗v�f�̒l��\"%s\"�ɕύX����܂���\n", selectInput[0], str);
				}
				else
				{
					printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", selectInput[0]);
				}

				printf("\n------------------------------------\n");
				printf("1.�v�f�̕ҏW�ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

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
				// ��ʃN���A
				system("cls");
				selectInput[0] = -1;

				printf("[�v�f�̍폜]\n");
				printf("�폜�������v�f�̔ԍ����w�肵�Ă��������B\n");

				scanf_s("%d", &selectInput[0]);
				scanf_s("%*[^\n]%*c");

				if (selectInput[0] == -1) continue;

				printf("\n");

				if (myList.GetCell(selectInput[0]))
				{
					printf("%d�Ԗڂ̗v�f\"%s\"���폜���܂����B\n", selectInput[0], myList.GetData(selectInput[0])->c_str());
					myList.Erase(myList.GetCell(selectInput[0]));
				}
				else
				{
					printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", selectInput[0]);
				}

				printf("\n------------------------------------\n");
				printf("1.�v�f�̍폜�ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

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
				// ��ʃN���A
				system("cls");

				printf("[�v�f�̑S�폜]\n");
				printf("1.�S�폜�����s����\n");
				printf("2.�v�f�̑���ɖ߂�\n");

				do {
					scanf_s("%d", &selectInput[1]);
					scanf_s("%*[^\n]%*c");
				} while (selectInput[1] != 1 && selectInput[1] != 2);

				if (selectInput[1] == 1)
				{
					printf("\n�{���Ɏ��s���܂����H\n");
					printf("1.�S�폜�����s����\n");
					printf("2.�v�f�̑���ɖ߂�\n");

					do {
						scanf_s("%d", &selectInput[1]);
						scanf_s("%*[^\n]%*c");
					} while (selectInput[1] != 1 && selectInput[1] != 2);

					if (selectInput[1] == 1)
					{
						myList.Clear();
						
						printf("\n");
						printf("�S�폜�����s����܂����B\n");
					}
				}
				
				printf("\n------------------------------------\n");
				printf("2.�v�f�̑���ɖ߂�\n");

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