/*
 *  quaternion.cpp
 *  Ninteru3DMacOSX
 *
 *  Created by Fumiyasu Takaura on 1/25/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "TZQuaternion.hpp"
#include <iostream>
#include <math.h>

using namespace TZulu;


static float degree2radian(const float degree)
{
    static const float factor  = 0.00555f * M_PI;
	return degree * factor;
}
static float radian2degree(const float radian)
{
    static const float factor = M_1_PI * 180.0f;
	return radian * factor ;
}


TZQuaternion::TZQuaternion()
{
	this->w = 1;
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

TZQuaternion::TZQuaternion( const float arg_w, const float arg_x, const float arg_y, const float arg_z )
{
	this->w = arg_w;
	this->x = arg_x;
	this->y = arg_y;
	this->z = arg_z;
}

TZQuaternion::TZQuaternion( const float arg_w, const TZVector3D &vector3D )
{
	this->w = arg_w;
	this->x = vector3D.x;
	this->y = vector3D.y;
	this->z = vector3D.z;
}

TZQuaternion::TZQuaternion( const TZQuaternion &arg_quaternion )
{
	this->w = arg_quaternion.w;
	this->x = arg_quaternion.x;
	this->y = arg_quaternion.y;
	this->z = arg_quaternion.z;
}

TZQuaternion::~TZQuaternion()
{
	
}





bool TZQuaternion::operator==( const TZQuaternion &quaternion ) const
{
	if( this->w == quaternion.w &&
	    this->x == quaternion.x &&
	    this->y == quaternion.y &&
	    this->z == quaternion.z  )
	{
		return true;
	}
	
	return false;
}

void TZQuaternion::operator+=( const TZQuaternion &quaternion )
{
	this->w += quaternion.w;
	this->x += quaternion.x;
	this->y += quaternion.y;
	this->z += quaternion.z;
}
TZQuaternion TZQuaternion::operator+( const TZQuaternion &quaternion ) const
{
	TZQuaternion retQuaternion;
	
	retQuaternion.w = this->w + quaternion.w;
	retQuaternion.x = this->x + quaternion.x;
	retQuaternion.y = this->y + quaternion.y;
	retQuaternion.z = this->z + quaternion.z;
	
	return retQuaternion;
}

void TZQuaternion::operator-=( const TZQuaternion &quaternion )
{
	this->w -= quaternion.w;
	this->x -= quaternion.x;
	this->y -= quaternion.y;
	this->z -= quaternion.z;
}
TZQuaternion TZQuaternion::operator-( const TZQuaternion &quaternion ) const
{
	TZQuaternion retQuaternion;
	
	retQuaternion.w = this->w - quaternion.w;
	retQuaternion.x = this->x - quaternion.x;
	retQuaternion.y = this->y - quaternion.y;
	retQuaternion.z = this->z - quaternion.z;
	
	return retQuaternion;
}


void TZQuaternion::operator*=( const float scala )
{
	this->w *= scala;
	this->x *= scala;
	this->y *= scala;
	this->z *= scala;
}
TZQuaternion TZQuaternion::operator*( const float scala ) const
{
	TZQuaternion retQuaternion;
	
	retQuaternion.w = this->w * scala;
	retQuaternion.x = this->x * scala;
	retQuaternion.y = this->y * scala;
	retQuaternion.z = this->z * scala;
	
	return retQuaternion;
}

void TZQuaternion::operator*=( const TZQuaternion &quaternion )
{
	TZQuaternion tempQuat = *this;
	
	this->w = tempQuat.w * quaternion.w  -  tempQuat.x * quaternion.x  -  tempQuat.y * quaternion.y  -  tempQuat.z * quaternion.z;
	this->x = tempQuat.w * quaternion.x  +  tempQuat.x * quaternion.w  +  tempQuat.y * quaternion.z  -  tempQuat.z * quaternion.y;
	this->y = tempQuat.w * quaternion.y  -  tempQuat.x * quaternion.z  +  tempQuat.y * quaternion.w  +  tempQuat.z * quaternion.x;
	this->z = tempQuat.w * quaternion.z  +  tempQuat.x * quaternion.y  -  tempQuat.y * quaternion.x  +  tempQuat.z * quaternion.w;
}
TZQuaternion TZQuaternion::operator*( const TZQuaternion &quaternion ) const
{
	TZQuaternion retQuaternion;
	
	retQuaternion.w = this->w * quaternion.w  -  this->x * quaternion.x  -  this->y * quaternion.y  -  this->z * quaternion.z;
	retQuaternion.x = this->w * quaternion.x  +  this->x * quaternion.w  +  this->y * quaternion.z  -  this->z * quaternion.y;
	retQuaternion.y = this->w * quaternion.y  -  this->x * quaternion.z  +  this->y * quaternion.w  +  this->z * quaternion.x;
	retQuaternion.z = this->w * quaternion.z  +  this->x * quaternion.y  -  this->y * quaternion.x  +  this->z * quaternion.w;
	
	return retQuaternion;
}

void TZQuaternion::operator/=( const float denominator )
{
	this->w /= denominator;
	this->x /= denominator;
	this->y /= denominator;
	this->z /= denominator;
}
TZQuaternion TZQuaternion::operator/( const float denominator ) const
{
	TZQuaternion retQuaternion;
	
	retQuaternion.w = this->w / denominator;
	retQuaternion.x = this->x / denominator;
	retQuaternion.y = this->y / denominator;
	retQuaternion.z = this->z / denominator;
	
	return retQuaternion;
}

float& TZQuaternion::operator[]( const int index )
{
	return this->q[index];
}


void TZQuaternion::print( std::string tag )
{
	std::cout << tag << "( " << this->w << "; " << this->x << "," << this->y << ","  << this->z << ")" << std::endl; 
}



std::pair<bool,TZQuaternion> TZQuaternion::invert()
{
	float square_norm = this->squareNorm();
	
	if( square_norm == 0 )
	{
		return std::pair<bool,TZQuaternion>( false, TZQuaternion(0,0,0,0) );
	}
	
	
	TZQuaternion retQuaternion;
	
	retQuaternion = this->conjugate() / square_norm;
	
	return std::pair<bool,TZQuaternion>( true, retQuaternion );
}

TZQuaternion TZQuaternion::conjugate()
{
	TZQuaternion retQuaternion;
	
	retQuaternion.w = this->w;
	retQuaternion.x = -this->x;
	retQuaternion.y = -this->y;
	retQuaternion.z = -this->z;
	
	return retQuaternion;
}

float TZQuaternion::squareNorm()
{
	return ( this->w * this->w  +  this->x * this->x  +  this->y * this->y  +  this->z * this->z );
}


TZQuaternion TZQuaternion::unit()
{
	float square_norm = this->squareNorm();
	
	return *this / square_norm;
}



void TZQuaternion::axisRotate( const float angle_degree, TZVector3D &axis )
{
	float half_angle_radian = degree2radian( angle_degree ) * 0.5f;
	TZVector3D unitAxis = axis.unit();
	
	TZQuaternion q      = TZQuaternion( cos(half_angle_radian), unitAxis * sin(half_angle_radian) );
	//TZQuaternion q_conj = TZQuaternion( cos(half_angle_radian), unitAxis * (-sin(half_angle_radian)) );
	
	//*this = q * (*this) * q_conj;
	*this = (*this) * q;
}


TZMatrix TZQuaternion::toMatrix()
{
	TZMatrix retMatrix;
	
	retMatrix.m[0] = 1-2*( this->y * this->y  +  this->z * this->z );
	retMatrix.m[1] = 2*( this->x * this->y  -  this->w * this->z );
	retMatrix.m[2] = 2*( this->x * this->z  +  this->w * this->y );
	retMatrix.m[3] = 0;
	
	retMatrix.m[4] = 2*( this->x * this->y  +  this->w * this->z );
	retMatrix.m[5] = 1-2*( this->x * this->x  +  this->z * this->z );
	retMatrix.m[6] = 2*( this->y * this->z  -  this->w * this->x );
	retMatrix.m[7] = 0;
	
	retMatrix.m[8] = 2*( this->x * this->z  -  this->w * this->y );
	retMatrix.m[9] = 2*( this->y * this->z  +  this->w * this->x );
	retMatrix.m[10] = 1-2*( this->x * this->x  +  this->y * this->y );
	retMatrix.m[11] = 0;
	
	retMatrix.m[12] = 0;
	retMatrix.m[13] = 0;
	retMatrix.m[14] = 0;
	retMatrix.m[15] = 1;
	
	return retMatrix;
}

TZMatrix TZQuaternion::toRotationMatrix()
{
	TZMatrix retMatrix;
	
	float half_angle_radian = degree2radian( this->w ) * 0.5f;
	TZVector3D unitAxis = TZVector3D(this->x,this->y,this->z).unit();
	
	TZQuaternion unitQ = TZQuaternion( cos(half_angle_radian), unitAxis * sin(half_angle_radian) );
	
	retMatrix.m[0] = 1.0f-2.0f*( unitQ.y * unitQ.y  +  unitQ.z * unitQ.z );
	retMatrix.m[1] = 2.0f*( unitQ.x * unitQ.y  -  unitQ.w * unitQ.z );
	retMatrix.m[2] = 2.0f*( unitQ.x * unitQ.z  +  unitQ.w * unitQ.y );
	retMatrix.m[3] = 0.0f;
	
	retMatrix.m[4] = 2.0f*( unitQ.x * unitQ.y  +  unitQ.w * unitQ.z );
	retMatrix.m[5] = 1.0f-2.0f*( unitQ.x * unitQ.x  +  unitQ.z * unitQ.z );
	retMatrix.m[6] = 2.0f*( unitQ.y * unitQ.z  -  unitQ.w * unitQ.x );
	retMatrix.m[7] = 0.0f;
	
	retMatrix.m[8] = 2.0f*( unitQ.x * unitQ.z  -  unitQ.w * unitQ.y );
	retMatrix.m[9] = 2.0f*( unitQ.y * unitQ.z  +  unitQ.w * unitQ.x );
	retMatrix.m[10] = 1.0f-2.0f*( unitQ.x * unitQ.x  +  unitQ.y * unitQ.y );
	retMatrix.m[11] = 0.0f;
	
	retMatrix.m[12] = 0.0f;
	retMatrix.m[13] = 0.0f;
	retMatrix.m[14] = 0.0f;
	retMatrix.m[15] = 1.0f;
	
	return retMatrix;
}


void TZQuaternion::slerp( TZVector3D start, TZVector3D end, const float t_0to1 )
{
	TZVector3D normalV = start.cross(end);
	this->axisRotate( radian2degree(t_0to1*acos(start.dot(end)/(start.length()*end.length()))), normalV );
}
