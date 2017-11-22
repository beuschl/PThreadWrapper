//
// Port for the realization of the interface ISystemThread
//

#ifndef _PSYSTEM_THREAD_H__
#define _PSYSTEM_THREAD_H__

#include "ithreadfactory.h"
#include "isystemthread.h"

namespace PThreadWarapper {

   class PSystemThread : public ISystemThread 
   {

      public:

         PSystemThread();
         virtual ~PSystemThread();

         void instanceThread();
         void createAttribute();
         IThread* createThread();
         void detachThread();
         void cancelThread();
         void exitThread();
         void setThreadAttr();
         void setThreadScope( int attributeType );
         void setThreadObject( IThreadObject* pTreadObject );

      private:

         IThreadFactory*   m_pThreadFactory;
         IThread*          m_pThread;
         IThreadAttribute* m_pThreadAttribute;
         IThreadObject*    m_pThreadObject;
   };
}

#endif
