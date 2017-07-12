# C Data Structures
A collection of simple data structures implemented in C
## Data Structures
- [ ] Linked List
- [ ] Queue
- [ ] Stack
- [ ] Heap
- [ ] Priority Queue
- [ ] Set
- [ ] Associative Array
## Building
#### Windows
Execute `gradlew build` in the project root

*Currently, the Gradle model for Platform does not allow us to differentiate between different
c-runtime, ABI or other binary variants. This means that it is not possible to differentiate
between a prebuilt library binary compatible with VS2010 vs VS2013.*

*As such, this sample will only work on Windows after setting the 'WinCUnit' to match your toolchain
Valid values for WinCUnit: [cygwin, mingw, vs2010, vs2013, vs2015]*
#### \*nix
Execute `./gradlew build` in the proect root
