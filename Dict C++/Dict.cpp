#include <iostream>

#include "Dict.h"
#include <string_view>


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
	
	//Item temp(key, value); Was my old config
	//items[length] = temp;
	items.push_back(Item(key, value));
	length++;
	
}
void Dict::add(const std::string key, std::string value)
{
	//TO DO
	for (size_t i = 0; i < this->length; i++)
		if (items[i].get_key() == key)
		{
			std::cerr << "Key already exists in the dict" << std::endl;
			_exit(1);
		}
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
void Dict::get(const std::string key)
{
	//TO DO
	for (size_t i = 0; i < this->length; i++)
		if (items[i].get_key() == key)
		{
			if (!items[i].get_type())
			{
				get_int(items[i].valueI);
			}
			else if (items[i].get_type() == 2)
			{
				get_str(items[i].valueS);
			}
		}
	std::cerr << "Key doesnt exist in the dict" << std::endl;
	_exit(1);
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
	valueI = semi_value;
	valueType = 0;
}//Int
Item::Item(const std::string semi_key, const std::string semi_value)
{
	key = semi_key;
	valueS = semi_value;
	valueType = 2;
}//String 

std::string Item::get_key() const
{
	return this->key;
}

/*auto Item::get_value() const
{
	switch (this->valueType)
	{
	case 0:return valueI;	
	//case 1:return this->valueF;
	//break;
	case 2:return valueS;
	default:
		return -1;
	
	}
	
}*/

int Item::get_type() 
{
	return valueType;
}
void Item::set_value(int new_value)
{
	this->valueI = new_value;
}

void Item::set_value(std::string new_value)
{
	this->valueS = new_value;
}

Value::Value(std::string value)
{
	get_str(value);
}

Value::Value(int value)
{
	get_int(value);
}

std::string Dict::get_str(std::string val)
{
	return val;
}

int Dict::get_int(int val)
{
	return val;
}
