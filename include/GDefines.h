#ifndef G_DEFINES_H
#define G_DEFINES_H

#ifdef _DEBUG
#  define G_LOGGING
#  include<iostream>
#endif // _DEBUG

#ifdef G_LOGGING
# define GLOG(l) std::cout << l << std::endl;
#endif

#endif // G_DEFINES_H guard
