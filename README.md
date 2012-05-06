"A state-of-the-art message-authentication code"

ABOUT
=====

See: [http://cr.yp.to/mac.html](http://cr.yp.to/mac.html) and [http://cr.yp.to/mac/poly1305-20050329.pdf](http://cr.yp.to/mac/poly1305-20050329.pdf)

These are portable, and in the case of the 64 bit & SSE2 versions, fairly performant, 
versions of poly1305.


BUILDING
========

`extern void poly1305_auth(unsigned char mac[16], const unsigned char *m, size_t len, const unsigned 
char key[32]);`

To link with each version

    poly1305-donna-c64-unrolled.c -Dpoly1305_auth=poly1305_donna_c64_unrolled_auth
    poly1305-donna-unrolled.c -Dpoly1305_auth=poly1305_donna_unrolled_auth
    poly1305-donna-x64-sse2.s -Dpoly1305_auth=poly1305_auth_x64_sse2
    poly1305-donna-x86-sse2.s -Dpoly1305_auth=poly1305_auth_x86_sse2

The .c source for the SSE2 versions is for inspection only. Compilers are not guaranteed to generate
decent code, so I included .s versions compiled with icc for the best performance.

USAGE
=====

See: [http://nacl.cace-project.eu/onetimeauth.html](http://nacl.cace-project.eu/onetimeauth.html), in specific, slightly plagiarized:

The poly1305_auth function, viewed as a function of the message for a uniform random key, is 
designed to meet the standard notion of unforgeability after a single message. After the sender 
authenticates one message, an attacker cannot find authenticators for any other messages.

The sender MUST NOT use poly1305_auth to authenticate more than one message under the same key.
Authenticators for two messages under the same key should be expected to reveal enough information 
to allow forgeries of authenticators on other messages. 


TESTING
=======

test-poly1305.c tests a specific poly1305 version for the specified repetitions. Run the output 
through "openssl md5" to create a fingerprint for the test which can be checked against known 
working versions. djb's poly1305-x86.s and poly1305-amd64.s are included to validate against.

test-driver.c (gcc only, requires openssl to be installed) automates testing of all available 
versions. The fingerprints for 2^0 to 2^24 trials are included in test-driver.c and are checked 
against automatically.


LICENSE
=======

[MIT](http://www.opensource.org/licenses/mit-license.php) or PUBLIC DOMAIN


NAMESAKE
========

I borrowed the idea for these from Adam Langley's [curve25519-donna](http://github.com/agl/curve25519-donna), hence
the name.