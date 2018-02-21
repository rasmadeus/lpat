#ifndef COR_H
#define COR_H

namespace COR
{
    enum class Level
    {
        Debug,
        Info,
    };


    class Logger
    {
    public:
        Logger(Level level)
            : level{level}
        {
        }

        void setNext(Logger* logger)
        {
            next = logger;
        }

        void log(const std::string& msg, Level logLevel)
        {
            if (logLevel == level)
                post(msg);

            if (next)
                next->log(msg, logLevel);
        }

    protected:
        virtual void post(const std::string& msg) = 0;

    private:
        Level level;
        Logger* next = nullptr;
    };


    class ConsoleLogger : public Logger
    {
    public:
        ConsoleLogger(Level level)
            : Logger{level}
        {
        }

    protected:
        void post(const std::string& msg) override
        {
            std::cout << "Console logger: "  << msg << std::endl;
        }
    };


    void test()
    {
        ConsoleLogger debug{Level::Debug};
        ConsoleLogger info{Level::Info};

        debug.setNext(&info);
        debug.log("Debug level", Level::Debug);
        debug.log("Info level", Level::Info);
    }
}

#endif // COR_H
