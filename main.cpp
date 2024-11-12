
# include "header.hpp"

using namespace std;
int n = 0;

std::deque<int>	init_deque(int num, char **av)
{
	std::deque<int>		dq;
	int	i;
	int	j;

	i = 1;
	while(i <= num)
	{
		j = 0;
		while (j < strlen(av[i]))
		{
			if (!isdigit(av[i][j]))
			{
				std::cout << "ERROR: invalid input.";
				exit (1);
			}
			j++;
		}
		dq.push_back(atoi(av[i]));
		i++;
	}
	return (dq);

}

std::vector<int>	init_vector(int num, char **av)
{
	std::vector<int>		data;
	int	i;
	int	j;

	i = 1;
	while(i <= num)
	{
		j = 0;
		if(!strlen(av[i]))
		{
			std::cout << "ERROR: invalid input.";
			exit (1);
		}
		while (j < strlen(av[i]))
		{
			if (!isdigit(av[i][j]))
			{
				std::cout << "ERROR: invalid input.";
				exit (1);
			}
			j++;
		}
		data.push_back(atoi(av[i]));
		i++;
	}
	return (data);

}

double	print_time(std::string msg, timeval start, timeval end)
{
	long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double sum = seconds + microseconds*1e-6;
	if (msg.length())
	{
		std::cout << msg << "\t\t";
		// printf("Time to initialize with vector: %.6f seconds.\n", sum);
		printf("%.6f seconds.\n", sum);
	}
	return (sum);

}

int	main(int ac, char **av)
{
	std::vector<int>		data;
	std::deque<int>		dq;
	struct timeval start;
	struct timeval end;
	double pt_one;
	double pt_two;

	int	i;
	
	if (ac < 2)
	{
		std::cout << "Invalid input.\n";
		exit (1);
	}
	gettimeofday(&start, NULL);
	data = init_vector(ac - 1, av);
	gettimeofday(&end, NULL);
    pt_one = print_time("", start, end); 

	i = 0;
	std::cout << "BEFORE:\n";
	while(i < ac - 1)
	{
		std::cout << data[i] << ' ';
		i++;
	}
	std::cout << '\n';

	gettimeofday(&start, NULL);
	merge_sort(data, ac - 1);
	gettimeofday(&end, NULL);

	i = 0;
	std::cout << "AFTER:\n";
	while(i < ac - 1)
	{
		std::cout << data[i] << ' ';
		i++;
	}
	std::cout << '\n';

	printf("Time to initialize with vector: %.6f seconds.\n", pt_one);

    pt_two = print_time("Time to sort with vector: ", start, end); 
	// std::cout << "TOTAL for VECTOR " << pt_one + pt_two << " seconds. \n";
	printf("TOTAL for VECTOR (%i elements): %.6f seconds.\n", ac - 1, pt_one + pt_two);


	gettimeofday(&start, NULL);
	dq = init_deque(ac - 1, av);
	gettimeofday(&end, NULL);
    pt_one = print_time("Time to initialize with deque: ", start, end); 

	gettimeofday(&start, NULL);
	merge_sort_dq(dq, ac - 1);
	gettimeofday(&end, NULL);
    pt_two = print_time("Time to sort with deque: ", start, end); 
	// std::cout << "TOTAL for DEQUE " << pt_one + pt_two << " seconds. \n";
	printf("TOTAL for DEQUE (%i elements): %.6f seconds.\n", ac - 1, pt_one + pt_two);

        
    // printf("Time measured: %.3f seconds.\n", elapsed_one);


	// i = 0;
	// while(i < ac - 1)
	// {
	// 	std::cout << dq[i];
	// 	i++;
	// }
	// std::cout << '\n';
	// i = 0;
	// while(i < ac - 1)
	// {
	// 	std::cout << data[i];
	// 	i++;
	// }
	// std::cout << '\n';

}