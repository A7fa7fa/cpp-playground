#pragma once
#include <iostream>
#include <string.h>

namespace tutorial {
    #define log(message) std::cout << message << std::endl;
    void charArray();
    void stdString();
    // void log(const char* message);
    // void log(std::string message);
    void pointer();
    void reference();


    class Car {
        std::string m_name;
        int m_x, m_y;
        int m_speed;
        int m_type;

    public:
        Car(const std::string& name, int x, int y, int speed);

        void move();

        void display() const;

        void printAddress() const;

    };

    class Logger {
    public:
        enum Level {
            DEBUG = 1,
            INFO,
            WARN,
            ERROR
        };
        static Level logLevel;
        static const char* LevelValue[5];
    private:
        // static inline Level logLevel = Level::DEBUG;
        void print(Level lvl, const char* message) const;
    public:
        Logger();

        void setLogLevel(Level value);
        Level getLogLevel() const;
        void error(const char* message) const;
        void warn(const char* message) const;
        void info(const char* message) const;
        void debug(const char* message) const;

    };

    void basicClass();
}