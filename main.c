#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void) {
	// Our yet to be written doIt() function
	void (*doIt)(void);

	while (1) {
		printf("Press Enter to load ./doit.so\n");
		getc(stdin);

		void* handle = dlopen("./doit.so", RTLD_LAZY);
		char* error = dlerror();
		if (!handle) {
			fprintf(stderr, "%s\n", error);
			continue;
		}

		doIt = (void (*)(void)) dlsym(handle, "doIt");

		error = dlerror();
		if (error != NULL) {
			fprintf(stderr, "%s\n", error);
			dlclose(handle);
			continue;
		}

		doIt();
		dlclose(handle);
	}

	exit(EXIT_SUCCESS);
}
