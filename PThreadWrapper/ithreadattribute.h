
#ifndef _ITHREAD_ATTRIBUTE_H__
#define _ITHREAD_ATTRIBUTE_H__

namespace PThreadWarapper {

   class IThreadAttribute
   {

      public:

         virtual void setScope( int attributeType ) = 0;
         virtual ~IThreadAttribute() {}
   };
}

#endif

