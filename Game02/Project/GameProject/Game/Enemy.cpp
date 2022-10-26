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
	//敵を下に動かす
	const int move_speed = 32;
	//カウントアップ
	m_cnt++;
	//60カウント(1秒)以上なら
	if (m_cnt >= 60) {
		//移動
		m_pos.y += move_speed;
		//カウンターリセット
		m_cnt = 0;
	}
}
void Enemy::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}
