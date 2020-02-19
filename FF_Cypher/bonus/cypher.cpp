#include "cypher.h"

Cypher::Cypher() { } // Reserved
int Cypher::chars = 0;
void Cypher::chars_encrypted(int num) {chars += num;}
int Cypher::chars_encrypted() {return chars;}

