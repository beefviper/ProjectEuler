#include "print.h"

ConditionalPrint print;

void ConditionalPrint::setEnabled(bool enabled) {
    enabled_ = enabled;
}

ConditionalPrint& ConditionalPrint::operator<<(std::ostream& (*manipulator)(std::ostream&)) {
    if (enabled_) {
        manipulator(std::cout);
    }

    return *this;
}

void setPrintEnabled(bool enabled) {
    print.setEnabled(enabled);
}