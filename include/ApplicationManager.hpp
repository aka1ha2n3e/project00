#ifndef APPLICATIONMANAGER_HPP
#define APPLICATIONMANAGER_HPP

#include "UI.hpp"
#include "Logger.hpp"
#include "inputManager.hpp"
#include "FileManager.hpp"
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
        private:
    };
};
#endif