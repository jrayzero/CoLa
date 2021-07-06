# CoLa

Setup Codon (e.g. seq)

1. Get the submodule
```$ git submodule update --init```
2. Install dependencies
```$ cd seq```
```$ mkdir deps```
```$ cd deps```
```$ ../scripts/deps.sh N```, where N is the number of jobs to use
3. Set the following environment variables:
set ```SEQ_DEP``` to ```<PREFIX>/CoLa/seq/deps/deps```
set ```CODON_DEP``` to ```<PREFIX>/CoLa/seq/deps/deps```
set ```SEQ_PATH``` to ```<PREFIX>/CoLa/seq/stdlib```
set ```CODON_TOP``` to ```<PREFIX>/CoLa/seq```
set ```CODON_BUILD``` to ```<PREFIX>/CoLa/seq/build```
4. Build Codon
```$ cd <PREFIX>/CoLa/seq```
```$ mkdir build```
```$ cd build```
```$ cmake -DSEQ_DEP=$SEQ_DEP ..``` # Currently, seq's CMakeLists.txt does not accurately read SEQ_DEP as an env variable
```$ make```

Setup CoLa
1. Build CoLa
```$ cd <PREFIX>/CoLa```
```$ mkdir build```
```$ cd build```
```$ cmake ..```
```$ make```

Now you should have the ```colac``` executable in the build directory ```CoLa/build```

 
