/*
 * Copyright (c) 2022, Alibaba Group Holding Limited;
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ASYNC_SIMPLE_COMMON_H
#define ASYNC_SIMPLE_COMMON_H

#include <stdexcept>

#if defined(__clang__) && __clang_major__ < 12
#define LIKELY
#define UNLIKELY
#else
#define LIKELY [[likely]]
#define UNLIKELY [[unlikely]]
#endif

#ifdef _WIN32
#define AS_INLINE
#else
#define AS_INLINE __attribute__((__always_inline__)) inline
#endif

namespace async_simple {
// Different from assert, logicAssert is meaningful in
// release mode. logicAssert should be used in case that
// we need to make assumption for users.
// In another word, if assert fails, it means there is
// a bug in the library. If logicAssert fails, it means
// there is a bug in the user code.
inline void logicAssert(bool x, const char* errorMsg) {
    if (x)
        LIKELY { return; }
    throw std::logic_error(errorMsg);
}

}  // namespace async_simple

#endif  // ASYNC_SIMPLE_COMMON_H
