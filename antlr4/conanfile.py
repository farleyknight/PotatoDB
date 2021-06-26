from conans import ConanFile, CMake, tools
import shutil
import os

class Antlr4Conan(ConanFile):
    name = "antlr4"
    version = "4.9.2"
    zip_sha256 = "838a2c804573f927c044e5f45a8feb297683a7047ab62dfac8ddc995498db11c"
    jar_sha256 = "bb117b1476691dc2915a318efd36f8957c0ad93447fb1dac01107eb15fe137cd"
    license = "The BSD License"
    author = "Eric Song <Eric_YF_Song@outlook.com>"
    url = "https://github.com/Eric-Song-Nop/conan-antlr4"
    description = "C++ runtime support for ANTLR"
    settings = "os", "compiler", "build_type", "arch"
    _source_subfolder = "source"

    def source(self):
        source_url = "https://www.antlr.org/download/antlr4-cpp-runtime-{}-source.zip".format(self.version)
        tools.get(source_url, sha256=self.zip_sha256, destination=self._source_subfolder)
        source_url2 = "https://www.antlr.org/download/antlr-{}-complete.jar".format(self.version)
        antlr_file_name = "antlr.jar"
        tools.download(source_url2, antlr_file_name)
        tools.check_sha256(antlr_file_name, self.jar_sha256)
        shutil.move(antlr_file_name, self._source_subfolder)

    def _configure_cmake(self):
        # cmake = CMake(self, "Ninja")
        cmake = CMake(self, "Unix Makefiles") # TODO: Figure out why we can't use Ninja!
        cmake.definitions['CMAKE_CXX_STANDARD'] = 17
        cmake.definitions['CMAKE_CXX_STANDARD_REQUIRED'] = 'Required'
        cmake.definitions['BUILD_SHARED_LIBS'] = 'OFF'
        cmake.configure(source_folder=self._source_subfolder)
        return cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build(target='antlr4_static')

    def package(self):
        self.copy("*.h",   dst="include", src=os.path.join(self._source_subfolder, "runtime", "src"))
        self.copy("*-runtime.a", dst="lib", keep_path=False)
        self.copy(pattern="conan_run.log", dst="", keep_path=False)
        self.copy("*.jar", dst="bin", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
