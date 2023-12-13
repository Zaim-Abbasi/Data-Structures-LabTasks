#pragma once
#include<iostream>
using namespace std;
template<typename T>
T smaller(T first, T second) {
	if (first < second)
		return first;
	return second;
}
template<typename T>
T smaller(T first, T second, T third) {
	T min = first;
	if (second < min)
		min = second;
	if (third < min)
		min = third;
	return min;
}