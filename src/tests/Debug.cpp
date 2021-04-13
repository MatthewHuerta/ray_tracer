#include<time.h>
#if DEBUG == 1
#define LOG(x) std::cout<< x
#else
#define LOG(x)
#endif

//testing ssh keys

clock_t begin;
clock_t end;

#define TIME(X) begin = clock(); X; end = clock(); std::cout << std::endl << "time taken: " << end - begin;
