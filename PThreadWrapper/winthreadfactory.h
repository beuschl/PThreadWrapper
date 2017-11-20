//
// Class CWinThreadFactory for handling the Windows Thread Factories
//


#ifndef _WIN_THREAD_FACTORY_H__
#define _WIN_THREAD_FACTORY_H__

#include "ithreadfactory.h"

namespace PThreadWarapper {

   class CWinThreadFactory : public IThreadFactory 
   {
      public:

         CWinThreadFactory();
         virtual ~CWinThreadFactory();

         IThread* createSystemThreads();
         IThreadAttribute* createThreadAttribute();
         
   };
}

#endif



