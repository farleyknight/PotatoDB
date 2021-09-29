# PotatoDB

A personal project to learn database internals and writing performant C++ code.

## Required Build System Tools

I've been developing PotatoDB on MacBooks, so I'll describe how to build that way. I'm fairly certain these instructions could be translated to work on Linux, although Windows, is well.. Windows, as per usual. Anyways, I'm using the following build tools:

* conan
  * To install try `brew install conan`
* CMake
  * To install try `brew install cmake`
* Ninja
  * To install try `brew install ninja`

Once you've got `conan` installed, you can run the conan installation process.

## Installation

### Making the conan packages

At the moment PotatoDB has no easy-to-use installers. This project requires Java to be installed in order to complile the code. I've chained myself to Antlr4 and I will one day rid myself of this extra dependendency. But for now, it is a requirement. And the best way to manage that requirement, I've found, is a package manager called `conan`.

Therefore, to get a predictable build situation, you'll be making two custom `conan` packages and then actually building PotatoDB.

This is because it is still under heavy development. 

Instead, you'll be building it from scratch. 

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

## Build System

I've been developing PotatoDB on MacBooks, so I'll describe how to build that way. I'm fairly certain these instructions could be translated to work on Linux, although Windows, is well.. Windows, as per usual. Anyways, I'm using the following build tools:

* conan
  * To install try `brew install conan`
* CMake
  * To install try `brew install cmake`
* Ninja
  * To install try `brew install ninja`

Once you've got `conan` installed, you can run the conan installation process.

```bash
$ conan install .
```

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

