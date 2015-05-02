
#include "maininclude.h"

int main ( int argc, char **argv, char **env )
{
  chorplus::strpo *lc_argon;
  chorplus::preferan *lc_confo;
  
  // First things first --- we register the command line.
  chorplus::cmline(argc,argv,env);
  
  // Now we set up the envari defaults.
  // I try (as much as possible) to follow the GNU defaults:
  // https://www.gnu.org/prep/standards/html_node/Directory-Variables.html
  lc_confo = new chorplus::preferan;
  lc_confo->to("srcdir");
  if ( argc >= 2 )
  {
    lc_confo->txa(argv[1]);
  } else {
    lc_confo->txa(".");
  }
  lc_confo->to("prefix");
  lc_confo->txa("/usr/local");
  lc_confo->to("exec_prefix","prefix");
  lc_confo->to("bindir","exec_prefix");
  lc_confo->txa("/bin");
  lc_confo->to("sbindir","exec_prefix");
  lc_confo->txa("/sbin");
  lc_confo->to("libexecdir","exec_prefix");
  lc_confo->txa("/libexec");
  lc_confo->to("datarootdir","prefix");
  lc_confo->txa("/share");
  lc_confo->to("datadir","datarootdir");
  lc_confo->to("sysconfdir","prefix");
  lc_confo->txa("/etc");
  lc_confo->to("sharedstatedir","prefix");
  lc_confo->txa("/com");
  lc_confo->to("localstatedir","prefix");
  lc_confo->txa("/var");
  lc_confo->to("runstatedir","localstatedir");
  lc_confo->txa("/run");
  lc_confo->to("includedir","prefix");
  lc_confo->txa("/include");
  lc_confo->to("oldincludedir");
  lc_confo->txa("/usr/include");
  
  lc_confo->prtc("srcdir"); // Protect $(srcdir) from tampering.
  lc_confo->readpref(lc_confo->evl("srcdir") + "/proj-pref.txt");
  
  lc_confo->dmnd("project_name","The name of this project.");
  lc_confo->dmnd("project_version","The version-ID of this project.");
  lc_confo->prtc("project_name");
  lc_confo->prtc("project_version");
  
  // More dir-vars are to follow ---
  // but for now, these are the basics.
  // They should carry us until the most
  // rudimentary version of this program
  // is working.
  
  
  
  // Now we process the command-line.
  lc_argon = new chorplus::strpo_queue;
  lc_argon->cmlinargs(); // Add the command-line arguments.
  
  // Remove the first two items from the queue - as they are special.
  lc_argon->fitm(2);
  while ( lc_argon->left() )
  {
    std::string lc02_stvar;
    lc02_stvar = lc_argon->fitm();
    proc_an_arg(lc_argon,lc02_stvar,lc_confo);
  }
  delete lc_argon;
  
  
  // Free the resource.
  delete lc_confo;
}



