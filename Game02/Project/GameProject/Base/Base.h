#pragma once
#include <GLLibrary.h>

enum {
	eType_Player,
	eType_Enemy,
	eType_Bullet,
	eType_Effect,
	eType_UI,
};
class Base {
public:
	//オブジェクトの種類
	int m_type;
	CVector2D m_pos;
	float m_rad;
	bool m_kill;
	static std::list<Base*> m_list;
public:
	//type オブジェクトの種類
	Base(int type);
	virtual ~Base();
	virtual void Update();
	virtual void Draw();
	virtual void Collision(Base* b);
	void SetKill() { m_kill = true; }
	static void UpdateAll();
	static void DrawAll();
	static void CollisionAll();
	static void Add(Base* b);
	static bool CollisionCircle(Base* b1, Base* b2);
	static void CheckKillAll();
	Base* FindObject(int type);
	static std::list<Base*>FindObjects(int type);
};