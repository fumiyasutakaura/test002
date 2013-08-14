/*
 *  matrix.cpp
 *  Ninteru3DMacOSX
 *
 *  Created by Fumiyasu Takaura on 1/16/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "TZMatrix.hpp"
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


TZMatrix::TZMatrix()
{
	this->m[0] = 1;	this->m[1] = 0;	this->m[2] = 0;	this->m[3] = 0;
	this->m[4] = 0; this->m[5] = 1;	this->m[6] = 0;	this->m[7] = 0;
	this->m[8] = 0;	this->m[9] = 0;	this->m[10] = 1; this->m[11] = 0;
	this->m[12] = 0; this->m[13] = 0; this->m[14] = 0; this->m[15] = 1;
}

TZMatrix::TZMatrix(const float a[16])
{
	this->m[0] = a[0]; this->m[1] = a[1]; this->m[2] = a[2]; this->m[3] = a[3];
	this->m[4] = a[4]; this->m[5] = a[5]; this->m[6] = a[6]; this->m[7] = a[7];	
	this->m[8] = a[8]; this->m[9] = a[9]; this->m[10] = a[10]; this->m[11] = a[11];
	this->m[12] = a[12]; this->m[13] = a[13]; this->m[14] = a[14]; this->m[15] = a[15];
}

TZMatrix::TZMatrix(const float a11, const float a12, const float a13, const float a14,
		  const float a21, const float a22, const float a23, const float a24,
		  const float a31, const float a32, const float a33, const float a34,
		  const float a41, const float a42, const float a43, const float a44)
{
	this->m[0] = a11; this->m[1] = a12; this->m[2] = a13; this->m[3] = a14;
	this->m[4] = a21; this->m[5] = a22; this->m[6] = a23; this->m[7] = a24;	
	this->m[8] = a31; this->m[9] = a32; this->m[10] = a33; this->m[11] = a34;
	this->m[12] = a41; this->m[13] = a42; this->m[14] = a43; this->m[15] = a44;
}


TZMatrix::TZMatrix(const TZMatrix &matrix )
{
	this->m[0] = matrix.m[0]; this->m[1] = matrix.m[1]; this->m[2] = matrix.m[2]; this->m[3] = matrix.m[3];
	this->m[4] = matrix.m[4]; this->m[5] = matrix.m[5]; this->m[6] = matrix.m[6]; this->m[7] = matrix.m[7];	
	this->m[8] = matrix.m[8]; this->m[9] = matrix.m[9]; this->m[10] = matrix.m[10]; this->m[11] = matrix.m[11];
	this->m[12] = matrix.m[12]; this->m[13] = matrix.m[13]; this->m[14] = matrix.m[14]; this->m[15] = matrix.m[15];
}

TZMatrix::~TZMatrix()
{
	
}






bool TZMatrix::operator==( const TZMatrix &matrix ) const
{
	if( this->m[0] == matrix.m[0] && this->m[1] == matrix.m[1] && this->m[2] == matrix.m[2] && this->m[3] == matrix.m[3]         && 
	    this->m[4] == matrix.m[4] && this->m[5] == matrix.m[5] && this->m[6] == matrix.m[6] && this->m[7] == matrix.m[7]         && 
	    this->m[8] == matrix.m[8] && this->m[9] == matrix.m[9] && this->m[10] == matrix.m[10] && this->m[11] == matrix.m[11]     && 
	    this->m[12] == matrix.m[12] && this->m[13] == matrix.m[13] && this->m[14] == matrix.m[14] && this->m[15] == matrix.m[15]   )
	{
		return true;
	}
	
	return false;
}

void TZMatrix::operator+=( const TZMatrix &matrix )
{
	
	this->m[0] += matrix.m[0]; this->m[1] += matrix.m[1]; this->m[2] += matrix.m[2]; this->m[3] += matrix.m[3]; 
	this->m[4] += matrix.m[4]; this->m[5] += matrix.m[5]; this->m[6] += matrix.m[6]; this->m[7] += matrix.m[7]; 
	this->m[8] += matrix.m[8]; this->m[9] += matrix.m[9]; this->m[10] += matrix.m[10]; this->m[11] += matrix.m[11]; 
	this->m[12] += matrix.m[12]; this->m[13] += matrix.m[13]; this->m[14] += matrix.m[14]; this->m[15] += matrix.m[15];
}

TZMatrix TZMatrix::operator+( const TZMatrix &matrix ) const
{
	TZMatrix retMatrix;
	
	retMatrix.m[0] = this->m[0] + matrix.m[0]; retMatrix.m[1] = this->m[1] + matrix.m[1]; retMatrix.m[2] = this->m[2] + matrix.m[2]; retMatrix.m[3] = this->m[3] + matrix.m[3]; 
	retMatrix.m[4] = this->m[4] + matrix.m[4]; retMatrix.m[5] = this->m[5] + matrix.m[5]; retMatrix.m[6] = this->m[6] + matrix.m[6]; retMatrix.m[7] = this->m[7] + matrix.m[7]; 
	retMatrix.m[8] = this->m[8] + matrix.m[8]; retMatrix.m[9] = this->m[9] + matrix.m[9]; retMatrix.m[10] = this->m[10] + matrix.m[10]; retMatrix.m[11] = this->m[11] + matrix.m[11]; 
	retMatrix.m[12] = this->m[12] + matrix.m[12]; retMatrix.m[13] = this->m[13] + matrix.m[13]; retMatrix.m[14] = this->m[14] + matrix.m[14]; retMatrix.m[15] = this->m[15] + matrix.m[15];
	
	return retMatrix;
}


void TZMatrix::operator-=( const TZMatrix &matrix )
{
	
	this->m[0] -= matrix.m[0]; this->m[1] -= matrix.m[1]; this->m[2] -= matrix.m[2]; this->m[3] -= matrix.m[3]; 
	this->m[4] -= matrix.m[4]; this->m[5] -= matrix.m[5]; this->m[6] -= matrix.m[6]; this->m[7] -= matrix.m[7]; 
	this->m[8] -= matrix.m[8]; this->m[9] -= matrix.m[9]; this->m[10] -= matrix.m[10]; this->m[11] -= matrix.m[11]; 
	this->m[12] -= matrix.m[12]; this->m[13] -= matrix.m[13]; this->m[14] -= matrix.m[14]; this->m[15] -= matrix.m[15];
}

TZMatrix TZMatrix::operator-( const TZMatrix &matrix ) const
{
	TZMatrix retMatrix;
	
	retMatrix.m[0] = this->m[0] - matrix.m[0]; retMatrix.m[1] = this->m[1] - matrix.m[1]; retMatrix.m[2] = this->m[2] - matrix.m[2]; retMatrix.m[3] = this->m[3] - matrix.m[3]; 
	retMatrix.m[4] = this->m[4] - matrix.m[4]; retMatrix.m[5] = this->m[5] - matrix.m[5]; retMatrix.m[6] = this->m[6] - matrix.m[6]; retMatrix.m[7] = this->m[7] - matrix.m[7]; 
	retMatrix.m[8] = this->m[8] - matrix.m[8]; retMatrix.m[9] = this->m[9] - matrix.m[9]; retMatrix.m[10] = this->m[10] - matrix.m[10]; retMatrix.m[11] = this->m[11] - matrix.m[11]; 
	retMatrix.m[12] = this->m[12] - matrix.m[12]; retMatrix.m[13] = this->m[13] - matrix.m[13]; retMatrix.m[14] = this->m[14] - matrix.m[14]; retMatrix.m[15] = this->m[15] - matrix.m[15];
	
	return retMatrix;
}


void TZMatrix::operator*=( const float scala )
{
	this->m[0] *= scala; this->m[1] *= scala; this->m[2] *= scala; this->m[3] *= scala;
	this->m[4] *= scala; this->m[5] *= scala; this->m[6] *= scala; this->m[7] *= scala;
	this->m[8] *= scala; this->m[9] *= scala; this->m[10] *= scala; this->m[11] *= scala; 
	this->m[12] *= scala; this->m[13] *= scala; this->m[14] *= scala; this->m[15] *= scala;
}

TZMatrix TZMatrix::operator*( const float scala ) const
{
	TZMatrix retMatrix;
	
	retMatrix.m[0] = this->m[0] * scala; retMatrix.m[1] = this->m[1] * scala; retMatrix.m[2] = this->m[2] * scala; retMatrix.m[3] = this->m[3] * scala;
	retMatrix.m[4] = this->m[4] * scala; retMatrix.m[5] = this->m[5] * scala; retMatrix.m[6] = this->m[6] * scala; retMatrix.m[7] = this->m[7] * scala;
	retMatrix.m[8] = this->m[8] * scala; retMatrix.m[9] = this->m[9] * scala; retMatrix.m[10] = this->m[10] * scala; retMatrix.m[11] = this->m[11] * scala; 
	retMatrix.m[12] = this->m[12] * scala; retMatrix.m[13] = this->m[13] * scala; retMatrix.m[14] = this->m[14] * scala; retMatrix.m[15] = this->m[15] * scala;
	
	return retMatrix;
}

void TZMatrix::operator*=( const TZMatrix &matrix )
{
	const TZMatrix tempMatrix = *this;
	
	this->m[0] = tempMatrix.m[0] * matrix.m[0] + tempMatrix.m[1] * matrix.m[4] + tempMatrix.m[2] * matrix.m[8] + tempMatrix.m[3] * matrix.m[12];
	this->m[1] = tempMatrix.m[0] * matrix.m[1] + tempMatrix.m[1] * matrix.m[5] + tempMatrix.m[2] * matrix.m[9] + tempMatrix.m[3] * matrix.m[13];
	this->m[2] = tempMatrix.m[0] * matrix.m[2] + tempMatrix.m[1] * matrix.m[6] + tempMatrix.m[2] * matrix.m[10] + tempMatrix.m[3] * matrix.m[14];
	this->m[3] = tempMatrix.m[0] * matrix.m[3] + tempMatrix.m[1] * matrix.m[7] + tempMatrix.m[2] * matrix.m[11] + tempMatrix.m[3] * matrix.m[15];
	
	this->m[4] = tempMatrix.m[4] * matrix.m[0] + tempMatrix.m[5] * matrix.m[4] + tempMatrix.m[6] * matrix.m[8] + tempMatrix.m[7] * matrix.m[12];
	this->m[5] = tempMatrix.m[4] * matrix.m[1] + tempMatrix.m[5] * matrix.m[5] + tempMatrix.m[6] * matrix.m[9] + tempMatrix.m[7] * matrix.m[13];
	this->m[6] = tempMatrix.m[4] * matrix.m[2] + tempMatrix.m[5] * matrix.m[6] + tempMatrix.m[6] * matrix.m[10] + tempMatrix.m[7] * matrix.m[14];
	this->m[7] = tempMatrix.m[4] * matrix.m[3] + tempMatrix.m[5] * matrix.m[7] + tempMatrix.m[6] * matrix.m[11] + tempMatrix.m[7] * matrix.m[15];
	
	this->m[8] = tempMatrix.m[8] * matrix.m[0] + tempMatrix.m[9] * matrix.m[4] + tempMatrix.m[10] * matrix.m[8] + tempMatrix.m[11] * matrix.m[12];
	this->m[9] = tempMatrix.m[8] * matrix.m[1] + tempMatrix.m[9] * matrix.m[5] + tempMatrix.m[10] * matrix.m[9] + tempMatrix.m[11] * matrix.m[13];
	this->m[10] = tempMatrix.m[8] * matrix.m[2] + tempMatrix.m[9] * matrix.m[6] + tempMatrix.m[10] * matrix.m[10] + tempMatrix.m[11] * matrix.m[14];
	this->m[11] = tempMatrix.m[8] * matrix.m[3] + tempMatrix.m[9] * matrix.m[7] + tempMatrix.m[10] * matrix.m[11] + tempMatrix.m[11] * matrix.m[15];
	
	this->m[12] = tempMatrix.m[12] * matrix.m[0] + tempMatrix.m[13] * matrix.m[4] + tempMatrix.m[14] * matrix.m[8] + tempMatrix.m[15] * matrix.m[12];
	this->m[13] = tempMatrix.m[12] * matrix.m[1] + tempMatrix.m[13] * matrix.m[5] + tempMatrix.m[14] * matrix.m[9] + tempMatrix.m[15] * matrix.m[13];
	this->m[14] = tempMatrix.m[12] * matrix.m[2] + tempMatrix.m[13] * matrix.m[6] + tempMatrix.m[14] * matrix.m[10] + tempMatrix.m[15] * matrix.m[14];
	this->m[15] = tempMatrix.m[12] * matrix.m[3] + tempMatrix.m[13] * matrix.m[7] + tempMatrix.m[14] * matrix.m[11] + tempMatrix.m[15] * matrix.m[15];
}

TZMatrix TZMatrix::operator*( const TZMatrix &matrix ) const
{
	TZMatrix retMatrix;
	
	retMatrix.m[0] = this->m[0] * matrix.m[0] + this->m[1] * matrix.m[4] + this->m[2] * matrix.m[8] + this->m[3] * matrix.m[12];
	retMatrix.m[1] = this->m[0] * matrix.m[1] + this->m[1] * matrix.m[5] + this->m[2] * matrix.m[9] + this->m[3] * matrix.m[13];
	retMatrix.m[2] = this->m[0] * matrix.m[2] + this->m[1] * matrix.m[6] + this->m[2] * matrix.m[10] + this->m[3] * matrix.m[14];
	retMatrix.m[3] = this->m[0] * matrix.m[3] + this->m[1] * matrix.m[7] + this->m[2] * matrix.m[11] + this->m[3] * matrix.m[15];
	
	retMatrix.m[4] = this->m[4] * matrix.m[0] + this->m[5] * matrix.m[4] + this->m[6] * matrix.m[8] + this->m[7] * matrix.m[12];
	retMatrix.m[5] = this->m[4] * matrix.m[1] + this->m[5] * matrix.m[5] + this->m[6] * matrix.m[9] + this->m[7] * matrix.m[13];
	retMatrix.m[6] = this->m[4] * matrix.m[2] + this->m[5] * matrix.m[6] + this->m[6] * matrix.m[10] + this->m[7] * matrix.m[14];
	retMatrix.m[7] = this->m[4] * matrix.m[3] + this->m[5] * matrix.m[7] + this->m[6] * matrix.m[11] + this->m[7] * matrix.m[15];
	
	retMatrix.m[8] = this->m[8] * matrix.m[0] + this->m[9] * matrix.m[4] + this->m[10] * matrix.m[8] + this->m[11] * matrix.m[12];
	retMatrix.m[9] = this->m[8] * matrix.m[1] + this->m[9] * matrix.m[5] + this->m[10] * matrix.m[9] + this->m[11] * matrix.m[13];
	retMatrix.m[10] = this->m[8] * matrix.m[2] + this->m[9] * matrix.m[6] + this->m[10] * matrix.m[10] + this->m[11] * matrix.m[14];
	retMatrix.m[11] = this->m[8] * matrix.m[3] + this->m[9] * matrix.m[7] + this->m[10] * matrix.m[11] + this->m[11] * matrix.m[15];
	
	retMatrix.m[12] = this->m[12] * matrix.m[0] + this->m[13] * matrix.m[4] + this->m[14] * matrix.m[8] + this->m[15] * matrix.m[12];
	retMatrix.m[13] = this->m[12] * matrix.m[1] + this->m[13] * matrix.m[5] + this->m[14] * matrix.m[9] + this->m[15] * matrix.m[13];
	retMatrix.m[14] = this->m[12] * matrix.m[2] + this->m[13] * matrix.m[6] + this->m[14] * matrix.m[10] + this->m[15] * matrix.m[14];
	retMatrix.m[15] = this->m[12] * matrix.m[3] + this->m[13] * matrix.m[7] + this->m[14] * matrix.m[11] + this->m[15] * matrix.m[15];
	
	return retMatrix;
}

TZVector3D  TZMatrix::operator*( const TZVector3D &vector3D ) const
{
	TZVector3D retVector3D;
	/* const int w = 1; */
	
	retVector3D.x = this->m[0] * vector3D.x + this->m[1] * vector3D.y + this->m[2] * vector3D.z + this->m[3]/* * w */;
	retVector3D.y = this->m[4] * vector3D.x + this->m[5] * vector3D.y + this->m[6] * vector3D.z + this->m[7]/* * w */;
	retVector3D.z = this->m[8] * vector3D.x + this->m[9] * vector3D.y + this->m[10] * vector3D.z + this->m[11]/* * w */;
	
	return retVector3D;
}

void TZMatrix::operator/=( const float denominator )
{
	this->m[0] /= denominator; this->m[1] /= denominator; this->m[2] /= denominator; this->m[3] /= denominator;
	this->m[4] /= denominator; this->m[5] /= denominator; this->m[6] /= denominator; this->m[7] /= denominator;
	this->m[8] /= denominator; this->m[9] /= denominator; this->m[10] /= denominator; this->m[11] /= denominator; 
	this->m[12] /= denominator; this->m[13] /= denominator; this->m[14] /= denominator; this->m[15] /= denominator;
}

TZMatrix TZMatrix::operator/( const float denominator ) const
{
	TZMatrix retMatrix;
	
	retMatrix.m[0] = this->m[0] / denominator; retMatrix.m[1] = this->m[1] / denominator; retMatrix.m[2] = this->m[2] / denominator; retMatrix.m[3] = this->m[3] / denominator;
	retMatrix.m[4] = this->m[4] / denominator; retMatrix.m[5] = this->m[5] / denominator; retMatrix.m[6] = this->m[6] / denominator; retMatrix.m[7] = this->m[7] / denominator;
	retMatrix.m[8] = this->m[8] / denominator; retMatrix.m[9] = this->m[9] / denominator; retMatrix.m[10] = this->m[10] / denominator; retMatrix.m[11] = this->m[11] / denominator; 
	retMatrix.m[12] = this->m[12] / denominator; retMatrix.m[13] = this->m[13] / denominator; retMatrix.m[14] = this->m[14] / denominator; retMatrix.m[15] = this->m[15] / denominator;
	
	return retMatrix;
}

float& TZMatrix::operator[]( const int index ) {
	return this->m[index];
}



void TZMatrix::print( std::string tag )
{
	std::cout << tag << " =" << std::endl;
	std::cout << "| " << this->m[0] << " " << this->m[1] << " " << this->m[2] << " " << this->m[3] << " |" << std::endl;
	std::cout << "| " << this->m[4] << " " << this->m[5] << " " << this->m[6] << " " << this->m[7] << " |" << std::endl;
	std::cout << "| " << this->m[8] << " " << this->m[9] << " " << this->m[10] << " " << this->m[11] << " |" << std::endl;
	std::cout << "| " << this->m[12] << " " << this->m[13] << " " << this->m[14] << " " << this->m[15] << " |" << std::endl;
}


void TZMatrix::loadIdentity()
{
	this->m[0] = 1;	this->m[1] = 0;	this->m[2] = 0;	this->m[3] = 0;
	this->m[4] = 0; this->m[5] = 1;	this->m[6] = 0;	this->m[7] = 0;
	this->m[8] = 0;	this->m[9] = 0;	this->m[10] = 1; this->m[11] = 0;
	this->m[12] = 0; this->m[13] = 0; this->m[14] = 0; this->m[15] = 1;
}


std::pair<bool,TZMatrix> TZMatrix::invert()
{
	float det = this->det();
	
	if( det == 0.0 )
	{
		return std::pair<bool,TZMatrix>( false, TZMatrix(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0) );
	}
	
	TZMatrix retMatrix;
	
	retMatrix.m[0]  = this->m[5] * this->m[10] * this->m[15]  +  this->m[6] * this->m[11] * this->m[13]  +  this->m[7] * this->m[9] * this->m[14]  -  this->m[5] * this->m[11] * this->m[14]  -  this->m[6] * this->m[9] * this->m[15]  -  this->m[7] * this->m[10] * this->m[13];
	retMatrix.m[1]  = this->m[1] * this->m[11] * this->m[14]  +  this->m[2] * this->m[9] * this->m[15]  +  this->m[3] * this->m[10] * this->m[13]  -  this->m[1] * this->m[10] * this->m[15]  -  this->m[2] * this->m[11] * this->m[13]  -  this->m[3] * this->m[9] * this->m[14];
	retMatrix.m[2]  = this->m[1] * this->m[6] * this->m[15]  +  this->m[2] * this->m[7] * this->m[13]  +  this->m[3] * this->m[5] * this->m[14]  -  this->m[1] * this->m[7] * this->m[14]  -  this->m[2] * this->m[5] * this->m[15]  -  this->m[3] * this->m[6] * this->m[13];
	retMatrix.m[3]  = this->m[1] * this->m[7] * this->m[10]  +  this->m[2] * this->m[5] * this->m[11]  +  this->m[3] * this->m[6] * this->m[9]  -  this->m[1] * this->m[6] * this->m[11]  -  this->m[2] * this->m[7] * this->m[9]  -  this->m[3] * this->m[5] * this->m[10];
	retMatrix.m[4]  = this->m[4] * this->m[11] * this->m[14]  +  this->m[6] * this->m[8] * this->m[15]  +  this->m[7] * this->m[10] * this->m[12]  -  this->m[4] * this->m[10] * this->m[15]  -  this->m[6] * this->m[11] * this->m[12]  -  this->m[7] * this->m[8] * this->m[14];
	retMatrix.m[5]  = this->m[0] * this->m[10] * this->m[15]  +  this->m[2] * this->m[11] * this->m[12]  +  this->m[3] * this->m[8] * this->m[14]  -  this->m[0] * this->m[11] * this->m[14]  -  this->m[2] * this->m[8] * this->m[15]  -  this->m[3] * this->m[10] * this->m[12];
	retMatrix.m[6]  = this->m[0] * this->m[7] * this->m[14]  +  this->m[2] * this->m[4] * this->m[15]  +  this->m[3] * this->m[6] * this->m[12]  -  this->m[0] * this->m[6] * this->m[15]  -  this->m[2] * this->m[7] * this->m[12]  -  this->m[3] * this->m[4] * this->m[14];
	retMatrix.m[7]  = this->m[0] * this->m[6] * this->m[11]  +  this->m[2] * this->m[7] * this->m[8]  +  this->m[3] * this->m[4] * this->m[10]  -  this->m[0] * this->m[7] * this->m[10]  -  this->m[2] * this->m[4] * this->m[11]  -  this->m[3] * this->m[6] * this->m[8];
	retMatrix.m[8]  = this->m[4] * this->m[9] * this->m[15]  +  this->m[5] * this->m[11] * this->m[12]  +  this->m[7] * this->m[8] * this->m[13]  -  this->m[4] * this->m[11] * this->m[13]  -  this->m[5] * this->m[8] * this->m[15]  -  this->m[7] * this->m[9] * this->m[12];
	retMatrix.m[9]  = this->m[0] * this->m[11] * this->m[13]  +  this->m[1] * this->m[8] * this->m[15]  +  this->m[3] * this->m[9] * this->m[12]  -  this->m[0] * this->m[9] * this->m[15]  -  this->m[1] * this->m[11] * this->m[12]  -  this->m[3] * this->m[8] * this->m[13];
	retMatrix.m[10] = this->m[0] * this->m[5] * this->m[15]  +  this->m[1] * this->m[7] * this->m[12]  +  this->m[3] * this->m[4] * this->m[13]  -  this->m[0] * this->m[7] * this->m[13]  -  this->m[1] * this->m[4] * this->m[15]  -  this->m[3] * this->m[5] * this->m[12];
	retMatrix.m[11] = this->m[0] * this->m[7] * this->m[9]  +  this->m[1] * this->m[4] * this->m[11]  +  this->m[3] * this->m[5] * this->m[8]  -  this->m[0] * this->m[5] * this->m[11]  -  this->m[1] * this->m[7] * this->m[8]  -  this->m[3] * this->m[4] * this->m[9];
	retMatrix.m[12] = this->m[4] * this->m[10] * this->m[13]  +  this->m[5] * this->m[8] * this->m[14]  +  this->m[6] * this->m[9] * this->m[12]  -  this->m[4] * this->m[9] * this->m[14]  -  this->m[5] * this->m[10] * this->m[12]  -  this->m[6] * this->m[8] * this->m[13];
	retMatrix.m[13] = this->m[0] * this->m[9] * this->m[14]  +  this->m[1] * this->m[10] * this->m[12]  +  this->m[2] * this->m[8] * this->m[13]  -  this->m[0] * this->m[10] * this->m[13]  -  this->m[1] * this->m[8] * this->m[14]  -  this->m[2] * this->m[9] * this->m[12];
	retMatrix.m[14] = this->m[0] * this->m[6] * this->m[13]  +  this->m[1] * this->m[4] * this->m[14]  +  this->m[2] * this->m[5] * this->m[12]  -  this->m[0] * this->m[5] * this->m[14]  -  this->m[1] * this->m[6] * this->m[12]  -  this->m[2] * this->m[4] * this->m[13];
	retMatrix.m[15] = this->m[0] * this->m[5] * this->m[10]  +  this->m[1] * this->m[6] * this->m[8]  +  this->m[2] * this->m[4] * this->m[9]  -  this->m[0] * this->m[6] * this->m[9]  -  this->m[1] * this->m[4] * this->m[10]  -  this->m[2] * this->m[5] * this->m[8];
	retMatrix = retMatrix * (1.0/det);
	
	return std::pair<bool,TZMatrix>( true, retMatrix );
}


float TZMatrix::det()
{
	float ret;
	
	ret =   this->m[0] * this->m[5] * this->m[10] * this->m[15]  +  this->m[0] * this->m[6] * this->m[11] * this->m[13]  +  this->m[0] * this->m[7] * this->m[9] * this->m[14]
	      + this->m[1] * this->m[4] * this->m[11] * this->m[14]  +  this->m[1] * this->m[6] * this->m[8] * this->m[15]  +  this->m[1] * this->m[7] * this->m[10] * this->m[12]
	      + this->m[2] * this->m[4] * this->m[9] * this->m[15]  +  this->m[2] * this->m[5] * this->m[11] * this->m[12]  +  this->m[2] * this->m[7] * this->m[8] * this->m[13]
	      + this->m[3] * this->m[4] * this->m[10] * this->m[13]  +  this->m[3] * this->m[5] * this->m[8] * this->m[14]  +  this->m[3] * this->m[6] * this->m[9] * this->m[12]
	      - this->m[0] * this->m[5] * this->m[11] * this->m[14]  -  this->m[0] * this->m[6] * this->m[9] * this->m[15]  -  this->m[0] * this->m[7] * this->m[10] * this->m[13]
	      - this->m[1] * this->m[4] * this->m[10] * this->m[15]  -  this->m[1] * this->m[6] * this->m[11] * this->m[12]  -  this->m[1] * this->m[7] * this->m[8] * this->m[14]
	      - this->m[2] * this->m[4] * this->m[11] * this->m[13]  -  this->m[2] * this->m[5] * this->m[8] * this->m[15]  -  this->m[2] * this->m[7] * this->m[9] * this->m[12]
	      - this->m[3] * this->m[4] * this->m[9] * this->m[14]  -  this->m[3] * this->m[5] * this->m[10] * this->m[12]  -  this->m[3] * this->m[6] * this->m[8] * this->m[13]
	      ;
	
	return ret;
}


void TZMatrix::transpose()
{
	TZMatrix tempMatrix(*this);
	
	/*this->m[0] = tempMatrix.m[0];*/
	this->m[1] = tempMatrix.m[4];
	this->m[2] = tempMatrix.m[8];
	this->m[3] = tempMatrix.m[12];
	
	this->m[4] = tempMatrix.m[1];
	//this->m[5] = tempMatrix.m[5];
	this->m[6] = tempMatrix.m[9];
	this->m[7] = tempMatrix.m[13];
	
	this->m[8] = tempMatrix.m[2];
	this->m[9] = tempMatrix.m[6];
	//this->m[10] = tempMatrix.m[10];
	this->m[11] = tempMatrix.m[14];
	
	this->m[12] = tempMatrix.m[3];
	this->m[13] = tempMatrix.m[7];
	this->m[14] = tempMatrix.m[11];
	//this->m[15] = tempMatrix.m[15];
	
}




void TZMatrix::scale( const float scale_xyz )
{
	this->m[0] *= scale_xyz;
	this->m[5] *= scale_xyz;
	this->m[10] *= scale_xyz;
}
void TZMatrix::scale( const float scale_x, const float scale_y, const float scale_z )
{
	this->m[0] *= scale_x;
	this->m[5] *= scale_y;
	this->m[10] *= scale_z;	
}


void TZMatrix::translate( TZVector3D &positionVec )
{
	this->m[3] += positionVec.x;
	this->m[7] += positionVec.y;
	this->m[11] += positionVec.z;
}

void TZMatrix::axisRotate( const float angle_degree, TZVector3D &axis )
{
	/*
	TZQuaternion q(0,0,0,1);
	q.axisRotate( angle_degree, axis );
	 */
	float half_radian = degree2radian(angle_degree * 0.5);
	TZQuaternion q( cos(half_radian), axis.unitTZVector3D() * sin(half_radian) );

	*this *= q.toMatrix();
}



TZMatrix TZMatrix::Translate( TZVector3D positionVec ) {
    TZMatrix ret;
	ret.m[3] = positionVec.x;
	ret.m[7] = positionVec.y;
	ret.m[11] = positionVec.z;
    return ret;
}

TZMatrix TZMatrix::AxisRotate( const float angle_degree, TZVector3D axis ) {
    TZMatrix ret;
	float half_radian = degree2radian(angle_degree * 0.5);
	TZQuaternion q( cos(half_radian), axis.unitVector3D() * sin(half_radian) );
	ret *= q.toMatrix();
    return ret;
}

TZMatrix TZMatrix::Projection(const int screenW, const int screenH,
                              const float angleOfView_Degree,
                              const float abs_near, const float abs_far ) {
    const float far = - abs_far;
    const float near = -abs_near;
    TZMatrix ret;
    const float cot = - 1.0f / tanf( degree2radian(angleOfView_Degree*0.5) );
    const float reciprocal_far_near = 1.0f / (far - near);
    ret.m11 = ((float)screenH / (float)screenW) * cot;
    ret.m22 = cot;
    ret.m33 = far * reciprocal_far_near;
    ret.m34 = -far * near * reciprocal_far_near;
    ret.m43 = -1.0f;
    ret.m44 = 0.0f;
    return ret;
}
