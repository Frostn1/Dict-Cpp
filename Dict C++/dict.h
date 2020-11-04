#pragma once
#ifndef DICT_H
#define DICT_H


#include <string>
class Item
{
public:
	Item(const std::string semi_key, const int semi_value);
	int get_value() const;
	void set_value(int new_value);
	std::string get_key() const;
private:
	std::string key;
	int value;
};

class Dict
{
public:
	Dict();
	void add(const std::string key, int value);
	void remove(const std::string& key);
	int get(const std::string& key);
	void change(const std::string& key, int new_value);
private:
	Item *items;
	unsigned int length;
};



#endif // !DICT_H