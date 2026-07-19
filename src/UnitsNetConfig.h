#pragma once

namespace unitsnet_cpp
{
#ifdef UNITSNET_CPP_USE_FLOAT
    using un_scalar_t = float;
#else
    using un_scalar_t = double;
#endif
}