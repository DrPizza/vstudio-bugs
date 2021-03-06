#pragma once

#include "targetver.h"

#pragma warning(disable: 4514) // warning C4514: '%s': unreferenced inline function has been removed
#pragma warning(disable: 4710) // warning C4710: '%s': function not inlined
#pragma warning(disable: 4668) // warning C4668: '%s' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
#pragma warning(disable: 4820) // warning C4820: '%s': '%d' bytes padding added after data member '%s'

#if !defined(_STL_EXTRA_DISABLED_WARNINGS)
#define _STL_EXTRA_DISABLED_WARNINGS 4061 4365 4514 4571 4623 4625 4626 4710 4774 4820 4987 5026 5027
#endif

#include <atomic>
#include <iostream>
