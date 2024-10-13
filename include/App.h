#include "AppBase.h"
#include <string>

class App : public AppBase
{
public:
	App();
	~App() override;

	void init() override;

	void update() override;

private:
	void showMenuBar();

	// Our state
	bool showDemoWindow_;
	std::string textBuffer;
};