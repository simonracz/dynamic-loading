#include <cstdlib>
#include <dlfcn.h>
#include <string>
#include <iostream>

#include <icamera.h>

using namespace std;

[[noreturn]] void print_usage_and_exit() {
    cout << "Usage:\n";
    cout << "    ./dynamic_cpp [1|2]\n";
    std::exit(EXIT_FAILURE);
}

void checkDlError(void* handle) {
    char* error = dlerror();
    if (!handle || error != NULL) {
        cerr << error << "\n";
        if (handle) dlclose(handle);
        print_usage_and_exit();
    }
}

int main(int argc, char* argv[]) {
	ICamera* (*createCamera)(void);
    void (*destroyCamera)(ICamera*);

    if (argc != 2) {
        print_usage_and_exit();
    }

    char c = argv[1][0];
    void* handle = nullptr;
    switch (c) {
        case '1':
            handle = dlopen("./cupcake.so", RTLD_LAZY);
            break;
        case '2':
            handle = dlopen("./donut.so", RTLD_LAZY);
            break;
        default:
            print_usage_and_exit();
            break;
    }
    checkDlError(handle);

	createCamera = (ICamera* (*)(void)) dlsym(handle, "createCamera");
    checkDlError(handle);
    destroyCamera = (void (*)(ICamera*)) dlsym(handle, "destroyCamera");
	checkDlError(handle);

    ICamera* cam = createCamera();
    cam->init();
    cam->start();
    cam->stop();
    destroyCamera(cam);

    dlclose(handle);

	exit(EXIT_SUCCESS);
}