#pragma once
//Base.h�͈��̃t�H���_
#include "../Base/Base.h"
class Player : public Base{
public:
	CImage m_img;
	
public:
	Player(const CVector2D& pos);
	void Update();
	void Draw();

};