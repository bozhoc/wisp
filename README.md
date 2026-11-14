# wisp
\> Write light.

A lightweight text editor written in C++ with Qt 6


## Features
- Open, edit and save files
- Open folders and browse their files in the side panel
- Auto-indent, bracket and quote auto-closing
- Zoom in and out (Ctrl +/-)

## Requirements
- Qt 6 (Widgets module)
- CMake 3.16 or newer
- C++17 compiler (GCC, Clang or MSVC)

On Debian and Ubuntu, the dependencies can be installed with:

```
sudo apt install qt6-base-dev cmake build-essential
```

## Build
```
git clone https://github.com/bozhoc/wisp.git
cd wisp
cmake -S . -B build
cmake --build build
```
Run it with:
```
./build/Wisp
```

## Platform support

| Platform | Status |
|----------|--------|
| Linux    | Tested |
| Windows  | Not yet tested |
| macOS    | Not yet tested |

##License
See [LICENSE](LICENSE)