#include "application.h"
#include "Config.h"
#include "Utility/ConfigLoader.h"

int main() {
    Config config(loadConfig("config.json"));

    Application app(config);
    app.start();

    return 0;
}