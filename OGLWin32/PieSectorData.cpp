#include "PieSectorData.h"

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

void PieSectorData::SetSegments(int _segments)
{
	segments = _segments;
}

int PieSectorData::GetSegments()
{
	return segments;
}