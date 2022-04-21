#pragma once

class KdGameSystem
{
public:
	KdGameSystem();
	~KdGameSystem();

	void Init();
	void Update();
	void Draw();


private:

	void Release();

	KdSquarePolygon Polygon;

	KdCamera* pCamera;
	Math::Matrix CameraMat;



};