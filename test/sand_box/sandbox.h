#pragma once

#include "RoseEngine.h"

class Sandbox : public rose::Layer
{
public:
	Sandbox();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate() override;
	virtual void OnImGuiRender() override;
	//void OnEvent(Hazel::Event& e) override;
private:

};