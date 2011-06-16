
#include "Application.h"

#include "Win32RenderWindow.h"
#include "RendererDX11.h"
#include "ScriptManager.h"

#include "ViewPerspective.h"
#include "GeometryDX11.h"
#include "MaterialDX11.h"
#include "Camera.h"
#include "Scene.h"
#include "SkinnedActor.h"
#include "AnimationStream.h"

using namespace Glyph3;

class App : public Application
{

public:
	App();
	
public:
	virtual void Initialize();
	virtual void Update();
	virtual void Shutdown();

	virtual bool ConfigureEngineComponents();
	virtual void ShutdownEngineComponents();

	virtual bool HandleEvent( IEvent* pEvent );
	virtual std::wstring GetName( );

protected:

	RendererDX11*			m_pRenderer11;
	ScriptManager*			m_pScriptMgr;
	Win32RenderWindow*		m_pWindow;

	ResourcePtr				m_RenderTarget;
	ResourcePtr				m_DepthTarget;

	ViewPerspective*		m_pRenderView;
	Node3D*					m_pNode;
	SkinnedActor*			m_pActor;
	
	Camera*					m_pCamera;

	AnimationStream<Vector3f>*	m_pAnimationStream;

	bool					m_bSaveScreenshot;
};
