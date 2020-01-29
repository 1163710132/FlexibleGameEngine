//
// Created by chenjs on 1/16/20.
//

#ifndef FLEXIBLEGAMEENGINE_PIXEL_H
#define FLEXIBLEGAMEENGINE_PIXEL_H

#include "Common.h"

struct Rgb24{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct Rgba32{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

using Color3 = Rgb24;
using Color4 = Rgba32;

#endif //FLEXIBLEGAMEENGINE_PIXEL_H
