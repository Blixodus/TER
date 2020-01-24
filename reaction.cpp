#include "reaction.h"

Reaction::Reaction(const unsigned int ar1, const unsigned int ar2, const unsigned int ap1,
          const unsigned int ap2, const unsigned int reac_id, const float pr):r1(ar1), r2(ar2), 
          p1(ap1), p2(ap2), react_id(reac_id), prob(pr){}
          
          
//Imaginaire d'Atte ... <3
bool Reaction::react(){}