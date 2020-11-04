#include <iostream>

#include "Dict.h"


Dict::Dict(void)
{
	//TO DO
	this->length = 0;
}
void Dict::add(const std::string key, int value)
{
	//TO DO
	for (size_t i = 0; i < this->length; i++)
		if (items[i].get_key() == key)
		{
			std::cerr << "Key already exists in the dict" << std::endl;
			_exit(1);
		}
	Item temp(key, value);
	items[length] = temp;
	length++;
	
}
void Dict::remove(const std::string& key)
{
	//TO DO
	bool flag = false;
	for (size_t i = 0; i < this->length+1; i++)
		if (items[i].get_key() == key)
			flag = true;
		else if (flag)
		{
			items[i] = items[i + 1];
		}
}
int Dict::get(const std::string& key)
{
	for (size_t i = 0; i < this->length; i++)
		if (items[i].get_key() == key)
			return items[i].get_value();
	return -1;
	//TO DO
}
void Dict::change(const std::string& key, int new_value)
{
	//TO DO
	for (size_t i = 0; i < this->length; i++)
		if (items[i].get_key() == key)
			items[i].set_value(new_value);
}
Item::Item(const std::string semi_key, const int semi_value)
{
	key = semi_key;
	value = semi_value;
}

std::string Item::get_key() const
{
	return this->key;
}

int Item::get_value() const
{
	return this->value;
}
void Item::set_value(int new_value)
{
	this->value = new_value;
}