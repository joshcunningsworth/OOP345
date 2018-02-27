OOP345/BTP305: sbt - Simple Build Tool
--------------------------------------
Last Updated: March 18, 2015

HOWTO use these build scripts
-----------------------------
Put your source files for the project into the src directory then run   
these build scripts as follows:                                         

On Linux (matrix) do the following:

    chmod u+x build
    ./build        (to build and run on matrix)
    ./build clean  (to delete executable and the bin directory)

On Windows do the following:

    (run VSVARS32.bat first) 
    build.bat         (to build and run on Windows)
    build.bat clean   (to delete executable and the bin directory)
  
Running build automatically tests the data files for the project, so
build will start with empty_object.json and then the other json files.  

Tips for Linux (matrix)
-----------------------

* To run a build on matrix use:

    chmod u+x && ./build 


* If you get an error or want to remove the executable on matrix use:

    ./build clean

 and run build again

    ./build

* In case you make a mistake, or get a compiler error, you should
  still be able to see where you made the errors as if you compiled
  from the command line directly. Alternatively, you can redirect
  errors into a file like this:

  ./build 2>err


* On matrix to get help with build tool:
  
    ./build help

  or any of
    ./build --help
    ./build -h
    ./build /?


Tips for Windows
----------------

* To run a build on Windows use:

    build 


* If you get an error or want to remove the executable on matrix use:

    build clean

 and run build again

    build

* In case you make a mistake, or get a compiler error, you should
  still be able to see where you made the errors as if you compiled
  from the command line directly. Alternatively, you can redirect
  errors into a file like this:

  build 2>&1 >err


* On Windows to get help with build tool:
  
    build help

  or any of
    build --help
    build -h
    build /?


# vim: tw=70:spell
