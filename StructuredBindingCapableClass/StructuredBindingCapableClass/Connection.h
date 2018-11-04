#pragma once

#include <string>

class Connection;

namespace std
{
	template <> struct tuple_size<Connection> : std::integral_constant<size_t, 2> { };
	template <> struct tuple_element<0, Connection> { using type = std::string; };
	template <> struct tuple_element<1, Connection> { using type = std::string; };
};

class Connection
{
public:
	Connection(std::string name, std::string address) :
		m_name(name),
		m_address(address)
	{}

	virtual ~Connection() {}
	
	void validate(bool isValid)
	{
		m_isValid = isValid;
	}

	std::string getName()
	{
		return m_name;
	}
	std::string getAddress()
	{
		return m_address;
	}

	template <size_t I>
	decltype(auto) get() const
	{
		if constexpr (I == 0)
		{
			return m_name;
		}
		else if constexpr (I == 1)
		{
			return m_address;
		}
	}

private:
	std::string m_name;
	std::string m_address;
	bool m_isValid = false;
};