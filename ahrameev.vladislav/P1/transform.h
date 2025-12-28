#ifndef TRANSFORM_H
#define TRANSFORM_H

namespace ahrammev
{
    struct Result
{
        int cntMin = 0;
        int aftMax = 0;
        bool aftMaxValid = true;
    };

    Result compute();
}

#endif
