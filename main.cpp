#include "DxLib.h"
#include "Enemy.h"

#include <list>
#include <vector>
#include <memory>

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "LE2A_24_���__�J�Y�} 03_02";

// �E�B���h�E����
const int WIN_WIDTH = 600;

// �E�B���h�E�c��
const int WIN_HEIGHT = 400;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾

	Enemy enemy;

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = {0};

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = {0};

	// �Q�[�����[�v
	while (true) {

		for (int i = 0; i < 256; i++) 
		{
			oldkeys[i] = keys[i];
		}

		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
		/*if (keys[KEY_INPUT_R] && oldkeys[KEY_INPUT_R] == false)
		{

		}*/

		enemy.Update();


		// �`�揈��
		const int cWhite = 0xffffff;
		
		if (enemy.phase_ == enemy.MELEE)
		{
			DrawFormatString(20, 80, cWhite, "���݂�Enemy�̏�� : �ڋ�");
			DrawFormatString(20, 100, cWhite, "     NEXT      : �ˌ�");
		}
		else if (enemy.phase_ == enemy.SHOT)
		{
			DrawFormatString(20, 80, cWhite, "���݂�Enemy�̏�� : �ˌ�");
			DrawFormatString(20, 100, cWhite, "     NEXT      : ���E");
		}
		else if (enemy.phase_ == enemy.ESCAPE)
		{
			DrawFormatString(20, 80, cWhite, "���݂�Enemy�̏�� : ���E");
			DrawFormatString(20, 100, cWhite, "     NEXT      : �ڋ�");
		}
		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
