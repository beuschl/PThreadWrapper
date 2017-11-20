//
// Implementation of the class CThreadAttribute
//

#include "threadattribute.h"

PThreadWarapper::CThreadAttribute::CThreadAttribute()
{
   pthread_attr_init( &m_AttributeType );
}

PThreadWarapper::CThreadAttribute::~CThreadAttribute()
{
}

pthread_attr_t
PThreadWarapper::CThreadAttribute::getAttribType() const
{
   return m_AttributeType;
}

void
PThreadWarapper::CThreadAttribute::setScope( int attributeType )
{
   pthread_attr_setscope( &m_AttributeType, attributeType );
}





