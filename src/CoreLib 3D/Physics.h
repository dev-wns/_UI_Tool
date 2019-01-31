#pragma once
#include "header.h"

//union q3FeaturePair
//{
//	struct
//	{
//		UCHAR inR;
//		UCHAR outR;
//		UCHAR inI;
//		UCHAR outI;
//	};
//	int key;
//};
//
//struct q3Contact
//{
//	D3DXVECTOR3 position;			// ������ ���� ��ǥ
//	float penetration;				// �浹 ħ�� ����
//	float normalImpulse;			// ���� �븻 ���
//	float tangentImpulse[2];		// ���� ���� ���
//	float bias;						// Restitution + baumgarte
//	float normalMass;				// �븻 ���� ����
//	float tangentMass[2];			// ���� ���� ����
//	q3FeaturePair fp;				// ������ ���� A�� B�� ���?
//	UCHAR warmStarted;				// ����� ������?
//};


struct PhysicsInfo
{
	bool m_usePhysics	 = true;
	bool m_isMoving		 = false;
	bool m_isGround		 = false;

	UINT UserSocket		 = DataInfo::MaxUINT;
	float m_maxHP		 = 1.0f;
	float m_curHP		 = 1.0f;
	float m_disHP		 = 1.0f;
	float m_damage		 = 0.0f;
	float m_armor		 = 1.0f;

	D3DXVECTOR3 m_force		= Vector3::Zero;	// �������� ��
	D3DXVECTOR3 m_direction = Vector3::Zero;	// �̵� ��

	float m_GravityScale = 1.0f;				// �߷�ũ��
	float m_mass		 = 1.0f;				// ����
	float m_repulsion	 = 0.3f;				// �ݹ� ���
	float m_drag		 = 0.3f;				// ������
	float m_damping		 = 0.3f;				// �׷�
	//float m_angularDamping = 0.2f;			// ȸ�� �׷�
	///
	//D3DXVECTOR3 m_prePosition;				// ���� ��ġ
	//D3DXVECTOR3 m_normal;						// �浹 �븻
	//D3DXVECTOR3 m_tangent[2];					// ���� ����
	//q3Contact	m_contacts[8];					// ���� ����?
	//int			m_contactCount;
};


class Physics
{
public:
	PhysicsInfo* m_pPhysics = nullptr;
public:
	void AddForce(const D3DXVECTOR3& vForce)				noexcept;
	void SetForce(const D3DXVECTOR3& vForce)				noexcept;
	void SetDirectionForce(const D3DXVECTOR3& vForce)		noexcept;
	void SetGravityScale(const float& gravityRate)			noexcept;

	const D3DXVECTOR3 GetForce()					  const noexcept;
	const D3DXVECTOR3 GetTotalForce()				  const noexcept;
	const float GetVelocity()						  const noexcept;
	const float GetVelocitySq()						  const noexcept;
	///
	void SetDamage(const float& value, const UCHAR& stat)	noexcept;
	//void SetArmor(const UCHAR& armorStat)					noexcept;
	void OperHP(const float& value)							noexcept;
	void HealHP(const float& value)							noexcept;
	void SetHP(const float& value)							noexcept;
	const float& GetHP()							  const noexcept;
	void SetArmor(const char& stat)							noexcept;
	const float& GetArmor()							  const noexcept;
	///
	void usePhysics(const bool& usePhysics)					noexcept;
	bool usePhysics()										noexcept;
	void isMoving(const bool& isMoving)						noexcept;
	bool isMoving()											noexcept;
	void isGround(const bool& isGround)						noexcept;
	bool isGround()											noexcept;
public:
	Physics() = default;
	virtual ~Physics() = default;
};
