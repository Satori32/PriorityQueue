#pragma once
#include <deque>
#include <cstdint>
#include <tuple>
#include <algorithm>

template<class T,class Order=std::intmax_t>
class PriorityQueue {
	typedef std::tuple<Order, T> Data;
public:
	bool push(const T& In,const Order& O) {
		Q.push_back({ O,In });
		force_sort();
		return true;
	}

	bool pop_front() {
		Q.pop_front();
		return true;
	}
	bool pop_back() {
		Q.pop_back();
		return true;
	}

	T& back() {
		return std::get<1>(Q.back());
	}	

	T& front() {
		return std::get<1>(Q.front());
	}
	std::size_t size() {
		return Q.size();
	}

	std::deque<Data>::iterator begin() {
		return Q.begin();
	}
	std::deque<Data>::iterator end() {
		return Q.end();
	}

	Data& operator[](std::size_t In) {
		return Q[In];
	}

	bool force_sort() {
		std::stable_sort(Q.begin(), Q.end(), [](const auto& A, const auto& B) {return std::get<0>(A) < std::get<0>(B); });
		return true;
	}
	
protected:
	std::deque<Data> Q;
};