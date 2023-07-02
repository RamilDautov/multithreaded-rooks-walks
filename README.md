# multithreaded-rooks-walks

## Build and Run
Simulation of several rooks making the moves on the chess board.

Use *'script-build.sh'* to build the project. You can also enable Thread Sanitizer by turning it on in the *'script-build.sh'*
```
... -DENABLE_THREAD_SANITIZER=ON
```

After building you can run the executable in *./build/bin* folder or just run *'run.sh'* from current directory.

## About
The program simulates several rooks making their moves in multithreaded regime.

The code uses strategy pattern, so new simulations can be easily added. 