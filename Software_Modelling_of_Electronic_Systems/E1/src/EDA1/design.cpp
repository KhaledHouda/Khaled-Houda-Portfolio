#include <cstdint>

// Zählt die Anzahl der Einsen in der 32-bit Binärzahl val
int count_ones(uint32_t val) {
  int count = 0;
  for(int i = 0;i<32;i++){
    if((val & 1U<<i) ){
      count++;
    }
  }
	return count;
}



// Zählt die Anzahl der führenden Nullen in der 32-bit Binärzahl val
int count_leading_zeros(uint32_t val) {
  int count = 0;
  for(int i = 31; i>=0;i--){
    if(!(val & 1U<<i)){
      count++;
    }
    else{
      return count;
     }
  }
  return count;
}

// Returnt val mit invertierter Byte-Order LSB First <-> MSB First
uint32_t byte_swap(uint32_t val) {
  uint32_t result = 0x00000000;
  
  for(int byte=3 ; byte>=0;byte--){
 	uint32_t temp = (val) & (0x000000ff<< (8*byte) );
    temp = temp>>(8*byte);
    temp = temp<<(8*(3-byte));
    result += temp;
   
  }
	return result;
}
