# Redis C++ Client Test

This project demonstrates how to use Redis client libraries (hiredis and redis-plus-plus) to connect to a remote Redis server and perform various Redis operations.

## Project Structure

- `main.c` - Simple Redis connection test (hiredis C API)
- `redis_test.cpp` - Comprehensive Redis operations test (hiredis C++ API)
- `redispp_test.cpp` - Redis++ operations test (Modern C++ API)
- `CMakeLists.txt` - CMake build configuration
- `Hiredis_FAQ.md` - FAQ about hiredis usage

## Prerequisites

1. **vcpkg** - C++ package manager
2. **hiredis** - Install via vcpkg:
   ```bash
   vcpkg install hiredis:x64-windows
   ```
3. **redis-plus-plus** - Install via vcpkg:
   ```bash
   vcpkg install redis-plus-plus:x64-windows
   ```
4. **CMake** - For building the project
5. **Visual Studio** - For Windows compilation

## Build Instructions

1. **Configure the project:**
   ```bash
   mkdir build
   cd build
   cmake .. -DCMAKE_TOOLCHAIN_FILE="D:/Program/vcpkg/scripts/buildsystems/vcpkg.cmake"
   ```

2. **Build the project:**
   ```bash
   cmake --build . --config Release
   ```

## Usage

### Simple Connection Test (hiredis C API)
```bash
cd build/Release
./test_hiredis.exe
```

### Comprehensive Redis Operations Test (hiredis C++ API)
```bash
cd build/Release
./redis_test.exe
```

### Modern C++ Redis Operations Test (redis-plus-plus)
```bash
cd build/Release
./redispp_test.exe
```

## Features Demonstrated

### Basic Operations
- Connection to remote Redis server
- Authentication with password
- Simple SET/GET operations
- INCR operations

### Advanced Data Types
- **Hashes**: HSET, HGETALL operations
- **Lists**: LPUSH, LRANGE operations
- **Sets**: SADD, SMEMBERS operations
- **Sorted Sets**: ZADD, ZRANGE operations

### Advanced Features
- **Pub/Sub**: Publish/Subscribe operations
- **Transactions**: MULTI/EXEC operations
- **Pipelining**: Batch operations
- **Connection Pooling**: Redis++ connection pooling

### Error Handling
- Connection error handling
- Authentication error handling
- Command execution error handling
- Proper resource cleanup

## Configuration

The Redis connection parameters are hardcoded in the source files:
- Host: `121.43.98.198`
- Port: `6379`
- Password: `123456`

## Libraries Comparison

### hiredis
- **Pros**: Lightweight, official Redis C client, high performance
- **Cons**: C-style API, manual memory management, no object-oriented interface
- **Best for**: Performance-critical applications, embedded systems

### redis-plus-plus
- **Pros**: Modern C++ API, RAII, exception safety, connection pooling, easy to use
- **Cons**: Larger footprint, C++11 required
- **Best for**: Modern C++ applications, rapid development

## Dependencies

- **hiredis** - Minimalistic C client library for Redis
- **redis-plus-plus** - Modern C++ client library for Redis
- **CMake** - Build system
- **vcpkg** - Package management

## License

This project is for educational purposes and demonstrates Redis client usage patterns.
