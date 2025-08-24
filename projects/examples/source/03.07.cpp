////////////////////////////////////////////////////

#include <cassert>
#include <iostream>

////////////////////////////////////////////////////

class Entity
{
public :

	Entity(int x) : m_x(x) {}

//  ----------------------------------

	static void test()
	{
		std::cout << "Entity::test\n";
	}

//  ----------------------------------

	static inline auto s_x = 1;

private :

	int m_x = 0;
};

////////////////////////////////////////////////////

struct Client { struct Server * server = nullptr; };

struct Server { struct Client * client = nullptr; };

////////////////////////////////////////////////////

int main()
{
	Entity entity_1(1);
	
	Entity entity_2(2);

//  -------------------------

	assert(Entity::s_x == 1);

//  -------------------------

	Client client;

	Server server;

//  -------------------------

	server.client = &client;

	client.server = &server;

//  -------------------------

	Entity::test();
}

////////////////////////////////////////////////////