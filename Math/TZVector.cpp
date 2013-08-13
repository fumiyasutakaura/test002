/*
 *  vector3D.cpp
 *  Test349248284985
 *
 *  Created by fumiyasu takaura on 10/10/30.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "TZVector.hpp"
#include <iostream>
#include <math.h>


TZVector3D::TZVector3D()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

TZVector3D::TZVector3D( const float arg_x, const float arg_y , const float arg_z )
{
	this->x = arg_x;
	this->y = arg_y;
	this->z = arg_z;
}

TZVector3D::~TZVector3D()
{
	
}



void TZVector3D::printTZVector3D()
{
	std::cout << "TZVector3D( " << this->x << ", " << this->y << ", " << this->z << " )" << std::endl;
}


void TZVector3D::operator=( const TZVector3D &vector3D )
{
	this->x = vector3D.x;
	this->y = vector3D.y;
	this->z = vector3D.z;
}

TZVector3D TZVector3D::operator+( const TZVector3D &vector3D ) const
{
	return TZVector3D( this->x + vector3D.x, this->y + vector3D.y, this->z + vector3D.z );	
}

void TZVector3D::operator+=( const TZVector3D &vector3D )
{
	this->x += vector3D.x;
	this->y += vector3D.y;
	this->z += vector3D.z;
}

TZVector3D TZVector3D::operator-( const TZVector3D &vector3D ) const
{
	return TZVector3D( this->x - vector3D.x, this->y - vector3D.y, this->z - vector3D.z );
}

void TZVector3D::operator-=( const TZVector3D &vector3D )
{
	this->x -= vector3D.x;
	this->y -= vector3D.y;
	this->z -= vector3D.z;
}

TZVector3D TZVector3D::operator*( const float scale ) const
{
	return TZVector3D( this->x * scale, this->y * scale, this->z * scale );
}

TZVector3D TZVector3D::operator/( const float denominator ) const
{
	return TZVector3D( this->x / denominator, this->y / denominator, this->z / denominator );
}

bool TZVector3D::operator==( const TZVector3D &vector3D ) const
{
	return (this->x == vector3D.x  &&  this->y == vector3D.y  &&  this->z == vector3D.z);
}

float& TZVector3D::operator[](int index) {
	return this->v[index];
}

void TZVector3D::print( std::string tag )
{
	std::cout << tag << "(" << this->x << "," << this->y << "," << this->z << ")" << std::endl;
}

float TZVector3D::vectorLength()
{
	return sqrt( this->x * this->x + this->y * this->y + this->z * this->z );
}

TZVector3D TZVector3D::unitTZVector3D()
{
	return *this / sqrt( this->x * this->x + this->y * this->y + this->z * this->z );
}

void TZVector3D::makeUnit()
{
	float denominator = sqrt( this->x * this->x + this->y * this->y + this->z * this->z );

	this->x /= denominator;
	this->y /= denominator;
	this->z /= denominator;
	
}


float TZVector3D::dot( const TZVector3D &vector3D ) const
{
	return this->x * vector3D.x + this->y * vector3D.y + this->z * vector3D.z;
}


TZVector3D TZVector3D::cross( const TZVector3D &vector3D ) const
{
	return TZVector3D(this->y * vector3D.z - this->z * vector3D.y,
					this->z * vector3D.x - this->x * vector3D.z,
					this->x * vector3D.y - this->y * vector3D.x );
}
