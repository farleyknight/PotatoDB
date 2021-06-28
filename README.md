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

At the moment, we have to build to extra `conan` packages in order to properly build the main one.

Step 1) Build the `antlr4` package

```
$ cd antlr4
$ conan create .
$ cd ..
```

Step 2) Build the `murmurhash` package

```
$ cd murmurhash
$ conan create .
$ cd ..
```

Step 3) Build PotatoDB

```
$ conan source . 
... # This step downloads the ANTLR4 jar
$ conan install .
... # This step generates a new parser based on the g4 file. 
... # It also runs through some initial setup for the build step
$ conan build .
... # Actual compilation & linking
```

## `conan` profile

Make sure your `conan` profile is something like this:

```
$ conan profile show default
Configuration for profile default:

[settings]
os=Macos
os_build=Macos
arch=x86_64
arch_build=x86_64
compiler=apple-clang
compiler.version=12.0
compiler.libcxx=libc++
build_type=Release
[options]
[build_requires]
[env]
```

You might have to run this line

```
$ conan profile update settings.compiler.version=12.0 default
```
