//
// Implementation of the class CPosixThreadFactory
//

#include "posixthreadfactory.h"
#include "threadattribute.h"
#include "posixthread.h"


PThreadWarapper::CPosixThreadFactory::CPosixThreadFactory()
{
}

PThreadWarapper::CPosixThreadFactory::~CPosixThreadFactory()
{
}

PThreadWarapper::IThread*
PThreadWarapper::CPosixThreadFactory::createSystemThreads()
{
   IThread* pThread = new CPosixThread();
   return pThread;
}

PThreadWarapper::IThreadAttribute*
PThreadWarapper::CPosixThreadFactory::createThreadAttribute()
{
   IThreadAttribute* pThreadAttribute = new CThreadAttribute();
   return pThreadAttribute;
}





