#include "cache.h"
#include "bits.h"

int get_set (Cache *cache, address_type address) {
  /* TODO:
     Extract the set bits from a 32-bit address.
   */

     unsigned int a = 0;
   address_type copy = address;
   int setb=cache->set_bits;
   int blockb=cache->block_bits;
   int L=blockb+setb-1;
   int R=blockb;
   

  //printf("%d\n",L );
   //printf("%d\n",R );


   copy=(unsigned)(copy<<(32-(L+1)))>>(32-(L-R+1));


          

    return copy;
}

int get_line (Cache *cache, address_type address) {
  /* TODO:
     Extract the tag bits from a 32-bit address.
   */
      address_type copy = address;
   int setb=cache->set_bits;
   int blockb=cache->block_bits;
     int L=31;
     int R=blockb+setb;

  return (unsigned)(copy<<(32-(L+1)))>>(32-(L-R+1));
}

int get_byte (Cache *cache, address_type address) {
  /* TODO
     Extract the block (byte index) bits from a 32-bit address.
   */
    address_type copy = address;
   int setb=cache->set_bits;
   int blockb=cache->block_bits;
     int L=blockb-1;
     int R=0;

     
  return (unsigned)(copy<<(32-(L+1)))>>(32-(L-R+1));
}
