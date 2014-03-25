#ifndef STD_EXT_H
#define STD_EXT_H

#include <iostream>
#include <vector>

template<typename T> std::ostream& operator<<(std::ostream&, std::vector<T>&);

#include "std_ext.ipp"

#endif
