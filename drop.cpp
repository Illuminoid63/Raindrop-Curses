#include "drop.hpp"
#include <curses.h>
#include <cstdlib>

Drop::Drop()
{
	age = 0;
	center.l = ((rand() % (LINES - 1)) + 1);
	center.c = ((rand() % (COLS - 1)) + 1);
}
void Drop::Draw()
{
	if (age == 0)
	{
		mvaddch(center.l, center.c, 'o');
	}
	else if (age == 1)
	{
		mvaddch(center.l - 1, center.c, '-');
		mvaddch(center.l + 1, center.c, '-');
		mvaddch(center.l, center.c - 1, '(');
		mvaddch(center.l, center.c + 1, ')');
	}
	else if (age == 2)
	{
		mvaddch(center.l - 2, center.c, '-');
		mvaddch(center.l + 2, center.c, '-');
		mvaddch(center.l, center.c - 2, '(');
		mvaddch(center.l, center.c + 2, ')');
		mvaddch(center.l - 1, center.c + 1, '\\');
		mvaddch(center.l + 1, center.c - 1, '\\');
		mvaddch(center.l - 1, center.c - 1, '/');
		mvaddch(center.l + 1, center.c + 1, '/');
	}
	++age;
}
bool Drop::TimeToDie()
{
	if (age >= MAXIMUM_AGE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Storm::Birth()
{
	for (int i = 0; i < ((rand() % 12) + 1); ++i)
	{
		Drop currentDrop;
		drops.push_back(currentDrop);
	}
}
void Storm::Draw()
{
	for (unsigned int j = 0; j < drops.size(); ++j)
	{
		drops.front().Draw();
		drops.push_back(drops.front());
		drops.pop_front();
	}
}
void Storm::Cull()
{
	if (drops.size() > 0)
	{
		while (drops.front().TimeToDie())
		{
			drops.pop_front();
		}
	}
}