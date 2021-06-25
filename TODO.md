

# Removing `vcpkg`

* Delete `vcpkg.json`
* Delete `vcpkg-manifest-install.log`
* Remove GitHub action for `vcpkg`

# Setting up `conan`

* Add `conan` GitHub action.
* We now "own" `antlr4/conanfile.py`
  - Came from: https://github.com/Eric-Song-Nop/conan-antlr4
  - TODO: Give credit to above author.
  - TODO: Document that this package must be built locally to properly build PotatoDB.
* We need something similar for `murmurhash3`
  - There is already `libmurmurhash`
    - https://github.com/kloetzl/libmurmurhash
  - TODO: Convert it into a `conanfile.py` using the `Autotools` functionality in conan
    - https://docs.conan.io/en/1.36/reference/build_helpers/autotools.html
