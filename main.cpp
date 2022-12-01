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
			// ��ʃN���A
			system("cls");

			printf("[�v�f�̑���]\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");
			printf("3.�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");
			printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
			printf("\n");
			printf("-------------------------------\n");
			printf("�����I�����Ă��������B\n");
			scanf_s("%d", &userInput[0]);
			state = userInput[0];
		}

		if (state == OUTPUT) 
		{
			// �v�f�̕\��
			if (state2[0] == 0) 
			{
				// ��ʃN���A
				system("cls");

				userInput[0] = 0;
				printf("[�v�f�̕\��]\n");
				printf("1.�v�f�̈ꗗ�\��\n");
				printf("2.���Ԃ��w�肵�ėv�f��\��\n");
				printf("9.�v�f����ɖ߂�\n");
				printf("\n�����I�����Ă��������B\n");
				scanf_s("%d", &userInput[0]);
				state2[0] = 1;
			}

			// �v�f�̈ꗗ�\��
			if (userInput[0] == 1 && state2[1] == 0) 
			{
				// ��ʃN���A
				system("cls");

				printf("[�v�f�̈ꗗ�\��]\n");
				printf("�v�f�ꗗ: {\n");

				int i = 0;

				for (auto itr = lst.begin(); itr != lst.end(); ++itr) 
				{
					printf(" %d: \"", i);
					cout << *itr << "\",\n";
					i++;
					
				}

				printf("}\n");
				printf("\n");

				printf("�v�f��: ");
				cout << lst.size() << "\n";

				printf("\n-------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

				scanf_s("%d", &userInput[1]);

				state2[1] = 1;
			}

			// ���Ԃ��w�肵�ėv�f��\��
			if (userInput[0] == 2 && state2[2] == 0) 
			{
				// ��ʃN���A
				system("cls");

				printf("[���Ԃ��w�肵�ėv�f��\��]\n");

				printf("�\���������v�f�̏��Ԃ��w�肵�Ă��������B\n");

				// �����ɓ��͂��ꂽ�v�f�̏o��
				scanf_s("%d", &userInput[2]);
				printf("\n%d: ", userInput[2]);
				itr = lst.begin();
				for (int i = 0; i < userInput[2]; i++) 
				{
					++itr;
				}
				cout << *itr << "\n";

				printf("\n-------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

				scanf_s("%d", &userInput[1]);

				state2[2] = 1;
			}

			if (userInput[1] == 1) 
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
			}

			// �v�f����ɖ߂�
			if (userInput[0] == 9 || userInput[1] == 2) 
			{
				state2[0] = 0;
				state2[1] = 0;
				state2[2] = 0;
				state = MENU;
			}
		}

		// �v�f�̑}��
		if (state == INSERT) 
		{
			if (state2[0] == 0) 
			{
				// ��ʃN���A
				system("cls");

				printf("[���X�g�v�f�̑}��]\n");
				printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B");
				printf("�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B\n");
				scanf_s("%d", &userInput[0]);

				printf("�ǉ�����v�f�̒l����͂��Ă��������B\n");
				scanf_s("%s", str, 16);
				const char* newstr;
				newstr = str;

				printf("�v�f\"%s\"��%d�Ԗڂɑ}������܂����B\n", str, userInput[0]);

				printf("\n9.�v�f����ɖ߂�\n");
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
			// ��ʃN���A
			system("cls");
		}

		if (state == DELETE) 
		{
			// ��ʃN���A
			system("cls");
		}

		if (state == SORT) 
		{
			// ��ʃN���A
			system("cls");
		}
	}

	return 0;
}