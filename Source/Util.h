#ifndef _UTIL_H
#define _UTIL_H 1

#include <Windows.h>
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WTimer>
#include <Wt/WImage>
#include <Wt/WHBoxLayout>
#include <Wt/WVBoxLayout>
#include <Wt/WRectArea>
#include <Wt/WMessageBox>
#include <Wt/WSpinBox>
#include <Wt/WPainter>
#include <Wt/WPaintedWidget>

std::string IntToString(long int number);

struct TotalCost{
	int FiveCost[5];

	TotalCost(int wood, int coins, int stone, int steel, int mana)
	{
		FiveCost[0] = wood;
		FiveCost[1] = coins;
		FiveCost[2] = stone;
		FiveCost[3] = steel;
		FiveCost[4] = mana;
	}
};

struct Vector2D{
	int X;
	int Y;

	Vector2D(int x, int y)
	{
		X = x;
		Y = y;
	}
};

#endif