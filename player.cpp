#include"DxLib.h"
#include"player.h"
#include"main.h"

#define STATUS_NORMAL 0
#define STATUS_ATTCK 1
#define INIT_VELOCITY 70.0f			// �W�����v�̏����x

// �ϐ�
int P1StopImage;			// ��~���̉摜
int P1RunImage;				// �_�b�V�����̉摜
int P1JunpImage[2];			// �W�����v���̉摜(�U�����܂߂�)

int P1DamegeImage;			// �_���[�W���󂯂����̉摜
int P1Attack1Image;			// �ʏ�U���̉摜
int P1Attack2Image[3];			// ����U���̉摜


CHARACTER player1;

void PlayerSystemInit(void)
{
	// �U�����
	P1Attack1Image = LoadGraph("image/ataack1.png");

	player1.attckFlag = false;			// �L�����N�^�[�̏��
	player1.runFlag = false;			// �L�����N�^�[�̏��
	player1.jumpFlag = false;			// �L�����N�^�[�̏��
	player1.damageFlag = false;			// �L�����N�^�[�̏��
	player1.imgLockCnt = 0;				// �L�����N�^�[�̏��
	player1.velocity = { 0, INIT_VELOCITY };
}

void PlayerGameInit(void)
{
	// �v���C���[�̏����l
	player1.attckFlag = false;			// �L�����N�^�[�̍U�����
	player1.runFlag = false;			// �L�����N�^�[�̕������
	player1.jumpFlag = false;			// �L�����N�^�[�̃W�����v���
	player1.damageFlag = false;			// �L�����N�^�[�̃_���[�W���
	player1.imgLockCnt = 0;				// �L�����N�^�[�̏��
	player1.velocity = { 0, INIT_VELOCITY };
}

void PlayerContol(void)
{

}

void PlayerGameDraw(void)
{
	DrawGraph(325, 325, P1Attack1Image, true);
}