#pragma once
#ifndef DICT_H
#define DICT_H


#include <string>
#include <vector>
 

class Item
{
public:
	Item(const std::string semi_key, const int semi_value);
	Item(const std::string semi_key, const std::string semi_value);
	void set_value(int new_value);
	int get_type();
	//auto get_value() const;
	void set_value(std::string new_value);
	std::string get_key() const;

	int valueI;
	std::string valueS;
private:
	std::string key;
	
	int valueType;
};

class Value
{
public:
	Value(std::string value);
	Value(int value);
	std::string get_str(std::string val);
	int get_int(int val);
};

class Dict
{
public:
	Dict();
	void add(const std::string key, int value);
	void add(const std::string key, std::string value);
	void remove(const std::string& key);
	void get(const std::string key);
	void change(const std::string& key, int new_value);
	std::string get_str(std::string val);
	int get_int(int val);
private:
	std::vector<Item> items;
	unsigned int length;
};



#endif // !DICT_H