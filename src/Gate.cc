#define _GLIBCXX_USE_NANOSLEEP

#include <algorithm>
#include <thread>
#include <iostream>
#include <tgmath.h>
#include <fstream>
#include <iomanip>
#include <wiringPi.h>

#include "Gate.h"
#include "Utils.h"
#include "erostamas/Logging.h"
#include "StringCommandAdapter.h"
#include "erostamas/UdpMessageReceiver.h"

Gate::Gate() {
    std::unique_ptr<StringCommandAdapter> adapter(new StringCommandAdapter());
    LOG_INFO << "ok 1" << std::endl;
    std::unique_ptr<UdpMessageReceiver> receiver(new UdpMessageReceiver(50001));
    LOG_INFO << "ok 2" << std::endl;
    adapter->registerMessageReceiver(std::move(receiver));
    LOG_INFO << "ok 3" << std::endl;
    _commandProcessor.registerCommandAdapter(std::move(adapter));
    LOG_INFO << "ok 4" << std::endl;
    _commandProcessor.processCommands();
}

Gate::~Gate() {
}

void Gate::run() {
    wiringPiSetup();
    pinMode (25, OUTPUT);

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        _commandProcessor.processCommands();
    }
    LOG_DEBUG << "Stopping gate" << std::endl;
}
