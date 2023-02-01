#pragma once
#include <stdio.h>
#include <core/Application.h>

extern Fish::Application* Fish::CreateApplication();//ÓÉclientÉú³É
int main(int argc,char **argv) {
	printf("Hello, Engine!");
	auto app = Fish::CreateApplication();
	app->Run();
	delete app;
	return 0;
	
}


