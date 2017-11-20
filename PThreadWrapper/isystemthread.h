//
//

#ifndef _ISYSTEM_THREAD_H__
#define _ISYSTEM_THREAD_H__

namespace PThreadWarapper {

   class IThreadObject;
   class IThread;

   class ISystemThread
   {
      public:

         virtual void instanceThread() = 0;
         virtual void createAttribute() = 0;
         virtual IThread* createThread() = 0;
         virtual void detachThread() = 0;
         virtual void cancelThread() = 0;
         virtual void exitThread() = 0;
         virtual void setThreadAttr() = 0;
         virtual void setThreadScope( int attributeType ) = 0;
         virtual void setThreadObject( IThreadObject* pTreadObject ) = 0;

         virtual ~ISystemThread() {}
   };
}

#endif