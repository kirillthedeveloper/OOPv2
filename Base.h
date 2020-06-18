#pragma once
#include <string>
#include <iostream>
#include "Container.h"

class Printable {
public:
	virtual operator std::string() const = 0;
};

class Named : public virtual Printable {
public:
	Named(std::string const &name): name(name) {}
protected:
	std::string name;
};

class Shape : public virtual Printable {
public:
	Shape() {
		++shapes_count;
	}

	Shape(Shape const &shape) {
		++shapes_count;
	}

	virtual ~Shape() {
		--shapes_count;
	}
	
	virtual operator std::string() const = 0;

	friend std::ostream & operator << (std::ostream &out, Shape const &p) {
		std::cout << (std::string)p;
		return out;
	}

	static int get_count() {
		return shapes_count;
	}

private:
	static int shapes_count;
};