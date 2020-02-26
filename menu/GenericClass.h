#pragma once
#include <type_traits>

template<typename Base,typename T>
class GenericClass
{
	static_assert(std::is_base_of<RoomElement, T>::value, "T must inherit from SomeBase");
};

