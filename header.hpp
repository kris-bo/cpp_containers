#ifndef HEADER_H
#define HEADER_H

# include <iostream>
# include <fstream>
# include <cstring>
# include <map> 
#include <iomanip>
# include <deque>
# include <vector>
#include <sys/time.h>
#include <unistd.h>

void merge_sort(std::vector<int> &a, int length);
void merge_sort_dq(std::deque<int> &a, int length);

#endif