#include "Enemy.h"
Enemy::Enemy(const CVector2D& p) :Base(eType_Enemy) {
	m_img.Load("Image/Enemy.png");
	m_pos = p;
	m_cnt = 0;
	m_rad = 16;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
}
void Enemy::Update() {
	//�G�����ɓ�����
	const int move_speed = 32;
	//�J�E���g�A�b�v
	m_cnt++;
	//60�J�E���g(1�b)�ȏ�Ȃ�
	if (m_cnt >= 60) {
		//�ړ�
		m_pos.y += move_speed;
		//�J�E���^�[���Z�b�g
		m_cnt = 0;
	}
}
void Enemy::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}
