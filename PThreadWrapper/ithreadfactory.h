//
// Interface IThreadFactory for creating the thread objects
//

#ifndef _ITHREAD_FACTORY_H__
#define _ITHREAD_FACTORY_H__

namespace PThreadWarapper {

   class IThread;
   class IThreadAttribute;

   class IThreadFactory 
   {
      public:

         virtual IThread* createSystemThreads() = 0;
         virtual IThreadAttribute* createThreadAttribute() = 0;

         virtual ~IThreadFactory() {}
   };
}

#endif


