//
// Implementation of the class CThreadObject
//

#include "threadobject.h"
#include "ithreadobjectimpl.h"


PThreadWarapper::CThreadObject::CThreadObject()
{
}

PThreadWarapper::CThreadObject::CThreadObject( IThreadObjectImpl* pThreadImpl )
{
   m_pThreadImpl = pThreadImpl;
}

PThreadWarapper::CThreadObject::~CThreadObject()
{
}

// threadOperation will be executed in a thread
//
void
PThreadWarapper::CThreadObject::threadOperation()
{
   m_pThreadImpl->threadOperationImpl();
}





