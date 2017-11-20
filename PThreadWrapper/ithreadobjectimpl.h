//
// Abstract class act as a kind of adapter/Port
//
// The object derives from this abstract class, the datamembers are the
// data, where the threadOperationImpl act
//

#ifndef _ITHREAD_OBJECT_IMPL_H__
#define _ITHREAD_OBJECT_IMPL_H__

namespace PThreadWarapper {

   class IThreadObjectImpl
   {

      public:

      virtual void threadOperationImpl() = 0;
      virtual ~IThreadObjectImpl() {};
   };
}
#endif
