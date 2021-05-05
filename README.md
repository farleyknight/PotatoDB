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

First install `vcpkg`. That boils down to cloning it locally from GitHub and running the bootstrap script. Check out the instructions here:

https://docs.microsoft.com/en-us/cpp/build/install-vcpkg?view=msvc-160&tabs=macos#to-copy-and-set-up-vcpkg-on-macos
It basically boils down to these steps:

```bash
$ git clone https://github.com/microsoft/vcpkg
$ cd vcpkg
# ./bootstrap-vcpkg.sh
$ export $VCPKG_ROOT=`pwd`
```

In the CMake scripts, we verify the `VCPKG_ROOT` environment variable gives the root location of your `vcpkg` installation. So double check:

```bash
$ echo $VCPKG_ROOT
/home/farleyknight/code/vcpkg # I typically keep it installed here
```

The `VCPKG_FEATURE_FLAGS` environment variable gives us the ability to use "manifest mode", which means that `vcpkg` can look at the local file `vcpkg.json` and install the necessary dependencies.

```bash
$ echo $VCPKG_FEATURE_FLAG
manifests
```

## Package management

I have tried my best to use the same best practices in this project as there are with other mainsteam languages. In that case, I've decided to adopt [`vcpkg`](https://github.com/microsoft/vcpkg).

Towards that end, there is a section in my `CMakeLists.txt` dedicated to those dependencies. They are management by hand at the moment.

### Using git module

I can't remember where I read this, but I do recall seeing a piece of advice: In order to get `vcpkg` working with GitHub actions (to show badges), we may have to make it a git submodule. Will research this further at some point...
