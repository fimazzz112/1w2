# FabricLauncher

Small Windows EXE wrapper for launching an existing, legitimately installed
Minecraft Fabric 1.21.4 instance with Java 21.

## Important

This project does NOT implement Microsoft authentication, token handling,
DRM bypassing, or anti-cheat bypassing.

The `launcher.cfg` file contains the launch command produced by your normal
Minecraft/Fabric launcher.

## Build

Install Visual Studio 2022 with "Desktop development with C++" and CMake.

```powershell
cmake -S . -B build
cmake --build build --config Release
```

The executable will be:

`build/Release/FabricLauncher.exe`

## Configure

Edit `launcher.cfg` and put the legitimate Java 21 launch command on one line.
