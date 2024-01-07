#pragma once
namespace meteor {
	template<typename Base, typename T>
	inline bool instanceof(const T*) {
		return std::is_base_of<Base, T>::value;
	}
}