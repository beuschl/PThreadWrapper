//
// Implementation of the class PSystemThread
//
// Hiding the operating system if and defs behind this Facade
//


#if defined(_WIN32)
#include "winthreadfactory.h"
#include "winthread.h"
#endif

#if defined(__linux__)
#include "posixthreadfactory.h"
#include "posixthread.h"
#endif


#include "psystemthread.h"

PThreadWarapper::PSystemThread::PSystemThread()
   : m_pThread(0)
   , m_pThreadAttribute(0)
{
#if defined( __linux__)
   m_pThreadFactory = new CPosixThreadFactory();
#endif

#if defined(_WIN32)
   m_pThreadFactory = new CWinThreadFactory();
#endif   

}

PThreadWarapper::PSystemThread::~PSystemThread()
{
   if( m_pThread != 0 )
   {
      delete m_pThread;
      m_pThread = 0;
   }

   if( m_pThreadAttribute != 0 )
   {
      delete m_pThreadAttribute;
      m_pThreadAttribute = 0;
   }

   delete m_pThreadFactory;
}

void
PThreadWarapper::PSystemThread::instanceThread()
{
   m_pThread = m_pThreadFactory->createSystemThreads();
}

void
PThreadWarapper::PSystemThread::createAttribute()
{
   m_pThreadAttribute = m_pThreadFactory->createThreadAttribute();
}

PThreadWarapper::IThread*
PThreadWarapper::PSystemThread::createThread()
{
   m_pThread->createThread();
   return m_pThread;
}

void
PThreadWarapper::PSystemThread::setThreadAttr()
{
   m_pThread->setThreadAttribute( m_pThreadAttribute );
}

void
PThreadWarapper::PSystemThread::setThreadScope( int attributeType )
{
   m_pThreadAttribute->setScope( attributeType );
}

void
PThreadWarapper::PSystemThread::setThreadObject( IThreadObject* pTreadObject )
{
   m_pThread->setThreadObject( pTreadObject );
}

void
PThreadWarapper::PSystemThread::detachThread()
{
   m_pThread->detachThread();
}

void
PThreadWarapper::PSystemThread::cancelThread()
{
   m_pThread->cancelThread();
}

void
PThreadWarapper::PSystemThread::exitThread()
{
   m_pThread->exitThread();
}


