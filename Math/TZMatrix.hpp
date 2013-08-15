/*
 *  matrix.h
 *  Ninteru3DMacOSX
 *
 *  Created by Fumiyasu Takaura on 1/16/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TZMatrix_H
#define TZMatrix_H


#include "TZVector.hpp"


namespace TZulu {
    
    class TZMatrix
    {
    public:
        
        union {
            float m[16];
            struct {
                float m11,m12,m13,m14,
                m21,m22,m23,m24,
                m31,m32,m33,m34,
                m41,m42,m43,m44;
            };
        };
        
        TZMatrix();
        TZMatrix(const float a[16]);
        TZMatrix(const float a11, const float a12, const float a13, const float a14,
                 const float a21, const float a22, const float a23, const float a24,
                 const float a31, const float a32, const float a33, const float a34,
                 const float a41, const float a42, const float a43, const float a44);
        TZMatrix( const TZMatrix &matrix );
        ~TZMatrix();
        
        void operator+=( const TZMatrix &matrix );
        TZMatrix operator+( const TZMatrix &matrix ) const;
        void operator-=( const TZMatrix &matrix );
        TZMatrix operator-( const TZMatrix &matrix ) const;
        void operator*=( const float scala );
        TZMatrix operator*( const float scala ) const;
        void operator*=( const TZMatrix &matrix );
        TZMatrix operator*( const TZMatrix &matrix ) const;
        TZVector3D  operator*( const TZVector3D &vector3D ) const;
        void operator/=( const float denominator );
        TZMatrix operator/( const float denominator ) const;
        float& operator[]( const int intdex );
        
        void print( std::string tag = "" ) const;
        
        void scale( const float scale_xyz );
        void scale( const float scale_x, const float scale_y, const float scale_z );
        void translate( TZVector3D &positionVec );
        void axisRotate( const float angle_degree, TZVector3D &axis );
        
        std::pair<bool,TZMatrix> inverse() const; // inverse matrix
        float det() const; // determinant
        TZMatrix transposed() const; // transposed matrix
        
        static TZMatrix Unit();
        static TZMatrix Scale( const float scale_xyz );
        static TZMatrix Scale( const float scale_x, const float scale_y, const float scale_z );
        static TZMatrix Translate( TZVector3D positionVec );
        static TZMatrix AxisRotate( const float angle_degree, TZVector3D axis );
        static TZMatrix Projection(const int screenW, const int screenH,
                                   const float angleOfView_Degree,
                                   const float near, const float far );
    };
    
}

#endif
