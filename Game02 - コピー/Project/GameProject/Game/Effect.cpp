#include "Effect.h"

static TexAnim _effect_bomb[] = {
	//�p�^�[���A���x�i�Q��2F�Ŏ��̊G�Ɂj
		{ 0,2 },
		{ 1,2 },
		{ 2,2 },
		{ 3,2 },
		{ 4,2 },
};
TexAnimData effectAnimData[] ={
	ANIMDATA(_effect_bomb),
};
Effect::Effect(const CVector2D& pos)
	:Base(eType_Effect) {
	//�A�j���[�V�����f�[�^�t���œǂݍ���
	//�@�@�@�@�@�@�@�t�@�C�����@�@�@�A�j���[�V�����f�[�^�@�ꖇ�̕��A����
	m_img.Load("Image/Effect_Bomb.png", effectAnimData, 96, 96);
	m_pos = pos;
	//�A�j���[�V�����ύX�@���[�v�v���O
	m_img.ChangeAnimation(0, false);
	m_img.SetCenter(96 / 2, 96 / 2);
}
void Effect::Update()
{
//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
	//�A�j���[�V�����I���`�F�b�N
	if (m_img.CheckAnimationEnd())
			m_kill = true;

}
void Effect::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}


