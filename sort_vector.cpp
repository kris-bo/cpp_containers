# include "header.hpp"

extern int n;

void merge_sorted_arrays(std::vector<int> &a, int l, int m, int r)
{  
		//std::cout << '\n' << "in sorting" << '\n';

	//std::cout << l << m << r << '\n' << '\n';
	int left_length = m - l + 1;
  int right_length = r - m;
  
  int temp_left[left_length];
  int temp_right[right_length];
  
  int i, j, k;
  
  for (int i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];
  
  for (int i = 0; i < right_length; i++)
    temp_right[i] = a[m + 1 + i];
  

  for (i = 0, j = 0, k = l; k <= r; k++)
  {

    if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]))
    {
      a[k] = temp_left[i];
      i++;
    }

    else
    {
      a[k] = temp_right[j];
      j++;
    }
  }  
}

void merge_sort_recursion(std::vector<int> &a, int l, int r)
{
	//std::cout << "in msr " << n << '\n';

	n++;
	
  if (l < r)
  {
    int m = l + (r - l) / 2;
  
	//std::cout << l << m << r << '\n';

    merge_sort_recursion(a, l, m);
	//std::cout << "after ms 1"<< '\n';

	//std::cout << l << m << r << '\n';
    merge_sort_recursion(a, m + 1, r);
  	//std::cout << "after ms 2"<< '\n';


    merge_sorted_arrays(a, l, m, r);
  }
}

void merge_sort(std::vector<int> &a, int length)
{


  merge_sort_recursion(a, 0, length - 1);
}
