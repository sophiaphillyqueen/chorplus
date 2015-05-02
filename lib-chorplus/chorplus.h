
#ifndef L__CHORPLUS__H
#define L__CHORPLUS__H

#include <iostream>

namespace chorplus {
  
  // The 'strpo' class is an abstract base class for any entity that you
  // can put strings in and out of. Queues, stacks, hats, and any other
  // specific version are implemented by specific supercalsses.
  class strpo {
    public:
      bool cmlinargs ( void );
      std::string fitm ( int rg_a );
      
      virtual std::string fitm ( void ) =0;
      virtual bool left ( void ) =0;
      virtual bool insert ( void ) =0;
      virtual ~strpo ( void ) = 0;
  };
  
  class strpo_queue: public strpo {
    public:
      std::string fitm ( void );
      bool left ( void );
      bool insert ( void );
      strpo_queue ( void );
      ~strpo_queue ( void );
  };
  
  // The 'preferan' class is a for objects that contain preference
  // variables such as dirvars.
  class preferan {
    public:
      preferan ( void );
      
      // This next method begins writing to a preference variable.
      // If such a variable already exists, the old one is deleted.
      bool to ( std::string rg_a );
      
      // This next version of the same method is when you want to
      // begin the new preference variable with the contents of a
      // pre-existing preference variable.
      bool to ( std::string rg_a, std::string rg_b );
      
      // To protect a preference variable from tampering
      bool prtc ( std::string rg_a );
      
      // To add text to the current variable
      bool txa ( std::string rg_a );
      
      // To read preference variables from a file
      bool readpref ( std::string rg_a );
      
      // To obtain the evaluated string-value of a preference variable
      std::string evl ( std::string rg_a );
      
      // Produce a fatal error (with explanation) if a specific preference
      // variable is absent:
      // Arg 1 is the var-name ---- arg 2 the explanation
      void dmnd ( std::string rg_a, std::string rg_b );
  };
  
  
  // The following function is for registering the command line.
  void cmline ( int rg_a, char **rg_b, char **rg_c );
}

#endif

