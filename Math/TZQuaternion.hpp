/*
 *  quaternion.h
 *  Ninteru3DMacOSX
 *
 *  Created by Fumiyasu Takaura on 1/25/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef TZQuaternion_H
#define TZQuaternion_H

#include "TZVector.hpp"
#include "TZMatrix.hpp"


class TZQuaternion
{
public:
	
	union  {
		float q[4];
		struct  {
			float w;      // 実部
			float x,y,z;  // 虚部
		};
	};
	
	TZQuaternion();
	TZQuaternion( const float arg_w, const float arg_x, const float arg_y, const float arg_z );
	TZQuaternion( const float arg_w, const TZVector3D &vector3D );
	TZQuaternion( const TZQuaternion &arg_quaternion );
	~TZQuaternion();
	
	bool operator==( const TZQuaternion &quaternion ) const;
	void operator+=( const TZQuaternion &quaternion );
	TZQuaternion operator+( const TZQuaternion &quaternion ) const;
	void operator-=( const TZQuaternion &quaternion );
	TZQuaternion operator-( const TZQuaternion &quaternion ) const;
	void operator*=( const float scala );
	TZQuaternion operator*( const float scala ) const;
	void operator*=( const TZQuaternion &quaternion );
	TZQuaternion operator*( const TZQuaternion &quaternion ) const;
	void operator/=( const float denominator );
	TZQuaternion operator/( const float denominator ) const;
	float& operator[]( const int index );

	void print( std::string tag );
	
	// 逆クオータニオン
	std::pair<bool,TZQuaternion> invert();
	// 共役クオータニオン
	TZQuaternion conjugate();
	// ノルムの2乗
	float squareNorm();
	
	// 単位クオータニオン
	TZQuaternion unit();
	
	// 回転 thisは軸ではなく、回転対象の頂点を表すクオータニオン
	void axisRotate( const float angle_degree, TZVector3D &axis );
	
	
	// Q(cos(w/2),TZVector3D(x,y,z)*sin(w/2))に変換してから回転行列化　普通はこちらを使う。
	TZMatrix toRotationTZMatrix();
	// Q(w;x,y,z)で、w=cos(回転角/2),|TZVector3D(x,y,z)|=1でないと回転行列にはならない　あまり使わない。
	TZMatrix toTZMatrix();
	
	// 球面線形補間 Spherical Linear intERPolation
	void slerp( TZVector3D start, TZVector3D end, const float t_0to1 );
	
};


#endif
