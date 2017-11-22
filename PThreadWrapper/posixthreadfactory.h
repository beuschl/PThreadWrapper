//
// Realization of the interface IThreadFactory for the POSIX Threads
//

#ifndef _POSIX_THREAD_FACTORY_H__
#define _POSIX_THREAD_FACTORY_H__


#include "ithreadfactory.h"

namespace PThreadWarapper {

   class CPosixThreadFactory : public IThreadFactory 
   {

      public:

         CPosixThreadFactory();
         virtual ~CPosixThreadFactory();

         IThread* createSystemThreads();
         IThreadAttribute* createThreadAttribute();
   };

}

#endif

