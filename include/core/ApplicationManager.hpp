#ifndef APPLICATIONMANAGER_HPP
#define APPLICATIONMANAGER_HPP

#include "libwrap/UI.hpp"
#include "logging/Logger.hpp"
#include "input/InputManager.hpp"
#include "file/FileManager.hpp"
namespace wrap
{
    using LogManager = loging::Logger;
};
namespace ApplicationManager
{
    using namespace wrap;

    class ApplicationManager{
        public:
            inputManager::InputManager input;
            LogManager logger;
            fileManager::FileManager file;
        private:
    };
};
#endif