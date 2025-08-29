@echo off
echo ========================================
echo Redis Client Libraries Test Suite
echo ========================================

echo.
echo Building project...
cd build
cmake --build . --config Release
if %errorlevel% neq 0 (
    echo Build failed!
    exit /b 1
)
cd Release

echo.
echo ========================================
echo Testing hiredis C API (main.c)
echo ========================================
echo.
test_hiredis.exe
if %errorlevel% neq 0 (
    echo hiredis C API test failed!
) else (
    echo hiredis C API test completed successfully!
)

echo.
echo ========================================
echo Testing hiredis C++ API (redis_test.cpp)
echo ========================================
echo.
redis_test.exe
if %errorlevel% neq 0 (
    echo hiredis C++ API test failed!
) else (
    echo hiredis C++ API test completed successfully!
)

echo.
echo ========================================
echo Testing redis-plus-plus API (redispp_test.cpp)
echo ========================================
echo.
redispp_test.exe
if %errorlevel% neq 0 (
    echo redis-plus-plus API test failed!
) else (
    echo redis-plus-plus API test completed successfully!
)

echo.
echo ========================================
echo All tests completed!
echo ========================================

pause
