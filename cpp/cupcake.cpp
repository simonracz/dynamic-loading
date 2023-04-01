#include <icamera.h>
#include <iostream>

class CupcakeCamera : ICamera {
    public:
    CupcakeCamera() {
        std::cout << "Cupcake()\n";
    }
    void init() {
        std::cout << "Cupcake Init\n";
    };
    void start() {
        std::cout << "Cupcake Start\n";
    };
    void stop() {
        std::cout << "Cupcake Stop\n";
    };
    ~CupcakeCamera() {
        std::cout << "~Cupcake\n";
    };
};

extern "C" {
    CupcakeCamera* createCamera(void) {
        return new CupcakeCamera();
    }

    void destroyCamera(ICamera* camera) {
        delete camera;
    }
}
