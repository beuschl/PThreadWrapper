//
// Implementation of the class CPosixThread
//

#include "posixthread.h"
#include "threadobject.h"


namespace cpxposixthread {

   void* threadOperation( void* pX )
   {
      void* pReturnValue = 0;
      PThreadWarapper::CPosixThread posixThread = PThreadWarapper::CPosixThread();
      pReturnValue = posixThread.threadOperation( pX );
      return pReturnValue;
   }
}

// Bridge Method/operation (for handling C/C++ function pointer)
void*
PThreadWarapper::CPosixThread::threadOperation( void* pX )
{
   void* pReturnValue = 0;
   CThreadObject* pThread = static_cast<CThreadObject*>( pX );
   pThread->threadOperation();
   return pReturnValue;
}

PThreadWarapper::CPosixThread::CPosixThread()
{
   m_pThreadAttribute = 0;
}

PThreadWarapper::CPosixThread::~CPosixThread()
{
}

void
PThreadWarapper::CPosixThread::setThreadObject( IThreadObject* pThreadObject )
{
   m_pThreadObject = pThreadObject;
}

void 
PThreadWarapper::CPosixThread::setThreadAttribute( IThreadAttribute* pAttribute )
{
   m_pThreadAttribute = static_cast<CThreadAttribute*>( pAttribute );
}

void
PThreadWarapper::CPosixThread::createThread()
{
   if( m_pThreadAttribute == 0 )
   {
      pthread_create( &m_pThread, 0, cpxposixthread::threadOperation, m_pThreadObject );
   }
   else {
      pthread_attr_t aAttribType;
      pthread_attr_init( &aAttribType );
      aAttribType = m_pThreadAttribute->getAttribType();
      pthread_create( &m_pThread, &aAttribType, cpxposixthread::threadOperation, m_pThreadObject );
   }
}

void
PThreadWarapper::CPosixThread::joinThread()
{
   pthread_join( m_pThread, 0 );
}

void
PThreadWarapper::CPosixThread::detachThread()
{
   pthread_detach( m_pThread );
}

void
PThreadWarapper::CPosixThread::cancelThread()
{
   pthread_cancel( m_pThread );
}

void
PThreadWarapper::CPosixThread::exitThread()
{
   int value;
   pthread_exit( &value );
}



