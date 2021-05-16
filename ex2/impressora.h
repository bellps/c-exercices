typedef struct fila Fila;
typedef struct lista Lista;
typedef struct impressoraDoc ImpressoraDoc;

Fila * criar_fila();

void inserir(Fila * f, ImpressoraDoc * doc);

void remover(Fila * f);

int vazia(Fila * f);

void liberar(Fila * f);

void imprimir(Fila * f);