typedef struct CST {
int size;
int quantity;
int next;
unsigned char* storage;
} CS_t;
void initialize(CS_t* s, int size);
void cleanup(CS_t* s);
int add(CS_t* s, const void* element);
void* fetch(CS_t* s, int index);
int count(CS_t* s);
void inflate(CS_t* s, int increase);
