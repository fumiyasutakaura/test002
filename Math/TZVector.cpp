/*
 *  vector3D.cpp
 *  Test349248284985
 *
 *  Created by fumiyasu takaura on 10/10/30.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "TZVector.hpp"
#include <math.h>

using namespace TZulu;

TZVector3D::TZVector3D()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

TZVector3D::TZVector3D( const float arg_x, const float arg_y , const float arg_z )
{
	x = arg_x;
	y = arg_y;
	z = arg_z;
}

TZVector3D::TZVector3D( const TZVector3D& v )
{
    x = v.x;
    y = v.y;
    z = v.z;
}

TZVector3D::~TZVector3D()
{
	
}

void TZVector3D::operator=( const TZVector3D &vector3D )
{
	x = vector3D.x;
	y = vector3D.y;
	z = vector3D.z;
}

TZVector3D TZVector3D::operator+( const TZVector3D &vector3D ) const
{
	return TZVector3D( x + vector3D.x, y + vector3D.y, z + vector3D.z );	
}

void TZVector3D::operator+=( const TZVector3D &vector3D )
{
	x += vector3D.x;
	y += vector3D.y;
	z += vector3D.z;
}

TZVector3D TZVector3D::operator-( const TZVector3D &vector3D ) const
{
	return TZVector3D( x - vector3D.x, y - vector3D.y, z - vector3D.z );
}

void TZVector3D::operator-=( const TZVector3D &vector3D )
{
	x -= vector3D.x;
	y -= vector3D.y;
	z -= vector3D.z;
}

TZVector3D TZVector3D::operator*( const float scale ) const
{
	return TZVector3D( x * scale, y * scale, z * scale );
}

TZVector3D TZVector3D::operator/( const float denominator ) const
{
	return TZVector3D( x / denominator, y / denominator, z / denominator );
}

float& TZVector3D::operator[](int index) {
	return v[index];
}

void TZVector3D::print( std::string tag ) const
{
	printf("%s(%f, %f, %f)\n", tag.c_str(), x, y, z);
}

float TZVector3D::length() const
{
	return sqrt( x * x + y * y + z * z );
}

TZVector3D TZVector3D::unit() const
{
	return *this / sqrt( x * x + y * y + z * z );
}

float TZVector3D::dot( const TZVector3D &vector3D ) const
{
	return x * vector3D.x + y * vector3D.y + z * vector3D.z;
}


TZVector3D TZVector3D::cross( const TZVector3D &vector3D ) const
{
	return TZVector3D(y * vector3D.z - z * vector3D.y,
					  z * vector3D.x - x * vector3D.z,
					  x * vector3D.y - y * vector3D.x );
}
