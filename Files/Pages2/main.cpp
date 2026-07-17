#include "AppManager.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    AppManager::getInstance().run();
    return 0;
}
