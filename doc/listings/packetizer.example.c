#include <liquid/liquid.h>
...
{
    // set up the options
    unsigned int n=16;                  // uncoded data length
    fec_scheme fec0 = FEC_HAMMING74;    // inner code
    fec_scheme fec1 = FEC_REP3;         // outer code

    // compute resulting packet length
    unsigned int k = packetizer_get_packet_length(n,fec0,fec1);

    // set up the arrays
    unsigned char msg[n];               // original message
    unsigned char packet[k];            // encoded message
    unsigned char msg_dec[n];           // decoded message
    int crc_pass;                       // decoder validity check

    // create the packetizer object
    packetizer p = packetizer_create(n,fec0,fec1);

    // initialize msg here
    unsigned int i;
    for (i=0; i<n; i++) msg[i] = i & 0xff;

    // encode the packet
    packetizer_encode(p,msg,packet);

    // decode the packet, returning validity
    crc_pass = packetizer_decode(p,packet,msg_dec);

    // destroy the packetizer object
    packetizer_destroy(p);
}
