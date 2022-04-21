#include "KdGameSystem.h"

//インストラクタ
KdGameSystem::KdGameSystem()
{
}

//デストラクタ
KdGameSystem::~KdGameSystem()
{
	Release();
}

//初期化
void KdGameSystem::Init()
{	
	CameraMat = Math::Matrix::CreateTranslation(0.0f, 1.0f, -0.5f);

	Polygon.SetMaterial("Asset/Tree.png");
	pCamera = new KdCamera();
	pCamera->SetProjectionMatrix(60.0f);
	pCamera->SetCameraMatrix(CameraMat);

}

//更新
void KdGameSystem::Update()
{
}

//描画
void KdGameSystem::Draw()
{
	pCamera->SetToShader();

	D3D.WorkShaderManager().m_HD2DShader.BeginNoLighting();
	{

		D3D.WorkShaderManager().m_HD2DShader.
			DrawSquarePolygon(Polygon);
	}
	D3D.WorkShaderManager().m_HD2DShader.EndNoLighting();


}

//解放
void KdGameSystem::Release()
{
	KdSafeDelete(pCamera);
}
