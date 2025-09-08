/////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstddef>
#include <iterator>
#include <valarray>

/////////////////////////////////////////////////////////////////////////////

auto equal(std::valarray < int > const & x, std::valarray < int > const & y)
{
    if (auto size = std::size(x); size == std::size(y))
    {
        for (auto i = 0uz; i < size; ++i)
        {
            if (x[i] != y[i])
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////

int main() 
{
    std::valarray < int > x = { 1, 2, 3, 4, 5 };
    
    std::valarray < int > y = { 1, 2, 3 };

//  -------------------------------------------------------------------------

    assert(equal(x[std::valarray < std::size_t > ({ 0, 1, 2 })], y));

//  -------------------------------------------------------------------------

    assert(equal(x[std::slice(0, 3, 1)], y));

//  -------------------------------------------------------------------------

    assert(equal(x[x < 4], y));

//  -------------------------------------------------------------------------

    assert(equal(x + y, std::valarray < int > ({ 2, 4, 6, 4, 5 })));

    assert(equal(x - y, std::valarray < int > ({ 0, 0, 0, 4, 5 })));

    assert(equal(x * y, std::valarray < int > ({ 1, 4, 9, 0, 0 })));

//  assert(equal(x / y, std::valarray < int > ({ 1, 1, 1, 0, 0 }))); // error
}

/////////////////////////////////////////////////////////////////////////////