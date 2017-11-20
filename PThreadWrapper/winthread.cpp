//
// Implementation of the class CWinThread
//

#include "winthread.h"
#include "threadobject.h"


namespace cpxwinthread 
{
   void* threadOperation( void* aX )
   {
      void* returnValue = 0;
      PThreadWarapper::CWinThread winThread = PThreadWarapper::CWinThread();
      returnValue = winThread.threadOperation( aX );
      return returnValue;
   }
}

void*
PThreadWarapper::CWinThread::threadOperation( void* aX )
{
   void* returnValue = 0;
   CThreadObject* pThread = static_cast<CThreadObject*>( aX );
   pThread->threadOperation();
   return returnValue;
}

PThreadWarapper::CWinThread::CWinThread()
{
   m_pThreadAttribute = 0;
}

PThreadWarapper::CWinThread::~CWinThread()
{
}

void
PThreadWarapper::CWinThread::setThreadAttribute( IThreadAttribute* pAttribute )
{
   m_pThreadAttribute = static_cast<CThreadAttribute*>( pAttribute );
}

void
PThreadWarapper::CWinThread::setThreadObject( IThreadObject* pThreadObject )
{
   m_pThreadObject = pThreadObject;
}

void
PThreadWarapper::CWinThread::createThread()
{
   if( m_pThreadAttribute == 0 )
   {
      pthread_create( &m_pThread, 0, cpxwinthread::threadOperation, m_pThreadObject );
   }
   else {
      pthread_attr_t aAttribType;
      pthread_attr_init( &aAttribType );
      aAttribType = m_pThreadAttribute->getAttribType();
      pthread_create( &m_pThread, &aAttribType,
                      cpxwinthread::threadOperation,
                      m_pThreadObject );

   }
}

void
PThreadWarapper::CWinThread::joinThread()
{
   pthread_join( m_pThread, 0 );
}

void
PThreadWarapper::CWinThread::detachThread()
{
   pthread_detach( m_pThread );
}

void
PThreadWarapper::CWinThread::cancelThread()
{
   pthread_cancel( m_pThread );
}

void
PThreadWarapper::CWinThread::exitThread()
{
   int returnValue;
   pthread_exit( &returnValue );
}


