/*
 *
 * Chinese Academy of Sciences
 * State Key Laboratory of Information Security
 * Institute of Information Engineering
 *
 * Copyright (C) 2016 Chinese Academy of Sciences
 *
 * LuoPeng, luopeng@iie.ac.cn
 * Updated in May 2016
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "aes.h"
#include <sys/time.h>

int main(int argc, char *argv[]) {
	int r0, r1, r2;
	uint8_t i, j, k, hold, index, dummy;
	uint8_t BLOCKS = 8;

	srand(time(NULL));

	/* 128 bit key */
	uint8_t key[] = {
		//0x0f, 0x15, 0x71, 0xc9, 0x47, 0xd9, 0xe8, 0x59, 
		//0x0c, 0xb7, 0xad, 0xd6, 0xaf, 0x7f, 0x67, 0x98,
		0xc2, 0x86, 0x69, 0x6d, 0x88, 0x7c, 0x9a, 0xa0,
		0x61, 0x1b, 0xbb, 0x3e, 0x20, 0x25, 0xa4, 0x5a, 
	};

	uint8_t IV[] = {
		//0x0f, 0x15, 0x71, 0xc9, 0x47, 0xd9, 0xe8, 0x59, 
		//0x0c, 0xb7, 0xad, 0xd6, 0xaf, 0x7f, 0x67, 0x98,
		0x56, 0x2e, 0x17, 0x99, 0x6d, 0x09, 0x3d, 0x28,
		0xdd, 0xb3, 0xba, 0x69, 0x5a, 0x2e, 0x6f, 0x58, 
	};

//"Two block messages are the best."
// 54776f20626c6f636b206d65737361676573206172652074686520626573742e
	
	/*uint8_t plaintext[] = {
		0x54, 0x77, 0x6f, 0x20, 0x62, 0x6c, 0x6f, 0x63,
		0x6b, 0x20, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67,
		0x65, 0x73, 0x20, 0x61, 0x72, 0x65, 0x20, 0x74,
		0x68, 0x65, 0x20, 0x62, 0x65, 0x73, 0x74, 0x2e,
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
	};
	*/
	//Coming up with an eight block message can be hard to do, because it is quite a long sentence to make up out of thin air.padding
	//43 6f 6d 69 6e 67 20 75 70 20 77 69 74 68 20 61 6e 20 65 69 67 68 74 20 
	//62 6c 6f 63 6b 20 6d 65 73 73 61 67 65 20 63 61 6e 20 62 65 20 68 61 72
	//64 20 74 6f 20 64 6f 2c 20 62 65 63 61 75 73 65 20 69 74 20 69 73 20 71 
	//75 69 74 65 20 61 20 6c 6f 6e 67 20 73 65 6e 74 65 6e 63 65 20 74 6f 20 
	//6d 61 6b 65 20 75 70 20 6f 75 74 20 6f 66 20 74 68 69 6e 20 61 69 72 2e 
	//70 61 64 64 69 6e 67	
		uint8_t plaintext[] = {
		0x43, 0x6f, 0x6d, 0x69, 0x6e, 0x67, 0x20, 0x75,
		0x70, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61,
		0x6e, 0x20, 0x65, 0x69, 0x67, 0x68, 0x74, 0x20,
		0x62, 0x6c, 0x6f, 0x63, 0x6b, 0x20, 0x6d, 0x65,
		0x73, 0x73, 0x61, 0x67, 0x65, 0x20, 0x63, 0x61,
		0x6e, 0x20, 0x62, 0x65, 0x20, 0x68, 0x61, 0x72,
		0x64, 0x20, 0x74, 0x6f, 0x20, 0x64, 0x6f, 0x2c, 
		0x20, 0x62, 0x65, 0x63, 0x61, 0x75, 0x73, 0x65,
		0x20, 0x69, 0x74, 0x20, 0x69, 0x73, 0x20, 0x71,
		0x75, 0x69, 0x74, 0x65, 0x20, 0x61, 0x20, 0x6c,
		0x6f, 0x6e, 0x67, 0x20, 0x73, 0x65, 0x6e, 0x74,
		0x65, 0x6e, 0x63, 0x65, 0x20, 0x74, 0x6f, 0x20,
		0x6d, 0x61, 0x6b, 0x65, 0x20, 0x75, 0x70, 0x20,
		0x6f, 0x75, 0x74, 0x20, 0x6f, 0x66, 0x20, 0x74,
		0x68, 0x69, 0x6e, 0x20, 0x61, 0x69, 0x72, 0x2e,
		0x70, 0x61, 0x64, 0x64, 0x69, 0x6e, 0x67, 0x01, 
	}; 
	uint8_t ciphertext[AES_BLOCK_SIZE*8];

	/*const uint8_t const_cipher[AES_BLOCK_SIZE] = {
		//0xff, 0x0b, 0x84, 0x4a, 0x08, 0x53, 0xbf, 0x7c,
		//0x69, 0x34, 0xab, 0x43, 0x64, 0x14, 0x8f, 0xb9,
		0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30,
		0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a,
	};
	*/
	uint8_t roundkeys[AES_ROUND_KEY_SIZE];

	// key schedule
	aes_key_schedule_128(key, roundkeys);

	//Cache warming code
	/*
	for(i = 0; i < 128; i++) {
		dummy = plaintext[i];
	}
	*/

clock_t begin = clock();
	for (j = 0; j < BLOCKS; j++) {

		for(k = 0; k < AES_BLOCK_SIZE; k++) {
			plaintext[k] = plaintext[(j*16)+k] ^ IV[(k)];
		}

		aes_encrypt_128(roundkeys, plaintext, ciphertext);

		for (i = 0; i < AES_BLOCK_SIZE; i++) {
			IV[i] = ciphertext[(j*16)+i];
		}
		
		//Random number timing code
		//Implimented
		/*
		r0 = rand()%10;
		for(index = 0; index < r0; index++) {
			r1 = rand();
			r2 = rand();
			hold = r1 + r2;
		} */

		//Random misses code
		//Call random part of ciphertext to generate cache misses
		/*r0 = rand()%128
		for(i=0; i < r0; i++) {
			dummy = ciphertext[i]
		}
		*/
	}
clock_t end = clock();
double time_spent = (double)(end-begin)/ CLOCKS_PER_SEC;

printf("%f\n", time_spent);



}	
