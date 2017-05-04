# AES-128

[![Build Status](https://travis-ci.org/openluopworld/aes_128.svg?branch=master)](https://travis-ci.org/openluopworld/aes_128) [![Coverity Scan Build Status](https://img.shields.io/coverity/scan/11502.svg)](https://scan.coverity.com/projects/openluopworld-aes_128)

C implementation of AES-128. This code has been tested with GCC 4.8.4 and Valgrind-3.11.0.

## Usage

### Interface

```C
/**
 * @purpose:            Key schedule for AES-128
 * @par[in]key:         16 bytes of master keys
 * @par[out]roundkeys:  176 bytes of round keys
 */
void aes_key_schedule_128(const uint8_t *key, uint8_t *roundkeys);

/**
 * @purpose:            Encryption. The length of plain and cipher should be one block (16 bytes).
 *                      The plaintext and ciphertext may point to the same memory
 * @par[in]roundkeys:   round keys
 * @par[in]plaintext:   plain text
 * @par[out]ciphertext: cipher text
 */
void aes_encrypt_128(const uint8_t *roundkeys, const uint8_t *plaintext, uint8_t *ciphertext);

/**
 * @purpose:            Decryption. The length of plain and cipher should be one block (16 bytes).
 *                      The ciphertext and plaintext may point to the same memory
 * @par[in]roundkeys:   round keys
 * @par[in]ciphertext:  cipher text
 * @par[out]plaintext:  plain text
 */
void aes_decrypt_128(const uint8_t *roundkeys, const uint8_t *ciphertext, uint8_t *plaintext);
```

### Compile
```sh
make
```

## Dependencies

+ The code is written in standard C
+ No dependencies of other libraries

## Contributing

If there is anything wrong or if you have any question, just make an issue or email me.

## Extension
The look-up-table implementation of AES is very fast. It can be seen in some famous projects.

## License

> Copyright (c) 2017 LuoPeng
> 
> Permission is hereby granted, free of charge, to any person obtaining a copy
> of this software and associated documentation files (the "Software"), to deal
> in the Software without restriction, including without limitation the rights
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
> copies of the Software, and to permit persons to whom the Software is
> furnished to do so, subject to the following conditions:
> 
> The above copyright notice and this permission notice shall be included in all
> copies or substantial portions of the Software.
> 
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
> SOFTWARE.
# CS591
