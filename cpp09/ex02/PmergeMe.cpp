#include "PmergeMe.hpp"

namespace {

template <typename RandomIt>
void mergeInsertSort(RandomIt first, RandomIt last) {
	std::size_t size = last - first;
	if (size <= 16) {
		for (RandomIt i = first + 1; i < last; ++i) {
			typename std::iterator_traits<RandomIt>::value_type key = *i;
			RandomIt j = i;
			while (j > first && *(j - 1) > key) {
				*j = *(j - 1);
				--j;
			}
			*j = key;
		}
		return;
	}

	RandomIt mid = first + size / 2;
	mergeInsertSort(first, mid);
	mergeInsertSort(mid, last);

	typedef typename std::iterator_traits<RandomIt>::value_type T;
	std::vector<T> buffer;
	buffer.reserve(size);

	RandomIt left = first;
	RandomIt right = mid;
	while (left != mid && right != last) {
		if (*left <= *right) {
			buffer.push_back(*left);
			++left;
		} else {
			buffer.push_back(*right);
			++right;
		}
	}
	while (left != mid) {
		buffer.push_back(*left);
		++left;
	}
	while (right != last) {
		buffer.push_back(*right);
		++right;
	}

	for (std::size_t i = 0; i < buffer.size(); ++i)
		first[i] = buffer[i];
}

} // anonymous namespace

void PmergeMe::sortVector(std::vector<int>& v) {
	if (!v.empty())
		mergeInsertSort(v.begin(), v.end());
}

void PmergeMe::sortDeque(std::deque<int>& d) {
	if (!d.empty())
		mergeInsertSort(d.begin(), d.end());
}

