rem #! /bin/bash

cmake ..
cmake --build . --config Debug
cmake --install . --config Debug
