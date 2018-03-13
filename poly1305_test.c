#include <stdio.h>
#include "poly1305-donna.h"

int main ()
{

	unsigned char key[32] = {0x85,0xd6,0xbe,0x78,0x57,0x55,0x6d,0x33,
							 0x7f,0x44,0x52,0xfe,0x42,0xd5,0x06,0xa8,
							 0x01,0x03,0x80,0x8a,0xfb,0x0d,0xb2,0xfd,
							 0x4a,0xbf,0xf6,0xaf,0x41,0x49,0xf5,0x1b};

	unsigned char mac[16] ={0};
	
	unsigned char *message = "Cryptographic Forum Research Group";
	int message_len = 34;
	int i =0;
	printf("Poly1305 Test Vector\r\n");
	printf("Key = ");
	for (i = 0; i< 32;i++)
		printf("%02x",key[i]);
	printf("\r\n");

	printf("Message = '%s'\r\n",message);
	
	poly1305_auth(mac, message, message_len, key);
	printf("MAC = ");
	for (i = 0; i< 16;i++)
		printf("%02x",mac[i]);
	printf("\r\n");

	return 0;
}
