from conan import ConanFile
from conan.tools.cmake import CMakeToolchain

class MyProjectConan(ConanFile):
    name = "my_project"
    version = "1.0"

    # Dependencies
   # requires = "fmt/10.1.1"
    requires = "gtest/1.11.0" 

    # Settings
    settings = "os", "compiler", "build_type", "arch"

    # Generators for CMake integration
  #  tool_requires = "cmake/3.25"  # Ensures CMake integration
    generators = "CMakeToolchain"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
