#pragma once
#include <GLLibrary.h>
#define GRAVITY	(9.8f/20)

enum {
	eType_Field,
	eType_Player,
	eType_Enemy,
	eType_Bullet,
	eType_Player_Attack,
	eType_Enemy_Attack,
	eType_Effect,
	eType_UI,
	
};
class Base {
public:
	//���W�f�[�^
	CVector2D m_pos;
	bool m_kill;
	static std::list<Base*> m_list;
	//�I�u�W�F�N�g�̎��
	int m_type;
	//���a
	float m_rad;
	//�ړ��x�N�g��
	CVector2D m_vec;
	//�X�N���[���l
	static CVector2D m_scroll;
	//�Z�`
	CRect m_rect;
public:
	static CVector2D GetScreenPos(const CVector2D& pos);
	static std::list<Base*> FindObjects(int type);
	Base(int type);
	virtual ~Base();
	virtual void Update();
	virtual void Draw();
	virtual void Collision(Base* b);
	void SetKill() { m_kill = true; }
	static void CollisionAll();
	//�Z�`���m�̔���
	static bool CollisionRect(Base* b1, Base b2);
	//�Z�`�̕\��
	void DrawRect();

	static void UpdateAll();
	static void DrawAll();
	bool CollisionRect(Base* b1, Base* b2);
	static void CheckKillAll();
	static void Add(Base* b);
	static bool CollisionCircle(Base* b1, Base* b2);
	Base* Base::FindObject(int type);
};


