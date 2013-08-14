/*
 *  vector3D.h
 *  Test349248284985
 *
 *  Created by fumiyasu takaura on 10/10/30.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef TZVECTOR_H
#define TZVECTOR_H

#include <string>

namespace TZulu {
    
    class TZVector2D {
    public:
        union {
            float v[2];
            struct {
                float x,y;
            };
        };
        TZVector2D() { x=0.0f; y=0.0f; }
        TZVector2D( const float arg_x, const float arg_y ) { x=arg_x; y=arg_y; }
    };
    class TZVector4D {
    public:
        union {
            float v[4];
            struct {
                float x,y,z,w;
            };
        };
        TZVector4D() { x=0.0f; y=0.0f; z=0.0f; w=1.0f; }
        TZVector4D( const float arg_x, const float arg_y, const float arg_z, const float arg_w ) {
            x=arg_x; y=arg_y; z=arg_z; w=arg_w;
        }
    };
    
    class TZVector3D
    {
    public:
        
        union {
            float v[3];
            struct {
                float x,y,z;
            };
        };
        
        TZVector3D();
        TZVector3D( const float arg_x, const float arg_y , const float arg_z );
        ~TZVector3D();
        
        void printTZVector3D();
        
        void operator=( const TZVector3D &vector3D );
        TZVector3D operator+( const TZVector3D &vector3D ) const;
        void operator+=( const TZVector3D &vector3D );
        TZVector3D operator-( const TZVector3D &vector3D ) const;
        void operator-=( const TZVector3D &vector3D );
        TZVector3D operator*( const float scale ) const;
        TZVector3D operator/( const float denominator ) const;
        bool operator==( const TZVector3D &vector3D ) const;
        float& operator[](int index);
        
        void print( std::string tag );
        
        float vectorLength();
        TZVector3D unitTZVector3D();
        void makeUnit();
        
        float dot( const TZVector3D &vector3D ) const;
        TZVector3D cross( const TZVector3D &vector3D ) const;
        
    };
    
}


#endif
