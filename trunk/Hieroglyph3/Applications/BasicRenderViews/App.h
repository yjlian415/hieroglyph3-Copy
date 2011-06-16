
#include "Application.h"

#include "Win32RenderWindow.h"
#include "RendererDX11.h"

#include "Entity3D.h"
#include "Node3D.h"
#include "ViewPerspective.h"

#include "GeometryLoaderDX11.h"
#include "GeometryDX11.h"

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
	Win32RenderWindow*		m_pWindow;
	
	int						m_iSwapChain;
	ResourcePtr				m_RenderTarget;
	ResourcePtr				m_DepthTarget;

	bool					m_bSaveScreenshot;

	ViewPerspective*		m_pRenderView;
	Node3D*					m_pRoot;
	Entity3D*				m_pEntity[10];
	
	GeometryDX11*			m_pGeometry;
	MaterialDX11*			m_pMaterial;
	
	Vector4f				m_TessParams;
};
