/*
 * MaxSizeEvent.hpp
 * A convenience template meta-function that determines which
 * type out of a set has the largest size.  This allows us
 * to figure what the largest event is out of all defined
 * events.
 *
 *  Created on: Jan 28, 2020
 *      Author: jcochran
 */

#ifndef APP_COMMON_INCLUDE_MAXSIZEEVENT_HPP_
#define APP_COMMON_INCLUDE_MAXSIZEEVENT_HPP_

#include <type_traits>

namespace COMMON {


struct EmptyType {};

template <typename... EventTypes>
struct FindMaxSizeEvent { };

template <>
struct FindMaxSizeEvent<> {
    using type = EmptyType;
};

template <typename FirstEventType, typename... EventTypes>
struct FindMaxSizeEvent<FirstEventType, EventTypes...> {
private:
    using tail_type = typename FindMaxSizeEvent<EventTypes...>::type;

    static constexpr bool firstTypeGreater() {
        return sizeof(FirstEventType) > sizeof(tail_type);
    }

public:
    using type = typename std::conditional<firstTypeGreater(),
                                           FirstEventType,
                                           tail_type>::type;
};



}

#endif /* APP_COMMON_INCLUDE_MAXSIZEEVENT_HPP_ */
