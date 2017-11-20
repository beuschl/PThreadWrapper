//

#ifndef _THREAD_ATTRIBUTE_H__
#define _THREAD_ATTRIBUTE_H__

#include "pthread.h"
#include "ithreadattribute.h"

namespace PThreadWarapper {

   class  CThreadAttribute : public IThreadAttribute 
   {
      public:

         CThreadAttribute();
         virtual ~CThreadAttribute();

         void setScope( int attributeType );
         pthread_attr_t getAttribType() const;                 

      private:

         pthread_attr_t m_AttributeType;
   };
}
#endif
