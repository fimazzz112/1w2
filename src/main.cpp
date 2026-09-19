#include <windows.h>

#include <fstream>
#include <iostream>
#include <string>

std::string ReadConfig()
{
    std::ifstream file("launcher.cfg");

    if (!file)
        return {};

    std::string command;
    std::getline(file, command);

    return command;
}

int main()
{
    SetConsoleTitleA("Fabric Launcher - Minecraft 1.21.4");

    std::cout << "Fabric Launcher\n";
    std::cout << "Minecraft 1.21.4 / Java 21\n\n";

    std::string command = ReadConfig();

    if (command.empty())
    {
        std::cerr
            << "launcher.cfg is missing or empty.\n\n"
            << "Put your legitimate Java/Fabric launch command into "
               "launcher.cfg.\n";

        system("pause");
        return 1;
    }

    std::cout << "Starting Minecraft...\n";

    // CreateProcess needs a writable command-line buffer.
    std::string commandLine = command;

    STARTUPINFOA startupInfo{};
    startupInfo.cb = sizeof(startupInfo);

    PROCESS_INFORMATION processInfo{};

    BOOL result = CreateProcessA(
        nullptr,
        commandLine.data(),
        nullptr,
        nullptr,
        FALSE,
        CREATE_NEW_CONSOLE,
        nullptr,
        nullptr,
        &startupInfo,
        &processInfo
    );

    if (!result)
    {
        DWORD error = GetLastError();

        std::cerr
            << "Failed to start Minecraft.\n"
            << "Windows error: " << error << "\n";

        system("pause");
        return 1;
    }

    std::cout
        << "Minecraft started successfully.\n"
        << "PID: " << processInfo.dwProcessId << "\n";

    CloseHandle(processInfo.hThread);
    CloseHandle(processInfo.hProcess);

    return 0;
}
