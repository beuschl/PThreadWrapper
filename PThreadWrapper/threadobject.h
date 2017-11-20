//

#ifndef _THREAD_OBJECT_H__
#define _THREAD_OBJECT_H__


#include "ithreadobject.h"

namespace PThreadWarapper {

   class IThreadObjectImpl;

   class CThreadObject : public IThreadObject 
   {

      public:

         CThreadObject();
         CThreadObject( IThreadObjectImpl* pThreadImpl );
         virtual ~CThreadObject();

         void threadOperation();
     

      private:

         IThreadObjectImpl* m_pThreadImpl;
   };
}

#endif


