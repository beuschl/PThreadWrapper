//
// Implementation of the class CWinThreadFactory
//

#include "winthreadfactory.h"
#include "threadattribute.h"
#include "winthread.h"


PThreadWarapper::CWinThreadFactory::CWinThreadFactory()
{
}

PThreadWarapper::CWinThreadFactory::~CWinThreadFactory()
{
}

PThreadWarapper::IThread*
PThreadWarapper::CWinThreadFactory::createSystemThreads()
{
   IThread* pThread = new CWinThread();
   return pThread;
}

PThreadWarapper::IThreadAttribute*
PThreadWarapper::CWinThreadFactory::createThreadAttribute()
{
   IThreadAttribute* pThreadAttribute = new CThreadAttribute();
   return pThreadAttribute;
}





