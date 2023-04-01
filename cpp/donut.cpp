#include <icamera.h>
#include <iostream>

class DonutCamera : ICamera{
    public:
    DonutCamera() {
        std::cout << "Donut()\n";
    }
    void init() {
        std::cout << "Donut Init\n";
    };
    void start() {
        std::cout << "Donut Start\n";
    };
    void stop() {
        std::cout << "Donut Stop\n";
    };
    ~DonutCamera() {
        std::cout << "~Donut\n";
    };
};

extern "C" {
    DonutCamera* createCamera(void) {
        return new DonutCamera();
    }

    void destroyCamera(ICamera* camera) {
        delete camera;
    }
}