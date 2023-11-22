#include "RoseEngine.h"


#include "sandbox.h"
#include "ExampleLayer.h"

class SandboxApp : public rose::Application
{
public:
	Sandbox(const rose::ApplicationSpecification& specification)
		: rose::Application(specification)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox());
	}

	~Sandbox()
	{
	}
};

rose::Application* rose::CreateApplication(rose::ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../Hazelnut";
	spec.CommandLineArgs = args;

	return new SandboxApp(spec);
}
