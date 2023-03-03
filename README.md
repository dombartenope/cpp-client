# How To Use

- `brew install openssl`
- `brew install cpprestsdk`

### Add logic for API requests in the test.cpp folder
 
### Run with cmake in command line:
```
cmake -DCMAKE_CXX_FLAGS="-I/opt/homebrew/include -I/usr/local/include -I/usr/local/Cellar/include -I/usr/local/opt/include -I/usr/local/opt/openssl/include" \
-DCMAKE_MODULE_LINKER_FLAGS="-L/opt/homebrew/lib -L/usr/local/lib -L/usr/local/Cellar/lib -L/usr/local/opt/lib" \
-DCMAKE_EXE_LINKER_FLAGS="-L/opt/homebrew/lib -L/usr/local/lib -L/usr/local/Cellar/lib -L/usr/local/opt/lib -L/usr/local/opt/openssl/lib" \
-DOPENSSL_ROOT_DIR=/usr/local/opt/openssl \
-DOPENSSL_LIBRARIES=/usr/local/opt/openssl/lib \
.

make
```
### Once compiled successfully, run with `./tests`