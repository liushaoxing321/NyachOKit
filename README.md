# UniversalFumenConverter
[![Build Status](https://travis-ci.com/Naville/UniversalFumenConverter.svg?token=FmAj58r5oom4hKe1aoaY&branch=master)](https://travis-ci.com/Naville/UniversalFumenConverter)

##Clone

```
git clone --recursive
```

*OR YOU WILL BE IN SERIOUS TROUBLE*

##Build

###UNIX-Like Systems:

First make sure you have clang and cmake installed.
Then
```
mkdir Build&& cd Build && cmake -G "Unix Makefiles" /PATH/TO/SRC/ROOT/ && make

```

###Windows:
1.	Install cmake from cmake.org
2.	Make sure cmake.exe and cl.exe is available in $PATH
3.      In VisualStudio Developer Console:

```
mkdir Build&& cd Build && cmake -G "Visual Studio 15" /PATH/TO/SRC/ROOT/
```

open the .sln in Build/ and build

Note: Edit "Visual Studio 15 accordingly if you are not using VS2015


