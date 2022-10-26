#pragma once
//Base.h‚Íˆê‚Âã‚ÌƒtƒHƒ‹ƒ_
#include "../Base/Base.h"
class Player : public Base{
public:
	CImage m_img;
	
public:
	Player(const CVector2D& pos);
	void Update();
	void Draw();

};