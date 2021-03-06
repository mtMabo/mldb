/* xdiv.h                                                          -*- C++ -*-
   Jeremy Barnes, 30 January 2005
   Copyright (c) 2005 Jeremy Barnes.  All rights reserved.
   This file is part of MLDB. Copyright 2015 mldb.ai inc. All rights reserved.

   ---

   Our old friend the xdiv function.
*/

#pragma once

#include "mldb/utils/float_traits.h"
#include "mldb/compiler/compiler.h"

namespace MLDB {

template<typename F1, typename F2>
typename float_traits<F1, F2>::fraction_type
xdiv(F1 x, F2 y)
{
    return (y == 0 ? 0 : x / y);
}

/* Divide, but round up */
template<class X, class Y>
MLDB_COMPUTE_METHOD
X rudiv(X val, Y by)
{
    X result = (val / by);
    X missing = val - (result * by);
    result += (missing > 0);
    return result;
}


} // namespace MLDB
