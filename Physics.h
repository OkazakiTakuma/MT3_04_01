#pragma once
#include "Matrix.h"
#include "Screen3.h"
#include "Vector3.h"
#include <Novice.h>

struct Spring {

	Vector3 anchor;           //!< スプリングのアンカー位置
	float naturalLength;      //!< スプリングの自然長
	float stiffness;          //!< スプリングのばね定数
	float dampingCiefficient; //!< スプリングの減衰係数
};

struct Ball {
	Vector3 position;     //!< ボールの位置
	Vector3 velocity;     //!< ボールの速度
	Vector3 acceleration; //!< ボールの加速度
	float mass;           //!< ボールの質量
	float radius;         //!< ボールの半径
	unsigned int color;   //!< ボールの色
};
