#include "tutorial.h"

tutorial::Car::Car(const std::string& name, int x, int y, int speed)
: m_name(name), m_x(x), m_y(y), m_speed(speed), m_type(1) { // default init for member attributes
  std::cout << "car created : " << m_name << std::endl;
}

void tutorial::Car::move() {
  m_x = m_x * m_speed;
  m_y = m_y * m_speed;
}

void tutorial::Car::display() const {
  std::cout << this->m_name << ": " << this->m_x << " " << this->m_y << " type:" << static_cast<int>(this->m_type) << std::endl;
}

void tutorial::Car::printAddress() const {
    std::cout << "Address of the current object: " << this << std::endl;
}


void tutorial::basicClass() {
   Car me{"mercedes", 10, 10, 10};

   Car* other = new Car("other", 1, 1, 1);

   other->move();
   me.move();
   me.display();
   other->display();
   me.printAddress();

   delete other;


   Logger myLogger{};
   Logger my2Logger{};
   my2Logger.setLogLevel(tutorial::Logger::Level::ERROR);
   myLogger.setLogLevel(tutorial::Logger::Level::INFO);
   my2Logger.debug("should output info and above");
   my2Logger.info("should output info and above");
   my2Logger.warn("should output info and above");
   my2Logger.error("should output info and above");
   myLogger.setLogLevel(tutorial::Logger::Level::ERROR);
   myLogger.debug("should output error");
   myLogger.info("should output error");
   myLogger.warn("should output error");
   myLogger.error("should output error");

}

tutorial::Logger::Level tutorial::Logger::logLevel = tutorial::Logger::Level::DEBUG;
const char* tutorial::Logger::LevelValue[5] = {"-", "DEBUG", "INFO", "WARN", "ERROR"};

tutorial::Logger::Logger() {
    std::cout << "init logger" << std::endl;
}

void tutorial::Logger::setLogLevel(Level value) {
    Logger::logLevel = value;
}
tutorial::Logger::Level tutorial::Logger::getLogLevel() const {
    return Logger::logLevel;
}
void tutorial::Logger::error(const char* message) const {
    if (this->getLogLevel() <= Logger::Level::ERROR) {
        this->print(Logger::Level::ERROR, message);
    }
}
void tutorial::Logger::warn(const char* message) const {
    if (this->getLogLevel() <= Logger::Level::WARN) {
        this->print(Logger::Level::WARN, message);
    }
}
void tutorial::Logger::info(const char* message) const {
    if (this->getLogLevel() <= Logger::Level::INFO) {
        this->print(Logger::Level::INFO, message);
    }
}
void tutorial::Logger::debug(const char* message) const {
    if (this->getLogLevel() <= Logger::Level::DEBUG) {
        this->print(Logger::Level::DEBUG, message);
    }
}
void tutorial::Logger::print(Level lvl, const char* message) const {
    char base[10];
    memset(&base, 0, 10);
    base[9] = 0;
    for (int i = 0; i < 8; i++) {
        if (i < strlen(this->LevelValue[lvl])) {
            base[i+1] = this->LevelValue[lvl][i];
        } else {
            base[i+1] = ' ';
        }
    }
    base[0] = '[';
    base[8] = ']';
    std::cout << base << " : " << message << std::endl;
}