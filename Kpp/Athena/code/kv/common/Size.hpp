#pragma once

#include "_namespace/begin"

template <class _ValueType>
union TSize2 final
{
    using ValueType = _ValueType;
    ValueType values[2];
    struct { ValueType width, height; };
    constexpr TSize2(ValueType const width, ValueType const height) noexcept
        : values { width, height }
    {}
};
using Size2i = TSize2<int>;
using Size2f = TSize2<float>;


template <class _ValueType>
union TSize3 final
{
    using ValueType = _ValueType;
    ValueType values[3];
    struct { ValueType width, height, depth; };
    constexpr TSize3(ValueType const width, ValueType const height, ValueType const depth) noexcept
        : values { width, height, depth }
    {}
};
using Size3i = TSize3<int>;
using Size3f = TSize3<float>;

#include "_namespace/end"