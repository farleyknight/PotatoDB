from conans import ConanFile, AutoToolsBuildEnvironment, tools
import shutil
import os

class MurmurHashConan(ConanFile):
    name = "libmurmurhash"
    version = "1.5.0"
    license = "Public Domain"
    author = "Farley Knight <farleyknight@gmail.com>"
    url = "https://github.com/farleyknight/PotatoDB/master/murmurhash"
    description = "MurmurHash3 library"
    settings = "os", "compiler", "build_type", "arch"
    _source_subfolder = "libmurmurhash"

    def source(self):
        self.run("git clone https://github.com/kloetzl/libmurmurhash.git")

    def build(self):
        with tools.chdir(self._source_subfolder):
            self.run("autoreconf -fi")
            autotools = AutoToolsBuildEnvironment(self)
            autotools.configure()
            autotools.make()
            return autotools

    def package(self):
        include_source_path = os.path.join(self._source_subfolder)
        self.copy("*.h",
                  dst="include",
                  src=include_source_path)

        libs_source_path = os.path.join(self._source_subfolder, ".libs")
        self.copy("*.a",
                  dst="lib",
                  src=libs_source_path,
                  keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
