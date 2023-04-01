class ICamera {
    public:
    virtual void init() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~ICamera() {};
};

