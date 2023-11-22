
extern rose::Application* rose::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	rose::Log::Init();

	auto app = rose::CreateApplication({ argc, argv });

	app->Run();

	delete app;
}