//
// Interface to creating, running, deleting, killing thread
//

#ifndef  _ITHREAD_H__
#define  _ITHREAD_H__


namespace PThreadWarapper {

   class IThreadObject;
   class IThreadAttribute;

   class IThread 
   {
      public:

         virtual void setThreadObject( IThreadObject* pThreadObject ) = 0;
         virtual void setThreadAttribute( IThreadAttribute* pAttribute ) = 0;
         virtual void createThread() = 0;
         virtual void joinThread() = 0;
         virtual void detachThread() = 0;
         virtual void cancelThread() = 0;
         virtual void exitThread() = 0;
         virtual ~IThread() {}
   };
}

#endif
