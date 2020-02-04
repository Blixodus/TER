#ifndef ABSTRACTSIMULATION_H
#define ABSTRACTSIMULATION_H

/* Abstract class to be inherited by population centred and entity centred simulations */
class AbstractSimulation {
 private:
  
 public:
  virtual void run(int t = 1);
}

#endif
