
#ifndef _ITHREAD_OBJECT_H__
#define _ITHREAD_OBJECT_H__

namespace PThreadWarapper {

   class IThreadObject
   {
      public:

      virtual void threadOperation() = 0;
      virtual ~IThreadObject() {};
   };
}
#endif
