# PotatoDB

A personal project to learn database internals and writing performant C++ code.

## Build System

Currently using CMake to generate our build scripts. However, while traditionally CMake has been used alongside the command `make`, I've switched to using `ninja` instead. What does this mean for someone just using the project? Here's the commands you'll run.

To generate the build scripts:

```bash
$ cmake . -G Ninja
```

To actually compile:

```bash
$ ninja
```

To compile a specific target, say the test suite:

```bash
$ ninja tests
```


## Installation

At the moment PotatoDB has no easy-to-use installers. This is because it is still under heavy develompent. Instead, you'll be building it from scratch. 


... TODO! Explain how to properly use `conan` here..
