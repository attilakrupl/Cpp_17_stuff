#include "Connection.h"

#include <vector>
#include <iostream>

int main(int argc, char** argv)
{
	std::vector<Connection> connections = { Connection{ "X124", "10.10.136.95" }, Connection{ "X125", "10.10.136.96" }, Connection{ "X125", "10.10.136.97" }, Connection{ "X126", "10.10.136.98" }};

	for (const auto& [connName, connAddr] : connections)
	{
		std::cout << connName << ": " << connAddr << std::endl;
	}

	return 0;
}