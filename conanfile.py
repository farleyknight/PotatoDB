from conans import ConanFile, CMake, tools

class PotatoDBConan(ConanFile):
    settings = {
        "os": None,
        "compiler": ['clang', 'apple-clang'],
        "build_type": None,
        "arch": None
        # "cppstd": 'gnu20'
    }

    requires = "antlr4/4.9.2", "asio/1.18.1", "benchmark/1.5.2", "fmt/7.1.3", "gtest/1.10.0", "ms-gsl/3.1.0", "spdlog/1.8.5", "libmurmurhash/1.5.0"
    generators = "cmake"
    antlr4_version = "4.9.2"
    jar_sha256 = "bb117b1476691dc2915a318efd36f8957c0ad93447fb1dac01107eb15fe137cd"

    def source(self):
        source_url = "https://www.antlr.org/download/antlr-{}-complete.jar".format(self.antlr4_version)
        antlr_file_name = "antlr.jar"
        tools.download(source_url, antlr_file_name)
        tools.check_sha256(antlr_file_name, self.jar_sha256)

    def _make_parser(self):
        # TODO: How do I find the jar file that is downloaded in the antlr4 conanfile.py?
        self.run("java -jar ./antlr4/source/antlr.jar -Dlanguage=Cpp -visitor parser/PotatoSQL.g4")

    def build(self):
        self._make_parser()
        self.run("cmake . -G Ninja")
        cmake = CMake(self)
        cmake.build()



