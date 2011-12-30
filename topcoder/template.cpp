#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES

#include <math.h>
#include <limits.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <numeric>
#include <functional>
#include <algorithm>
#include <utility>

#ifndef _countof
#define _countof(a) (sizeof(a) / sizeof(*a))
#endif

class MyDouble {
private:
	double abs;
	double base;
	double mul;
	double div;
public:
	MyDouble() : abs(0), base(1), mul(1), div(1) { }
	MyDouble(const double base) : abs(0), base(base), mul(1), div(1) { }
	MyDouble(const MyDouble &other) : abs(other.abs), base(other.base), mul(other.mul), div(other.div) { }
	MyDouble &AddBase(const double value) {
		this->base += value;
		return *this;
	}
	MyDouble AddBaseT(const double value) const {
		MyDouble result = *this;
		return result.AddBase(value);
	}
	MyDouble &AddAbs(const double value) {
		this->abs += value;
		return *this;
	}
	MyDouble AddAbsT(const double value) const {
		MyDouble result = *this;
		return result.AddAbs(value);
	}
	MyDouble &operator*=(const double value) {
		this->mul *= value;
		return *this;
	}
	MyDouble operator*(const double value) const {
		MyDouble result = *this;
		result *= value;
		return result;
	}
	MyDouble &operator/=(const double value) {
		this->div *= value;
		return *this;
	}
	MyDouble operator/(const double value) const {
		MyDouble result = *this;
		result /= value;
		return result;
	}
	bool operator<(const double value) const {
		return Calc() - std::numeric_limits<double>::epsilon() < value;
	}
	bool operator<=(const double value) const {
		return *this < value || *this == value;
	}
	bool operator>(const double value) const {
		return Calc() + std::numeric_limits<double>::epsilon() > value;
	}
	bool operator>=(const double value) const {
		return *this > value || *this == value;
	}
	bool operator==(const double value) const {
		return Calc() == value || (*this < value && *this > value);
	}
	bool operator<(const MyDouble &value) const {
		return Calc() - std::numeric_limits<double>::epsilon() < value.Calc();
	}
	bool operator<=(const MyDouble &value) const {
		return *this < value || *this == value;
	}
	bool operator>(const MyDouble &value) const {
		return Calc() + std::numeric_limits<double>::epsilon() > value.Calc();
	}
	bool operator>=(const MyDouble &value) const {
		return *this > value || *this == value;
	}
	bool operator==(const MyDouble &value) const {
		return Calc() == value.Calc() || (*this < value && *this > value);
	}
	double Calc() const {
		return this->abs + this->base * this->mul / this->div;
	}
};

template<typename T>
struct type_only {
	type_only(void *) { }
};
struct auto_type_base {
	operator bool() const { return false; }
};
template<typename T>
struct auto_type : auto_type_base {
	mutable T impl;
	auto_type(const T &t) : impl(t) {}
};
template<typename Container>
auto_type<typename const Container *> containerHolder(const Container &c) {
	return auto_type<typename const Container *>(&c);
}
template<typename Iterator>
typename type_only<Iterator> getIteratorType(const Iterator &) { return 0; }
#define GET_TYPE(type) (true ? NULL : (type))
#define GET_CONTAINER_TYPE(container) GET_TYPE(&(container))
#define GET_ITERATOR_TYPE(container) GET_TYPE(getIteratorType(std::begin(container)))
template<typename Container, typename Iterator>
auto_type<typename Iterator> createBeginIterator(const auto_type_base &c, const Container *, const type_only<Iterator>) {
	return std::begin(*(static_cast<const auto_type<Container *> *>(&c)->impl));
}
template<typename Container, typename Iterator>
auto_type<typename Iterator> createEndIterator(const auto_type_base &c, const Container *, const type_only<Iterator>) {
	return std::end(*(static_cast<const auto_type<Container *> *>(&c)->impl));
}
template<typename Iterator>
typename Iterator &getIterator(const auto_type_base &it, const type_only<Iterator>) {
	return static_cast<const auto_type<Iterator> *>(&it)->impl;
}
#define FOREACH(var, container) \
	if(const auto_type_base &c = containerHolder(container)) {} else \
	if(const auto_type_base &it = createBeginIterator(c, GET_CONTAINER_TYPE(container), GET_ITERATOR_TYPE(container))) {} else \
	if(const auto_type_base &end = createEndIterator(c, GET_CONTAINER_TYPE(container), GET_ITERATOR_TYPE(container))) {} else \
	for(bool MY_FOREACH_LOOP_FLAG = true; \
		MY_FOREACH_LOOP_FLAG && getIterator(it, GET_ITERATOR_TYPE(container)) != getIterator(end, GET_ITERATOR_TYPE(container)); \
		(MY_FOREACH_LOOP_FLAG ? ++getIterator(it, GET_ITERATOR_TYPE(container)) : (void)NULL) \
	) \
		if(MY_FOREACH_LOOP_FLAG = false) {} else \
		for(var = *getIterator(it, GET_ITERATOR_TYPE(container)); !MY_FOREACH_LOOP_FLAG; MY_FOREACH_LOOP_FLAG = true)

using namespace std;

class $CLASSNAME$ {
public:
	$RC$ $METHODNAME$($METHODPARMS$) {
		
	}
	$TESTCODE$
};
$BEGINCUT$
int main() {
	$CLASSNAME$ ___test;
	___test.run_test(-1);
	::getchar();
	return 0;
}
$ENDCUT$