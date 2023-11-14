# THREADS
*Uma thread, em termos simples, é uma sequência de execução em um programa. É uma unidade básica de processamento que compartilha recursos, como memória, com outras threads dentro do mesmo processo. As threads permitem a execução concorrente de tarefas em um programa, facilitando a realização de operações simultâneas e melhorando a eficiência em sistemas multiprocessadores. Cada thread em um processo tem seu próprio conjunto de registradores e um ponteiro de instruções, mas compartilha o mesmo espaço de endereço e outros recursos com as demais threads do mesmo processo.*
## Data Races (Race Conditions) — What Are They?
Corridas de dados são um problema comum na programação multithread. As corridas de dados ocorrem quando múltiplas tarefas ou threads acessam um recurso compartilhado sem proteções suficientes, levando a um comportamento indefinido ou imprevisível.
- dois ou mais threads acessando simultaneamente um local de memória
- um deles é uma escrita
- um deles não está sincronizado
Em palavras mais simples, uma condição de corrida pode acontecer quando 2 ou mais threads estão tentando acessar e modificar a mesma variável ao mesmo tempo, isso pode levar a um erro no valor final da variável, não significa que isso acontecerá com certeza.

## MUTEX
- `pthread_mutex_t mutex;`: Declaração de uma variável `mutex` do tipo `pthread_mutex_t`, que será utilizada para criar um mutex.

- `pthread_mutex_lock(&mutex);`: Bloqueia o mutex, impedindo que outras threads entrem na seção crítica protegida por esse mutex até que seja desbloqueado.

- `pthread_mutex_unlock(&mutex);`: Desbloqueia o mutex, permitindo que outras threads possam entrar na seção crítica protegida por esse mutex.

- `pthread_create(&thread_id, NULL, &thread_function, &thread_argument);`: Cria uma nova thread, onde `thread_id` armazenará o identificador da nova thread, `thread_function` é a função que a thread executará e `thread_argument` são os argumentos que serão passados para essa função.

- `pthread_join(thread_id, NULL);`: Aguarda até que a thread com identificador `thread_id` termine sua execução. O segundo argumento (`NULL` no exemplo) é usado para recuperar o valor de retorno da thread, mas aqui não é utilizado.

- `pthread_mutex_destroy(&mutex);`: Destrói o mutex, liberando os recursos associados a ele. É importante chamar essa função quando o mutex não é mais necessário para evitar vazamentos de recursos.

- `pthread_detach` é uma função em pthread (biblioteca para programação de threads em C) que é usada para indicar que uma thread específica pode liberar automaticamente seus recursos quando ela terminar, sem a necessidade de outra thread chamar `pthread_join` para esperar por seu término.
  - `int pthread_detach(pthread_t thread);` -> `pthread_t thread`: O identificador da thread que se deseja desanexar.