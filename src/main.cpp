#include "App.h"

int main(int argc, char* argv[]) {
	App application("diary.md");

	return application.run(argc, argv);
}