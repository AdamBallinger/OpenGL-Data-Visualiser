#include "PieSectorData.h"

#include <cmath>

PieSectorData::PieSectorData()
{

}

void PieSectorData::SetColor(Vector3f color)
{
	sectorColor = color;
}

Vector3f PieSectorData::GetColor()
{
	return sectorColor;
}

void PieSectorData::SetData(int _data)
{
	data = _data;
}

int PieSectorData::GetData()
{
	return data;
}

void PieSectorData::SetAngle(float _angle)
{
	angle = _angle;
}

float PieSectorData::GetAngle()
{
	return round(angle);
}