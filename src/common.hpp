/******************************************
Copyright (C) 2023 Authors of GANAK, see AUTHORS file

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
***********************************************/

#pragma once

#include <string>
#include <iomanip>
#include <sstream>
#include <cstdint>
#include <random>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

/* #define VERBOSE_DEBUG */
/* #define SLOW_DEBUG */
/* #define CHECK_PROPAGATED */
/* #define CHECK_IMPLIED */
/* #define VERY_SLOW_DEBUG */
/* #define BUDDY_ENABLED */
// the slowest of all that's not verifying counts
/* #define CHECK_TRAIL_ENTAILMENT */

// I suggest disabling the cache separately with --cache 0
/* #define CHECK_COUNT */


#define COLRED "\033[31m"
#define COLYEL2 "\033[35m"
#define COLYEL "\033[33m"
#define COLCYN "\033[36m"
#define COLWHT "\033[97m"
#define COLORG "\033[43m"
#define COLBLBACK  "\033[44m"
#define COLORGBG "\033[100m"
#define COLREDBG "\033[41m"

//default
#define COLDEF "\033[0m"

#ifdef SLOW_DEBUG
#define SLOW_DEBUG_DO(x) do { x; } while (0)
#else
#define SLOW_DEBUG_DO(x) do { } while (0)
#endif

#ifdef CHECK_IMPLIED
#define CHECK_IMPLIED_DO(x) do { x; } while (0)
#else
#define CHECK_IMPLIED_DO(x) do { } while (0)
#endif

#ifdef CHECK_PROPAGATED
#define CHECK_PROPAGATED_DO(x) do { x; } while (0)
#else
#define CHECK_PROPAGATED_DO(x) do { } while (0)
#endif

#ifdef VERY_SLOW_DEBUG
#define VERY_SLOW_DEBUG_DO(x) do { x; } while (0)
#else
#define VERY_SLOW_DEBUG_DO(x) do { } while (0)
#endif

#ifdef CHECK_COUNT
#define CHECK_COUNT_DO(x) do { x; } while (0)
#else
#define CHECK_COUNT_DO(x) do { } while (0)
#endif

#define verb_print(a, b) if (conf.verb >= a) cout << "c o " << b << endl
#define clear_toclear_seen() \
    do {\
      for(const auto& x: to_clear) seen[x] = 0;\
      to_clear.clear();} while (0)


#ifdef BUDDY_ENABLED
#define BUDDY_DO(x) do { x; } while (0)
#else
#define BUDDY_DO(x) do { } while (0)
#endif



#ifdef VERBOSE_DEBUG
#define VERBOSE_DEBUG_DO(x) do { x; } while (0)
#else
#define VERBOSE_DEBUG_DO(x) do { } while (0)
#endif

#ifdef VERBOSE_DEBUG
#define debug_print(x) std::cout << COLDEF << x << COLDEF << endl
#define debug_print_noendl(x) std::cout << x
#else
#define debug_print(x) do {} while(0)
#define debug_print_noendl(x) do {} while (0)
#endif
#define debug_print_tmp(x) std::cout << COLDEF << x << COLDEF << endl

#define all_vars_in_comp(comp, v) for(auto v = (comp).vars_begin(); *v != sentinel; v++)
#define all_cls_in_comp(comp, c) for(auto c = (comp).cls_begin(); *c != sentinel; c++)

#define release_assert(a) \
    do { \
        if (!(a)) {\
            fprintf(stderr, "*** ASSERTION FAILURE in %s() [%s:%d]: %s\n", \
            __FUNCTION__, __FILE__, __LINE__, #a); \
            abort(); \
        } \
    } while (0)

inline double float_div(const double a, const double b) {
    if (b != 0)
        return a/b;

    return 0;
}

#define all_lits(x) for(uint32_t x = 2; x < (nVars()+1)*2; x++)

inline std::string print_value_kilo_mega(const int64_t value, bool setw = true) {
  std::stringstream ss;
  if (value > 20*1000LL*1000LL) {
    if (setw) {
        ss << std::setw(4);
    }
    ss << value/(1000LL*1000LL) << "M";
  } else if (value > 20LL*1000LL) {
    if (setw) {
        ss << std::setw(4);
    }
    ss << value/1000LL << "K";
  } else {
    if (setw) {
        ss << std::setw(5);
    }
    ss << value;
  }
  return ss.str();
}
#define unif_uint_dist(x,y) std::uniform_int_distribution<> x(0, y)
inline uint32_t rnd_uint(std::mt19937_64& mtrand, const uint32_t maximum) {
    unif_uint_dist(u, maximum);
    return u(mtrand);
}

#define release_assert(a) \
    do { \
        if (!(a)) {\
            fprintf(stderr, "*** ASSERTION FAILURE in %s() [%s:%d]: %s\n", \
            __FUNCTION__, __FILE__, __LINE__, #a); \
            abort(); \
        } \
    } while (0)
