#include <cstdio>
#include <cstdint>

// Zählt die Anzahl der Einsen in der 32-bit Binärzahl val
int count_ones(uint32_t val);

// Zählt die Anzahl der führenden Nullen in der 32-bit Binärzahl val
int count_leading_zeros(uint32_t val);

// Returnt val mit invertierter Byte-Order LSB First <-> MSB First
uint32_t byte_swap(uint32_t val);

int main() {
  // Tests für count_ones
  printf("count_ones(0x00000000) = %d, expected 0\n", count_ones(0x00000000));
  printf("count_ones(0xffffffff) = %d, expected 32\n", count_ones(0xffffffff));
  printf("count_ones(0xabcdef12) = %d, expected 19\n", count_ones(0xabcdef12));
  
  // Tests für leading_zeros
  printf("count_leading_zeros(0x00000000) = %d, expected 32\n", count_leading_zeros(0x00000000));
  printf("count_leading_zeros(0x80000000) = %d, expected 0\n", count_leading_zeros(0x80000000));
  printf("count_leading_zeros(0x0c0fe0d1) = %d, expected 5\n", count_leading_zeros(0x050fe0d1));
  
  
  // Tests für byte_swap
  printf("byte_swap(0x11223344) = 0x%08x, expected 0x44332211\n", byte_swap(0x11223344));
  printf("byte_swap(0xabcdef12) = 0x%08x, expected 0x12efcdab\n", byte_swap(0xabcdef12));
  printf("byte_swap(0x1b2fa231) = 0x%08x, expected 0x31a22f1b\n", byte_swap(0x1b2fa231));
  
  return 0;
}