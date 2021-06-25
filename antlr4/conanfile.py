from conans import ConanFile, CMake, tools
import shutil
import os

class Antlr4Conan(ConanFile):
    name = "antlr4"
    version = "4.9.1"
    license = "The BSD License"
    author = "Eric Song <Eric_YF_Song@outlook.com>"
    url = "https://github.com/Eric-Song-Nop/conan-antlr4"
    description = "C++ runtime support for ANTLR"
    settings = "os", "compiler", "build_type", "arch"
    _source_subfolder = "source"

    def source(self):
        source_url = "https://www.antlr.org/download/antlr4-cpp-runtime-{}-source.zip".format(self.version)
        tools.get(source_url, sha256="21647f9d5c55d13f2297e3f61e5dd68283e439983c27bd899f9c8a725bbea7b5", destination=self._source_subfolder)
        source_url2 = "https://www.antlr.org/download/antlr-{}-complete.jar".format(self.version)
        antlr_file_name = "antlr.jar"
        tools.download(source_url2, antlr_file_name)
        tools.check_sha256(antlr_file_name, "1f645aea79b98e6ff7ec8f6bf7ea82b58cfc60a194cda2a3b1e753589d41f98d")
        shutil.move(antlr_file_name, self._source_subfolder)

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.definitions["WITH_LIBCXX"]="OFF"
        cmake.configure(source_folder=self._source_subfolder)
        return cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build(target='antlr4_static')

    def package(self):
        self.copy("*.h", dst="include", src=os.path.join(self._source_subfolder, "runtime", "src"))
        self.copy("*.a", dst="lib", keep_path=False)
        self.copy("*.jar", dst="bin", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
