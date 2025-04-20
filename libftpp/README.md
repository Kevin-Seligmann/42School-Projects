# lifbftpp

This project consists of a 'library' for c++. 

Modern C++ is used.

A makefile is provided to compile into a 'libftpp.a' static library file.

A header file 'libftpp.hpp' with all the functionalities is provided.

The justification for each implementation comes from a provided description, a provided series of tests, and anything else that might be interesting to implement.

## Project status

Only the "Pool" utility is documented inside its header yet.

The "Other" part of the utilities is not yet done.

The "Network" part of the utilities is functional but incomplete, in particular regarding error handling.

## Library Utilities

### Data structures

- Pool, DataBuffer

### Design patterns 

- Memento, Observer, Singleton, StateMachine

### Threads

- Thread safe IOStream, ThreadSafeQueue, Thread, WorkerPool, PersistentWorker

### Network

- Message, Client, Server

### Math

- IVector2, IVector3, Random2DCoordinateGenerator, PerlinNoise2D

### Other

- Timer, Chronometer, ObservableValue, Application & Widget
