#ifdef LOGGER
#include <iostream>
#define LOG(msg) \
    std::cerr << __FILE__ << "(" << __LINE__ << "): " << msg << std::endl 
#define LOGT(msg) \
    m.lock(); std::cerr << __FILE__ << "(" << __LINE__ << "): " << msg << std::endl; m.unlock()
#else
#define LOG(msg)
#define LOGT(msg)
#endif

