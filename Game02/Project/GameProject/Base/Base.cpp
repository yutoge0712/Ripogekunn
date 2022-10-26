#include "Base.h"
std::list<Base*> Base::m_list;
Base::Base(int type) : m_type(type),m_kill(false), m_rad(0) {

}


bool Base::CollisionCircle(Base* b1, Base* b2) {
	CVector2D v = b1->m_pos - b2->m_pos;
	float l = v.Length();
	if (l < b1->m_rad + b2->m_rad) {
		return true;
	}
	return false;
}
Base::~Base() {

}

void Base::Update() {

}

void Base::Draw() {

}

void Base::Collision(Base* b)
{
}
void Base::CollisionAll() {
	auto it1 = m_list.begin();
	auto last = m_list.end();
	while (it1 != last) {
		auto it2 = it1;
		it2++;
		while (it2 != last) {
			(*it1)->Collision(*it2);
			(*it2)->Collision(*it1);
			it2++;
		}
		it1++;
	}
}
void Base::UpdateAll()
{
	//�S�ẴI�u�W�F�N�g�̍X�V
	for (auto& b : m_list) {
		b->Update();
	}
}

void Base::DrawAll()
{
	//�S�ẴI�u�W�F�N�g�̕`�揈��
	for (auto& b : m_list) {
		b->Draw();
	}
}

void Base::Add(Base* b)
{
	//�I�u�W�F�N�gb�𖖔��ɒǉ�
	m_list.push_back(b);
	//Type���ɂ��\�[�g
	auto itr = m_list.begin();
	while (itr != m_list.end()) {
		if ((*itr)->m_type > b->m_type) {
			m_list.insert(itr, b);
			return;
		}
		itr++;
	}
	m_list.push_back(b);
}

	void Base::CheckKillAll() {
		auto it = m_list.begin();
		auto last = m_list.end();
		while (it != last) {
			if ((*it)->m_kill) {
				it = m_list.erase(it);
			}
			else {
				//����
				it++;
			}
		}
	}
	Base* Base::FindObject(int type) {
		//�擪�̗v�f
		auto it = m_list.begin();
		//�����̗v�f
		auto last = m_list.end();
		//it�������łȂ����
		while (it != last) {
			if ((*it)->m_type == type) {
				//�������I�u�W�F�N�g�̕ԋp
				return (*it);
			}
			it++;
		}
		return nullptr;
	}

	std::list<Base*> Base::FindObjects(int type)
	{
		 std::list<Base*>ret;
		 for (auto& b : m_list) {
			 if (b->m_type == type)
				 ret.push_back(b);
		 }
		 return ret;
	}
