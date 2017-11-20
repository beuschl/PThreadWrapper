//
// Realization of the interface IThread
//

#ifndef _WIN_THREAD_H__
#define _WIN_THREAD_H__


//#include "pthread.h"
#include "ithread.h"
#include "threadattribute.h"

namespace cpxwinthread {

   extern "C" void* threadOperation( void* aX );

}

namespace PThreadWarapper {

   class CWinThread : public IThread 
   {
      public:

         CWinThread();
         virtual ~CWinThread();

         void setThreadObject( IThreadObject* pThreadObject );
         void setThreadAttribute( IThreadAttribute* pAttribute );
         void createThread();
         void joinThread();
         void detachThread();
         void cancelThread();
         void exitThread();
         void* threadOperation( void* aX );        

      private:

         IThreadObject*    m_pThreadObject;
         CThreadAttribute*	m_pThreadAttribute;
         pthread_t			m_pThread;

   };
}

#endif

