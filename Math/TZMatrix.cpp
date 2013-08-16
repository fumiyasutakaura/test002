/*
 * matrix.cpp
 *  Ninteru3DMacOSX
 *
 *  Created by Fumiyasu Takaura on 1/16/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "TZMatrix.hpp"
#include "TZQuaternion.hpp"
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

static const float UnitMatrix[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

TZMatrix TZMatrix::Unit()
{
    return TZMatrix();
}

TZMatrix::TZMatrix()
{
    memcpy(m,UnitMatrix,sizeof(float)*16);
}

TZMatrix::TZMatrix(const float a[16])
{
    memcpy(m,a,sizeof(float)*16);
}

TZMatrix::TZMatrix(const float a11, const float a12, const float a13, const float a14,
                   const float a21, const float a22, const float a23, const float a24,
                   const float a31, const float a32, const float a33, const float a34,
                   const float a41, const float a42, const float a43, const float a44)
{
    m[0] = a11; m[1] = a12; m[2] = a13; m[3] = a14;
    m[4] = a21; m[5] = a22; m[6] = a23; m[7] = a24;
    m[8] = a31; m[9] = a32; m[10] = a33; m[11] = a34;
    m[12] = a41; m[13] = a42; m[14] = a43; m[15] = a44;
}


TZMatrix::TZMatrix( const TZMatrix &matrix )
{
    memcpy(m, matrix.m, sizeof(float)*16);
}

TZMatrix::~TZMatrix()
{
	
}




void TZMatrix::operator+=( const TZMatrix &matrix )
{
	
    m[0] += matrix.m[0]; m[1] += matrix.m[1]; m[2] += matrix.m[2]; m[3] += matrix.m[3];
    m[4] += matrix.m[4]; m[5] += matrix.m[5]; m[6] += matrix.m[6]; m[7] += matrix.m[7];
    m[8] += matrix.m[8]; m[9] += matrix.m[9]; m[10] += matrix.m[10]; m[11] += matrix.m[11];
    m[12] += matrix.m[12]; m[13] += matrix.m[13]; m[14] += matrix.m[14]; m[15] += matrix.m[15];
}

TZMatrix TZMatrix::operator+( const TZMatrix &matrix ) const
{
	TZMatrix ret;
	
	ret.m[0] = m[0] + matrix.m[0]; ret.m[1] = m[1] + matrix.m[1]; ret.m[2] = m[2] + matrix.m[2]; ret.m[3] = m[3] + matrix.m[3];
	ret.m[4] = m[4] + matrix.m[4]; ret.m[5] = m[5] + matrix.m[5]; ret.m[6] = m[6] + matrix.m[6]; ret.m[7] = m[7] + matrix.m[7];
	ret.m[8] = m[8] + matrix.m[8]; ret.m[9] = m[9] + matrix.m[9]; ret.m[10] = m[10] + matrix.m[10]; ret.m[11] = m[11] + matrix.m[11];
	ret.m[12] = m[12] + matrix.m[12]; ret.m[13] = m[13] + matrix.m[13]; ret.m[14] = m[14] + matrix.m[14]; ret.m[15] = m[15] + matrix.m[15];
	
	return ret;
}


void TZMatrix::operator-=( const TZMatrix &matrix )
{
	
    m[0] -= matrix.m[0]; m[1] -= matrix.m[1]; m[2] -= matrix.m[2]; m[3] -= matrix.m[3];
    m[4] -= matrix.m[4]; m[5] -= matrix.m[5]; m[6] -= matrix.m[6]; m[7] -= matrix.m[7];
    m[8] -= matrix.m[8]; m[9] -= matrix.m[9]; m[10] -= matrix.m[10]; m[11] -= matrix.m[11];
    m[12] -= matrix.m[12]; m[13] -= matrix.m[13]; m[14] -= matrix.m[14]; m[15] -= matrix.m[15];
}

TZMatrix TZMatrix::operator-( const TZMatrix &matrix ) const
{
	TZMatrix ret;
	
	ret.m[0] = m[0] - matrix.m[0]; ret.m[1] = m[1] - matrix.m[1]; ret.m[2] = m[2] - matrix.m[2]; ret.m[3] = m[3] - matrix.m[3];
	ret.m[4] = m[4] - matrix.m[4]; ret.m[5] = m[5] - matrix.m[5]; ret.m[6] = m[6] - matrix.m[6]; ret.m[7] = m[7] - matrix.m[7];
	ret.m[8] = m[8] - matrix.m[8]; ret.m[9] = m[9] - matrix.m[9]; ret.m[10] = m[10] - matrix.m[10]; ret.m[11] = m[11] - matrix.m[11];
	ret.m[12] = m[12] - matrix.m[12]; ret.m[13] = m[13] - matrix.m[13]; ret.m[14] = m[14] - matrix.m[14]; ret.m[15] = m[15] - matrix.m[15];
	
	return ret;
}


void TZMatrix::operator*=( const float scala )
{
    m[0] *= scala; m[1] *= scala; m[2] *= scala; m[3] *= scala;
    m[4] *= scala; m[5] *= scala; m[6] *= scala; m[7] *= scala;
    m[8] *= scala; m[9] *= scala; m[10] *= scala; m[11] *= scala;
    m[12] *= scala; m[13] *= scala; m[14] *= scala; m[15] *= scala;
}

TZMatrix TZMatrix::operator*( const float scala ) const
{
	TZMatrix ret;
	
	ret.m[0] = m[0] * scala; ret.m[1] = m[1] * scala; ret.m[2] = m[2] * scala; ret.m[3] = m[3] * scala;
	ret.m[4] = m[4] * scala; ret.m[5] = m[5] * scala; ret.m[6] = m[6] * scala; ret.m[7] = m[7] * scala;
	ret.m[8] = m[8] * scala; ret.m[9] = m[9] * scala; ret.m[10] = m[10] * scala; ret.m[11] = m[11] * scala;
	ret.m[12] = m[12] * scala; ret.m[13] = m[13] * scala; ret.m[14] = m[14] * scala; ret.m[15] = m[15] * scala;
	
	return ret;
}

void TZMatrix::operator/=( const float denominator )
{
    m[0] /= denominator; m[1] /= denominator; m[2] /= denominator; m[3] /= denominator;
    m[4] /= denominator; m[5] /= denominator; m[6] /= denominator; m[7] /= denominator;
    m[8] /= denominator; m[9] /= denominator; m[10] /= denominator; m[11] /= denominator;
    m[12] /= denominator; m[13] /= denominator; m[14] /= denominator; m[15] /= denominator;
}

TZMatrix TZMatrix::operator/( const float denominator ) const
{
	TZMatrix ret;
	
	ret.m[0] = m[0] / denominator; ret.m[1] = m[1] / denominator; ret.m[2] = m[2] / denominator; ret.m[3] = m[3] / denominator;
	ret.m[4] = m[4] / denominator; ret.m[5] = m[5] / denominator; ret.m[6] = m[6] / denominator; ret.m[7] = m[7] / denominator;
	ret.m[8] = m[8] / denominator; ret.m[9] = m[9] / denominator; ret.m[10] = m[10] / denominator; ret.m[11] = m[11] / denominator;
	ret.m[12] = m[12] / denominator; ret.m[13] = m[13] / denominator; ret.m[14] = m[14] / denominator; ret.m[15] = m[15] / denominator;
	
	return ret;
}

float& TZMatrix::operator[]( const int index ) {
	return m[index];
}


void TZMatrix::print( std::string tag ) const
{
	printf("%s =\n", tag.c_str() );
	printf("| %f %f %f %f |\n", m[0], m[1], m[2], m[3]);
	printf("| %f %f %f %f |\n", m[4], m[5], m[6], m[7]);
	printf("| %f %f %f %f |\n", m[8], m[9], m[10], m[11]);
	printf("| %f %f %f %f |\n", m[12], m[13], m[14], m[15]);
}


TZMatrix TZMatrix::transposed() const
{
	TZMatrix ret;
	
	ret.m[0] = m[0];
    ret.m[1] = m[4];
    ret.m[2] = m[8];
    ret.m[3] = m[12];
	
    ret.m[4] = m[1];
	ret.m[5] = m[5];
    ret.m[6] = m[9];
    ret.m[7] = m[13];
	
    ret.m[8] = m[2];
    ret.m[9] = m[6];
	ret.m[10] = m[10];
    ret.m[11] = m[14];
	
    ret.m[12] = m[3];
    ret.m[13] = m[7];
    ret.m[14] = m[11];
	ret.m[15] = m[15];
	
    return ret;
}

void TZMatrix::scale( const float scale_xyz )
{
    m[0] *= scale_xyz;
    m[5] *= scale_xyz;
    m[10] *= scale_xyz;
}
void TZMatrix::scale( const float scale_x, const float scale_y, const float scale_z )
{
    m[0] *= scale_x;
    m[5] *= scale_y;
    m[10] *= scale_z;
}
TZMatrix TZMatrix::Scale( const float scale_xyz )
{
    TZMatrix ret = TZMatrix();
    ret.m[0] = scale_xyz;
    ret.m[5] = scale_xyz;
    ret.m[10] = scale_xyz;
    return ret;
}
TZMatrix TZMatrix::Scale( const float scale_x, const float scale_y, const float scale_z )
{
    TZMatrix ret = TZMatrix();
    ret.m[0] = scale_x;
    ret.m[5] = scale_y;
    ret.m[10] = scale_z;
    return ret;
}

//=================================================================================================================
void TZMatrix::translate( TZVector3D &positionVec )
{
    m[3] += positionVec.x;
    m[7] += positionVec.y;
    m[11] += positionVec.z;
}
TZMatrix TZMatrix::Translate( TZVector3D positionVec ) {
    TZMatrix ret = TZMatrix();
	ret.m[3] = positionVec.x;
	ret.m[7] = positionVec.y;
	ret.m[11] = positionVec.z;
    return ret;
}

void TZMatrix::operator*=( const TZMatrix &matrix )
{
	const TZMatrix temp = *this;
	
    m[0] = temp.m[0] * matrix.m[0] + temp.m[1] * matrix.m[4] + temp.m[2] * matrix.m[8] + temp.m[3] * matrix.m[12];
    m[1] = temp.m[0] * matrix.m[1] + temp.m[1] * matrix.m[5] + temp.m[2] * matrix.m[9] + temp.m[3] * matrix.m[13];
    m[2] = temp.m[0] * matrix.m[2] + temp.m[1] * matrix.m[6] + temp.m[2] * matrix.m[10] + temp.m[3] * matrix.m[14];
    m[3] = temp.m[0] * matrix.m[3] + temp.m[1] * matrix.m[7] + temp.m[2] * matrix.m[11] + temp.m[3] * matrix.m[15];
	
    m[4] = temp.m[4] * matrix.m[0] + temp.m[5] * matrix.m[4] + temp.m[6] * matrix.m[8] + temp.m[7] * matrix.m[12];
    m[5] = temp.m[4] * matrix.m[1] + temp.m[5] * matrix.m[5] + temp.m[6] * matrix.m[9] + temp.m[7] * matrix.m[13];
    m[6] = temp.m[4] * matrix.m[2] + temp.m[5] * matrix.m[6] + temp.m[6] * matrix.m[10] + temp.m[7] * matrix.m[14];
    m[7] = temp.m[4] * matrix.m[3] + temp.m[5] * matrix.m[7] + temp.m[6] * matrix.m[11] + temp.m[7] * matrix.m[15];
	
    m[8] = temp.m[8] * matrix.m[0] + temp.m[9] * matrix.m[4] + temp.m[10] * matrix.m[8] + temp.m[11] * matrix.m[12];
    m[9] = temp.m[8] * matrix.m[1] + temp.m[9] * matrix.m[5] + temp.m[10] * matrix.m[9] + temp.m[11] * matrix.m[13];
    m[10] = temp.m[8] * matrix.m[2] + temp.m[9] * matrix.m[6] + temp.m[10] * matrix.m[10] + temp.m[11] * matrix.m[14];
    m[11] = temp.m[8] * matrix.m[3] + temp.m[9] * matrix.m[7] + temp.m[10] * matrix.m[11] + temp.m[11] * matrix.m[15];
	
    m[12] = temp.m[12] * matrix.m[0] + temp.m[13] * matrix.m[4] + temp.m[14] * matrix.m[8] + temp.m[15] * matrix.m[12];
    m[13] = temp.m[12] * matrix.m[1] + temp.m[13] * matrix.m[5] + temp.m[14] * matrix.m[9] + temp.m[15] * matrix.m[13];
    m[14] = temp.m[12] * matrix.m[2] + temp.m[13] * matrix.m[6] + temp.m[14] * matrix.m[10] + temp.m[15] * matrix.m[14];
    m[15] = temp.m[12] * matrix.m[3] + temp.m[13] * matrix.m[7] + temp.m[14] * matrix.m[11] + temp.m[15] * matrix.m[15];
}

TZMatrix TZMatrix::operator*( const TZMatrix &matrix ) const
{
	TZMatrix ret;
	
	ret.m[0] = m[0] * matrix.m[0] + m[1] * matrix.m[4] + m[2] * matrix.m[8] + m[3] * matrix.m[12];
	ret.m[1] = m[0] * matrix.m[1] + m[1] * matrix.m[5] + m[2] * matrix.m[9] + m[3] * matrix.m[13];
	ret.m[2] = m[0] * matrix.m[2] + m[1] * matrix.m[6] + m[2] * matrix.m[10] + m[3] * matrix.m[14];
	ret.m[3] = m[0] * matrix.m[3] + m[1] * matrix.m[7] + m[2] * matrix.m[11] + m[3] * matrix.m[15];
	
	ret.m[4] = m[4] * matrix.m[0] + m[5] * matrix.m[4] + m[6] * matrix.m[8] + m[7] * matrix.m[12];
	ret.m[5] = m[4] * matrix.m[1] + m[5] * matrix.m[5] + m[6] * matrix.m[9] + m[7] * matrix.m[13];
	ret.m[6] = m[4] * matrix.m[2] + m[5] * matrix.m[6] + m[6] * matrix.m[10] + m[7] * matrix.m[14];
	ret.m[7] = m[4] * matrix.m[3] + m[5] * matrix.m[7] + m[6] * matrix.m[11] + m[7] * matrix.m[15];
	
	ret.m[8] = m[8] * matrix.m[0] + m[9] * matrix.m[4] + m[10] * matrix.m[8] + m[11] * matrix.m[12];
	ret.m[9] = m[8] * matrix.m[1] + m[9] * matrix.m[5] + m[10] * matrix.m[9] + m[11] * matrix.m[13];
	ret.m[10] = m[8] * matrix.m[2] + m[9] * matrix.m[6] + m[10] * matrix.m[10] + m[11] * matrix.m[14];
	ret.m[11] = m[8] * matrix.m[3] + m[9] * matrix.m[7] + m[10] * matrix.m[11] + m[11] * matrix.m[15];
	
	ret.m[12] = m[12] * matrix.m[0] + m[13] * matrix.m[4] + m[14] * matrix.m[8] + m[15] * matrix.m[12];
	ret.m[13] = m[12] * matrix.m[1] + m[13] * matrix.m[5] + m[14] * matrix.m[9] + m[15] * matrix.m[13];
	ret.m[14] = m[12] * matrix.m[2] + m[13] * matrix.m[6] + m[14] * matrix.m[10] + m[15] * matrix.m[14];
	ret.m[15] = m[12] * matrix.m[3] + m[13] * matrix.m[7] + m[14] * matrix.m[11] + m[15] * matrix.m[15];
	
	return ret;
}

TZVector3D  TZMatrix::operator*( const TZVector3D &vector3D ) const
{
	TZVector3D retVector3D;
	/* const int w = 1.0f; */
	
	retVector3D.x = m[0] * vector3D.x + m[1] * vector3D.y + m[2] * vector3D.z + m[3]/* * w */;
	retVector3D.y = m[4] * vector3D.x + m[5] * vector3D.y + m[6] * vector3D.z + m[7]/* * w */;
	retVector3D.z = m[8] * vector3D.x + m[9] * vector3D.y + m[10] * vector3D.z + m[11]/* * w */;
	
	return retVector3D;
}





#define ABS(x) ((x) >= 0 ? (x) : -(x))
#define FLOAT_EQUAL(a,b) (ABS(a-b) < __FLT_EPSILON__)
std::pair<bool,TZMatrix> TZMatrix::inverse() const
{
	float det = TZMatrix::det();

	if( FLOAT_EQUAL(det,0.0f) )
	{
		return std::pair<bool,TZMatrix>( false, TZMatrix(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0) );
	}
	
	TZMatrix ret;
	
	ret.m[0]  = m[5] * m[10] * m[15]  + m[6] * m[11] * m[13]  + m[7] * m[9] * m[14]  - m[5] * m[11] * m[14]  - m[6] * m[9] * m[15]  - m[7] * m[10] * m[13];
	ret.m[1]  = m[1] * m[11] * m[14]  + m[2] * m[9] * m[15]  + m[3] * m[10] * m[13]  - m[1] * m[10] * m[15]  - m[2] * m[11] * m[13]  - m[3] * m[9] * m[14];
	ret.m[2]  = m[1] * m[6] * m[15]  + m[2] * m[7] * m[13]  + m[3] * m[5] * m[14]  - m[1] * m[7] * m[14]  - m[2] * m[5] * m[15]  - m[3] * m[6] * m[13];
	ret.m[3]  = m[1] * m[7] * m[10]  + m[2] * m[5] * m[11]  + m[3] * m[6] * m[9]  - m[1] * m[6] * m[11]  - m[2] * m[7] * m[9]  - m[3] * m[5] * m[10];
	ret.m[4]  = m[4] * m[11] * m[14]  + m[6] * m[8] * m[15]  + m[7] * m[10] * m[12]  - m[4] * m[10] * m[15]  - m[6] * m[11] * m[12]  - m[7] * m[8] * m[14];
	ret.m[5]  = m[0] * m[10] * m[15]  + m[2] * m[11] * m[12]  + m[3] * m[8] * m[14]  - m[0] * m[11] * m[14]  - m[2] * m[8] * m[15]  - m[3] * m[10] * m[12];
	ret.m[6]  = m[0] * m[7] * m[14]  + m[2] * m[4] * m[15]  + m[3] * m[6] * m[12]  - m[0] * m[6] * m[15]  - m[2] * m[7] * m[12]  - m[3] * m[4] * m[14];
	ret.m[7]  = m[0] * m[6] * m[11]  + m[2] * m[7] * m[8]  + m[3] * m[4] * m[10]  - m[0] * m[7] * m[10]  - m[2] * m[4] * m[11]  - m[3] * m[6] * m[8];
	ret.m[8]  = m[4] * m[9] * m[15]  + m[5] * m[11] * m[12]  + m[7] * m[8] * m[13]  - m[4] * m[11] * m[13]  - m[5] * m[8] * m[15]  - m[7] * m[9] * m[12];
	ret.m[9]  = m[0] * m[11] * m[13]  + m[1] * m[8] * m[15]  + m[3] * m[9] * m[12]  - m[0] * m[9] * m[15]  - m[1] * m[11] * m[12]  - m[3] * m[8] * m[13];
	ret.m[10] = m[0] * m[5] * m[15]  + m[1] * m[7] * m[12]  + m[3] * m[4] * m[13]  - m[0] * m[7] * m[13]  - m[1] * m[4] * m[15]  - m[3] * m[5] * m[12];
	ret.m[11] = m[0] * m[7] * m[9]  + m[1] * m[4] * m[11]  + m[3] * m[5] * m[8]  - m[0] * m[5] * m[11]  - m[1] * m[7] * m[8]  - m[3] * m[4] * m[9];
	ret.m[12] = m[4] * m[10] * m[13]  + m[5] * m[8] * m[14]  + m[6] * m[9] * m[12]  - m[4] * m[9] * m[14]  - m[5] * m[10] * m[12]  - m[6] * m[8] * m[13];
	ret.m[13] = m[0] * m[9] * m[14]  + m[1] * m[10] * m[12]  + m[2] * m[8] * m[13]  - m[0] * m[10] * m[13]  - m[1] * m[8] * m[14]  - m[2] * m[9] * m[12];
	ret.m[14] = m[0] * m[6] * m[13]  + m[1] * m[4] * m[14]  + m[2] * m[5] * m[12]  - m[0] * m[5] * m[14]  - m[1] * m[6] * m[12]  - m[2] * m[4] * m[13];
	ret.m[15] = m[0] * m[5] * m[10]  + m[1] * m[6] * m[8]  + m[2] * m[4] * m[9]  - m[0] * m[6] * m[9]  - m[1] * m[4] * m[10]  - m[2] * m[5] * m[8];
	ret = ret * (1.0/det);
	
	return std::pair<bool,TZMatrix>( true, ret );
}

float TZMatrix::det() const
{
	float ret;
	
	ret =  m[0] * m[5] * m[10] * m[15]  + m[0] * m[6] * m[11] * m[13]  + m[0] * m[7] * m[9] * m[14]
    + m[1] * m[4] * m[11] * m[14]  + m[1] * m[6] * m[8] * m[15]  + m[1] * m[7] * m[10] * m[12]
    + m[2] * m[4] * m[9] * m[15]  + m[2] * m[5] * m[11] * m[12]  + m[2] * m[7] * m[8] * m[13]
    + m[3] * m[4] * m[10] * m[13]  + m[3] * m[5] * m[8] * m[14]  + m[3] * m[6] * m[9] * m[12]
    - m[0] * m[5] * m[11] * m[14]  - m[0] * m[6] * m[9] * m[15]  - m[0] * m[7] * m[10] * m[13]
    - m[1] * m[4] * m[10] * m[15]  - m[1] * m[6] * m[11] * m[12]  - m[1] * m[7] * m[8] * m[14]
    - m[2] * m[4] * m[11] * m[13]  - m[2] * m[5] * m[8] * m[15]  - m[2] * m[7] * m[9] * m[12]
    - m[3] * m[4] * m[9] * m[14]  - m[3] * m[5] * m[10] * m[12]  - m[3] * m[6] * m[8] * m[13]
    ;
	
	return ret;
}


void TZMatrix::axisRotate( const float angle_degree, TZVector3D &axis )
{
	/*
     TZQuaternion q(0,0,0,1);
     q.axisRotate( angle_degree, axis );
	 */
	float half_radian = degree2radian(angle_degree * 0.5);
	TZQuaternion q( cos(half_radian), axis.unit() * sin(half_radian) );
    
	*this *= q.toMatrix();
}
TZMatrix TZMatrix::AxisRotate( const float angle_degree, TZVector3D axis ) {
    TZMatrix ret = TZMatrix();
	float half_radian = degree2radian(angle_degree * 0.5);
	TZQuaternion q( cos(half_radian), axis.unit() * sin(half_radian) );
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
