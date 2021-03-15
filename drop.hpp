#pragma once
#include <deque>

struct Drop
{

	Drop();
	void Draw();
	bool TimeToDie();

	struct
	{
		int l, c;
	} center;
	int age;

	static const int MAXIMUM_AGE = 3;
};

struct Storm
{
	void Birth();
	void Cull();
	void Draw();
	std::deque<Drop> drops;
};