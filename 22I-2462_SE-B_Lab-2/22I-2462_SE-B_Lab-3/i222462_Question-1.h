#pragma once
using namespace std;
template<typename T>
T smaller(T first, T second) {
	if (first < second)
		return first;
	return second;
}
