#ifndef __MAIN_H__
#define __MAIN_H__

#include <ostream>
#include <type_traits>
// yet (another) return code
enum class yrc {
    ERROR = -1,
    OK = 0,
};

inline std::ostream &operator<<(std::ostream &out, yrc rc) {
    switch (rc) {
    case yrc::ERROR:
        return out << "ERROR";
    case yrc::OK:
        return out << "OK";
    }
    return out << static_cast<std::underlying_type_t<yrc>>(rc);
}

#endif  // __MAIN_H__
