# scribe

scribe is a lightweight, header-only C++ logging library that provides simple console logging with colored output and log levels. It's designed to be easy to integrate as a submodule or standalone library.

---

## Features

- Supports four log levels: `DEBUG`, `INFO`, `WARNING`, `ERROR`
- Colored console output for better readability
- Variadic logging (pass multiple arguments to log)
- Header-only and easy to include in any C++ project

## Usage

```cpp
#include "scribe.h"

int main() {
    const char *name = "Paul";
    int age = 25;

    Scribe::Info("Program started");
    Scribe::Debug("Debugging value:", name, age);
    Scribe::Warning("Low memory warning");
    Scribe::Error("Fatal error occurred");
    return 0;
}
```