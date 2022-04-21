#include "KdGameSystem.h"

//�C���X�g���N�^
KdGameSystem::KdGameSystem()
{
}

//�f�X�g���N�^
KdGameSystem::~KdGameSystem()
{
	Release();
}

//������
void KdGameSystem::Init()
{	
	CameraMat = Math::Matrix::CreateTranslation(0.0f, 1.0f, -0.5f);

	Polygon.SetMaterial("Asset/Tree.png");
	pCamera = new KdCamera();
	pCamera->SetProjectionMatrix(60.0f);
	pCamera->SetCameraMatrix(CameraMat);

}

//�X�V
void KdGameSystem::Update()
{
}

//�`��
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

//���
void KdGameSystem::Release()
{
	KdSafeDelete(pCamera);
}
