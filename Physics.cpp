#include "Physics.h"
#include <cmath>

Vector3 CirecleMove(const Vector3& center, float radius, float angle) { return Vector3{center.x + std::cos(angle) * radius, center.y + std::sin(angle) * radius, center.z}; }

Vector3 SpringForce(const Spring& spring, Vector3 boundPosition,  Vector3 velocity, float mass, Vector3 acceleration, float deltaTIme) { 
	Vector3 diff = boundPosition - spring.anchor;                                // �X�v�����O�̃A���J�[�ʒu����{�[���̈ʒu�ւ̃x�N�g��
	float length = Length(diff);                                                 // �x�N�g���̒������v�Z
	if (length != 0.0f) {                                                        // �[�����Z������邽�߂̃`�F�b�N
		Vector3 direction = Normalize(diff);                                     // �x�N�g���𐳋K��
		Vector3 restPosition = spring.anchor + direction * spring.naturalLength; // �X�v�����O�̎��R���Ɋ�Â��ʒu
		Vector3 displacement = length * (boundPosition - restPosition);          // �{�[���̈ʒu�Ǝ��R���ʒu�̍���
		Vector3 restoringForce = -spring.stiffness * displacement;               // �X�v�����O�̕�����
		Vector3 dumpingForce = -spring.dampingCiefficient * velocity;       // ������
		Vector3 force = restoringForce + dumpingForce;                           // ���͂��v�Z
		acceleration = force / mass;                                   // �{�[���̉����x���v�Z
	}
	velocity += acceleration * deltaTIme; // �{�[���̑��x���X�V
	boundPosition += velocity * deltaTIme; // �{�[���̈ʒu���X�V
	return boundPosition;                  // �X�V���ꂽ�ʒu��Ԃ�
}
