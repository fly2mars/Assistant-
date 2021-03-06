#pragma once

#if !defined(SU_NOTHREADS) && defined(WIN32)
#include <Engines/System/Win32/lock.h>
#elif  defined(__linux)
#include <Engines/System/unix/lock.h>
#else

/* \file lock.h
*
* \brief  Thread synchronization routines, or null objects for
*  platforms that do not support (or do not need) this
*  functionality.
*/



#endif // other system


//!only choose win32
//#include <Engines/System/Win32/lock.h>

/* class suLocker
*\brief suLocker is a generic version of RAII (resource acquisition is initialization).
<pre>
1) Create a global lock that you will use for your resource
ex:  suLock coutLock;
2) Use an instance of suLocker to manage this resource
ex:
{
suLocker lock(coutLock);
std::cout << "Locked access to std::cout" << std::endl;
}
</pre>
*/
class suLocker
{
public:
	suLocker(suLock& lock) : lock_(lock) { lock_.lock(); }
	~suLocker() { lock_.unlock(); }

private:
	suLock& lock_;

	// Prohibit copy and assignment
	suLocker(const suLocker& src);
	suLocker& operator= (const suLocker& src);
};

