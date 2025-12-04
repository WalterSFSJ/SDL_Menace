#pragma once
#include "Transform.h"
#include "Renderer.h"
#include "RigidBody.h"
class Object
{
private:
	bool _isPendingDestroy = false;
	
protected:
	Renderer * _renderer = nullptr;
	Transform * _transform;
	RigidBody* physics;
public:
	Object()
	{
		_transform = new Transform();
		physics = new RigidBody(_transform);
	}
	void ChangeImage(std::string path) {
		_renderer->ChangeImage(path);
	}
	~Object()
	{
		delete _transform;
		_transform = nullptr;
		
		delete _renderer;
		_renderer = nullptr;

		delete physics;
		physics = nullptr;
	}
	void GetDestroyed() { _isPendingDestroy = true; }
	virtual void Update()
	{
		if (physics != nullptr)
			physics->Update(0.02f);

		_renderer->Update(0.02f); // 50 FPS
	}

	virtual void Render()
	{
		_renderer->Render();
	}
	
	Transform * GetTransform() { return _transform; }
	// De moment no fan res
	bool IsPendingDestroy() const { return _isPendingDestroy; }
	virtual void Destroy() { _isPendingDestroy = true; }
	
	RigidBody* GetRigidBody() { return physics; }

};