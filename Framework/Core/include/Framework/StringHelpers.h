// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

#ifndef O2_FRAMEWORK_STRINGHELPERS_H_
#define O2_FRAMEWORK_STRINGHELPERS_H_

#include <cstdint>
#include <utility>
#include <type_traits>
#include <string_view>

// CRC32 Table (zlib polynomial) static
constexpr uint32_t crc_table[256] = {0x0L, 0x77073096L, 0xee0e612cL,
                                     0x990951baL, 0x76dc419L, 0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0xedb8832L,
                                     0x79dcb8a4L, 0xe0d5e91eL, 0x97d2d988L, 0x9b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
                                     0x90bf1d91L, 0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL, 0x1adad47dL,
                                     0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L, 0x136c9856L, 0x646ba8c0L, 0xfd62f97aL,
                                     0x8a65c9ecL, 0x14015c4fL, 0x63066cd9L, 0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L,
                                     0x4c69105eL, 0xd56041e4L, 0xa2677172L, 0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL,
                                     0xa50ab56bL, 0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L, 0x32d86ce3L,
                                     0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L, 0x26d930acL, 0x51de003aL, 0xc8d75180L,
                                     0xbfd06116L, 0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L, 0xb8bda50fL, 0x2802b89eL,
                                     0x5f058808L, 0xc60cd9b2L, 0xb10be924L, 0x2f6f7c87L, 0x58684c11L, 0xc1611dabL,
                                     0xb6662d3dL, 0x76dc4190L, 0x1db7106L, 0x98d220bcL, 0xefd5102aL, 0x71b18589L,
                                     0x6b6b51fL, 0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L, 0xf00f934L, 0x9609a88eL,
                                     0xe10e9818L, 0x7f6a0dbbL, 0x86d3d2dL, 0x91646c97L, 0xe6635c01L, 0x6b6b51f4L,
                                     0x1c6c6162L, 0x856530d8L, 0xf262004eL, 0x6c0695edL, 0x1b01a57bL, 0x8208f4c1L,
                                     0xf50fc457L, 0x65b0d9c6L, 0x12b7e950L, 0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL,
                                     0x15da2d49L, 0x8cd37cf3L, 0xfbd44c65L, 0x4db26158L, 0x3ab551ceL, 0xa3bc0074L,
                                     0xd4bb30e2L, 0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL, 0x4369e96aL,
                                     0x346ed9fcL, 0xad678846L, 0xda60b8d0L, 0x44042d73L, 0x33031de5L, 0xaa0a4c5fL,
                                     0xdd0d7cc9L, 0x5005713cL, 0x270241aaL, 0xbe0b1010L, 0xc90c2086L, 0x5768b525L,
                                     0x206f85b3L, 0xb966d409L, 0xce61e49fL, 0x5edef90eL, 0x29d9c998L, 0xb0d09822L,
                                     0xc7d7a8b4L, 0x59b33d17L, 0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL, 0xedb88320L,
                                     0x9abfb3b6L, 0x3b6e20cL, 0x74b1d29aL, 0xead54739L, 0x9dd277afL, 0x4db2615L,
                                     0x73dc1683L, 0xe3630b12L, 0x94643b84L, 0xd6d6a3eL, 0x7a6a5aa8L, 0xe40ecf0bL,
                                     0x9309ff9dL, 0xa00ae27L, 0x7d079eb1L, 0xf00f9344L, 0x8708a3d2L, 0x1e01f268L,
                                     0x6906c2feL, 0xf762575dL, 0x806567cbL, 0x196c3671L, 0x6e6b06e7L, 0xfed41b76L,
                                     0x89d32be0L, 0x10da7a5aL, 0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L,
                                     0x60b08ed5L, 0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L, 0xd1bb67f1L,
                                     0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL, 0xd80d2bdaL, 0xaf0a1b4cL, 0x36034af6L,
                                     0x41047a60L, 0xdf60efc3L, 0xa867df55L, 0x316e8eefL, 0x4669be79L, 0xcb61b38cL,
                                     0xbc66831aL, 0x256fd2a0L, 0x5268e236L, 0xcc0c7795L, 0xbb0b4703L, 0x220216b9L,
                                     0x5505262fL, 0xc5ba3bbeL, 0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L, 0xc2d7ffa7L,
                                     0xb5d0cf31L, 0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L, 0xec63f226L, 0x756aa39cL,
                                     0x26d930aL, 0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x5005713L, 0x95bf4a82L,
                                     0xe2b87a14L, 0x7bb12baeL, 0xcb61b38L, 0x92d28e9bL, 0xe5d5be0dL, 0x7cdcefb7L,
                                     0xbdbdf21L, 0x86d3d2d4L, 0xf1d4e242L, 0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL,
                                     0xf6b9265bL, 0x6fb077e1L, 0x18b74777L, 0x88085ae6L, 0xff0f6a70L, 0x66063bcaL,
                                     0x11010b5cL, 0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L, 0xa00ae278L,
                                     0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L, 0xa7672661L, 0xd06016f7L, 0x4969474dL,
                                     0x3e6e77dbL, 0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L, 0x37d83bf0L, 0xa9bcae53L,
                                     0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L, 0xbdbdf21cL, 0xcabac28aL, 0x53b39330L,
                                     0x24b4a3a6L, 0xbad03605L, 0xcdd70693L, 0x54de5729L, 0x23d967bfL, 0xb3667a2eL,
                                     0xc4614ab8L, 0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL,
                                     0x2d02ef8dL};

consteval uint32_t crc32(char const* str, int length)
{
  uint32_t crc = 0xFFFFFFFF;
  for (auto j = 0; j <= length; ++j) {
    crc = (crc >> 8) ^ crc_table[(crc ^ static_cast<unsigned int>(str[j])) & 0x000000FF];
  }
  return crc;
}

consteval uint32_t compile_time_hash(char const* str)
{
  return crc32(str, static_cast<int>(__builtin_strlen(str)) - 1) ^ 0xFFFFFFFF;
}

constexpr uint32_t runtime_crc32(char const* str, int length)
{
  uint32_t crc = 0xFFFFFFFF;
  for (auto j = 0; j <= length; ++j) {
    crc = (crc >> 8) ^ crc_table[(crc ^ static_cast<unsigned int>(str[j])) & 0x000000FF];
  }
  return crc;
}

constexpr uint32_t runtime_hash(char const* str)
{
  return runtime_crc32(str, static_cast<int>(__builtin_strlen(str)) - 1) ^ 0xFFFFFFFF;
}

template <int N>
consteval uint32_t compile_time_hash_from_literal(const char (&str)[N])
{
  return crc32(str, N - 2) ^ 0xFFFFFFFF;
}

template <char... chars>
struct ConstStr {
  static constexpr char str[] = {chars..., '\0'};
  static constexpr uint32_t hash = compile_time_hash_from_literal(str);
};

template <typename>
struct is_const_str : std::false_type {
};

template <char... chars>
struct is_const_str<ConstStr<chars...>> : std::true_type {
};

template <typename T>
consteval bool is_const_str_v(T)
{
  return is_const_str<T>::value;
}

template <char... chars1, char... chars2>
constexpr auto operator+(const ConstStr<chars1...>&, const ConstStr<chars2...>&)
{
  return ConstStr<chars1..., chars2...>{};
}

namespace const_str_details
{

template <typename T, std::size_t... Is>
constexpr auto as_chars_impl(std::index_sequence<Is...>)
{
  return ConstStr<T::str()[Is]...>{};
}

template <typename T>
constexpr auto as_chars()
{
  return as_chars_impl<T>(
    std::make_index_sequence<T::size() - 1>{});
}

template <int N>
constexpr auto get_str(const char (&str)[N])
{
  return str;
}

template <int N>
constexpr auto get_size(const char (&str)[N])
{
  return N;
}

constexpr auto get_str(const std::string_view& str)
{
  return str.data();
}

constexpr auto get_size(const std::string_view& str)
{
  return str.size() + 1;
}
} // namespace const_str_details

#define CONST_STR(literal)                                  \
  [] {                                                      \
    struct literal_to_chars {                               \
      static constexpr decltype(auto) str()                 \
      {                                                     \
        return const_str_details::get_str(literal);         \
      }                                                     \
      static constexpr decltype(auto) size()                \
      {                                                     \
        return const_str_details::get_size(literal);        \
      }                                                     \
    };                                                      \
    return const_str_details::as_chars<literal_to_chars>(); \
  }()

#endif // O2_FRAMEWORK_STRINGHELPERS_H