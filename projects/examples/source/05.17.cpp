//////////////////////////////////////////////////////

#include <iostream>

//////////////////////////////////////////////////////

class Entity
{
public :

	virtual ~Entity() = default;

//  ------------------------------

	virtual void test() const = 0;
};

//////////////////////////////////////////////////////

class Client_v1 : public Entity 
{ 
public :

	void test() const override 
	{ 
		std::cout << "Client_v1::test\n";
	} 
};

//////////////////////////////////////////////////////

class Server_v1 : public Entity 
{ 
public :

	void test() const override 
	{ 
		std::cout << "Server_v1::test\n";
	} 
};

//////////////////////////////////////////////////////

void test_v1(Entity const & entity)
{
	entity.test();
}

//////////////////////////////////////////////////////

class Client_v2 
{ 
public :

	void test() const 
	{ 
		std::cout << "Client_v2::test\n";
	} 
};

//////////////////////////////////////////////////////

class Server_v2 
{ 
public :

	void test() const 
	{ 
		std::cout << "Server_v2::test\n";
	} 
};

//////////////////////////////////////////////////////

template < typename E > void test_v2(E const & entity)
{
	entity.test();
}

//////////////////////////////////////////////////////

int main()
{
	Entity * entity = new Client_v1;

//  --------------------------------

	test_v1(*entity);

//  --------------------------------

	delete entity;

//  --------------------------------

	test_v2(Client_v2());
}

//////////////////////////////////////////////////////