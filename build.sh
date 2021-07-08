#!/bin/bash

cd antlr4
conan create .
cd ..

cd murmurhash
conan create .
cd ..
