# PotatoDB

A personal project to learn database internals and writing performant C++ code.

## Installation

At the moment PotatoDB has no easy-to-use installers. This is because it is still under heavy develompent. Instead, you'll be building it from scratch. 

First install `vcpkg`:

```bash
$ brew install vcpkg
```

Next, make sure you have the ncessary environment variables. 

The `VCPKG_ROOT` environment variable gives the root location of your `vcpkg` installation.
```bash
$ echo $VCPKG_ROOT
<Your vcpkg root here, probably somewhere under your home directory>
```

The `VCPKG_FEATURE_FLAGS` environment variable gives us the ability to use "manifest mode", which means that `vcpkg` can look at the local file `vcpkg.json` and install the necessary dependencies.

```bash
$ echo $VCPKG_FEATURE_FLAGS
manifests
```

## Package management

I have tried my best to use the same best practices in this project as there are with other mainsteam languages. In that case, I've decided to adopt [`vcpkg`](https://github.com/microsoft/vcpkg).

Towards that end, there is a section in my `CMakeLists.txt` dedicated to those dependencies. They are management by hand at the moment.

