#include <iostream>

inline long unsigned int sh(long unsigned int x)
{
    return x % 2 == 1 ? (x + 1) / 2 : x + 1;
}


long unsigned int sp(long unsigned int x)
{
    if (x == 1)
        return 1;

    return sp(x - 1) + sh(x - 1);
}


inline short se(long unsigned int x)
{
    return static_cast<bool>(x % 4 % 3) * 2 - 1;
}


long unsigned int p(long unsigned int x)
{
    if (x == 1)
        return 1;

    long unsigned int n {0};
    for (long unsigned int i {1}, j {1}; i <= x; ++i)
    {
        if (sp(j) == i)
        {
            n += se(j) * p(x - i);
            ++j;
        }
    }
    return n;
}


int main()
{
    int n;
    while (true)
    {
        std::cout << "Enter a number (-1 for list of all numbers): ";
        std::cin >> n;
        if (n < 0)
        {
            std::cout << "n\t\ta(n)\t\t2^n\n";
            for (int i {1}; true; ++i)
                fprintf(stderr, "%d\t\t%lu\t\t%lu\n", i, p(i), (long unsigned int)1 << i);
        }
        else
            std::cout << p(n) << std::endl;
    }
    return 0;
}
