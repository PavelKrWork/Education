/////////////////////////////////////////////////////////////////////

#include <cassert>
#include <utility>
#include <vector>

/////////////////////////////////////////////////////////////////////

template < typename T, typename C = std::vector < T > > class Stack
{
public :

	void push(T x);

//  -----------------

	auto top() const;

//  -----------------

	void pop();

private :

	C m_container;
};

/////////////////////////////////////////////////////////////////////

template < typename T, typename C > void Stack < T, C > ::push(T x)
{
	m_container.push_back(std::move(x));
}

/////////////////////////////////////////////////////////////////////

template < typename T, typename C > auto Stack < T, C > ::top() const
{
	return m_container.back();
}

/////////////////////////////////////////////////////////////////////

template < typename T, typename C > void Stack < T, C > ::pop()
{
	m_container.pop_back();
}

/////////////////////////////////////////////////////////////////////

int main()
{
    Stack < int > stack;

//  -------------------------

	stack.push(1);

	stack.push(2);

//  -------------------------
	
	assert(stack.top() == 2);

//  -------------------------
	
	stack.pop();

//  -------------------------
	
	assert(stack.top() == 1);
}

/////////////////////////////////////////////////////////////////////