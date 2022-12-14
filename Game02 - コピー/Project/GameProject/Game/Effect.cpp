#include "Effect.h"

static TexAnim _effect_bomb[] = {
	//パターン、速度（２は2Fで次の絵に）
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
	//アニメーションデータ付きで読み込み
	//　　　　　　　ファイル名　　　アニメーションデータ　一枚の幅、高さ
	m_img.Load("Image/Effect_Bomb.png", effectAnimData, 96, 96);
	m_pos = pos;
	//アニメーション変更　ループプラグ
	m_img.ChangeAnimation(0, false);
	m_img.SetCenter(96 / 2, 96 / 2);
}
void Effect::Update()
{
//アニメーション更新
	m_img.UpdateAnimation();
	//アニメーション終了チェック
	if (m_img.CheckAnimationEnd())
			m_kill = true;

}
void Effect::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}


