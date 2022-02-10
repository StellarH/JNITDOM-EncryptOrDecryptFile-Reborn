/*
 * Copyright (C) 2021-2022 Twilight-Dream
 *
 * 本文件是 TDOM-EncryptOrDecryptFile-Reborn 的一部分。
 *
 * TDOM-EncryptOrDecryptFile-Reborn 是自由软件：你可以再分发之和/或依照由自由软件基金会发布的 GNU 通用公共许可证修改之，无论是版本 3 许可证，还是（按你的决定）任何以后版都可以。
 *
 * 发布 TDOM-EncryptOrDecryptFile-Reborn 是希望它能有用，但是并无保障;甚至连可销售和符合某个特定的目的都不保证。请参看 GNU 通用公共许可证，了解详情。
 * 你应该随程序获得一份 GNU 通用公共许可证的复本。如果没有，请看 <https://www.gnu.org/licenses/>。
 */
 
 /*
 * Copyright (C) 2021-2022 Twilight-Dream
 *
 * This file is part of TDOM-EncryptOrDecryptFile-Reborn.
 *
 * TDOM-EncryptOrDecryptFile-Reborn is free software: you may redistribute it and/or modify it under the GNU General Public License as published by the Free Software Foundation, either under the Version 3 license, or (at your discretion) any later version.
 *
 * TDOM-EncryptOrDecryptFile-Reborn is released in the hope that it will be useful, but there are no guarantees; not even that it will be marketable and fit a particular purpose. Please see the GNU General Public License for details.
 * You should get a copy of the GNU General Public License with your program. If not, see <https://www.gnu.org/licenses/>.
 */
 
#pragma once

#ifndef  SUPPORT_LINRARY_HPP
#define SUPPORT_LINRARY_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <string_view>

#include <typeinfo>
#include <type_traits>

#include <algorithm>
#include <iomanip>
#include <utility>
#include <stdexcept>
#include <chrono>
#include <charconv>
#include <limits>
#include <optional>
#include <span>
#include <bitset>
#include <random>
#include <filesystem>
#include <ranges>

#include <iterator>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

//Multi-Threading-Devlopment-ISO-C++ Standard Libary
#include <atomic>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <future>
#include <functional>
#include <condition_variable>

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <ctime>

#include "Support-MyType.hpp"

#define NAMESPACE_BEGIN( This_Name ) namespace This_Name {
#define NAMESPACE_END }

#endif // !SUPPORT_LINRARY_H
