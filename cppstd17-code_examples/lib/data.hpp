
#ifndef DATA_HPP
#define DATA_HPP

#include <iterator>
#include <iostream>

template<typename T>
void printData(const T& coll)
{
  // print every second element:
  for (std::size_t idx{0}; idx < std::size(coll); ++idx) {
    if (idx % 2 == 0) {
      std::cout << std::data(coll)[idx] << ' ';
    }
  }
  std::cout << '\n';
}

#endif // DATA_HPP


