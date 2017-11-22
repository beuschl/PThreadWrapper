//
// Realization of the interface IThread by POSIX Threads
//
// Thread Class for multithreaded objects, according to the wished number
// of threads per object, by CCpxNThreadObj, where N = 1, 2, 3, ..., N = 40
// it creates the number of threads for the objects, max 40 threads per object
//


#ifndef _POSIX_THREAD_H__
#define _POSIX_THREAD_H__

#include "ithread.h"
#include "threadattribute.h"


namespace cpxposixthread {

   extern "C" void* threadOperation( void* pX );

}

namespace PThreadWarapper {

   class CPosixThread : public IThread 
   {

      public:

         CPosixThread();
         virtual ~CPosixThread();

         void setThreadObject( IThreadObject* pThreadObject );
         void setThreadAttribute( IThreadAttribute* pAttribute );
         void createThread();
         void joinThread();
         void detachThread();
         void cancelThread();
         void exitThread();
         void* threadOperation( void* pX );

      private:

         IThreadObject*    m_pThreadObject;
         CThreadAttribute*	m_pThreadAttribute;
         pthread_t         m_pThread;

   };
}


#endif
