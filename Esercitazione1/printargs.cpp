#include <iostream> //file header

// quando lanciato programma spesso utile passare parametri -> modificano esecuzione (es. -l quando usiamo ls)
int main(int argc, const char *argv[]) //passiamo parametri a funzione main tramite terminale, tradizionalmente chiamati argc, argv
{
std::cout << "Numero di parametri: " << argc << "\n";
for (int i = 0; i < argc; i++) {
std::cout << "Parametro " << i << " = " << argv[i] << "\n";
  }
return 0;
}

// g++ -o print_args printargs.cpp -> per compilare da terminale
// ./printargs testo.txt -> per eserguire da terminale
// oss: per convenzione nome programma stesso è sempre parametro (parametro 0)
