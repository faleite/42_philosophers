# Overview

**Philosophers with threads and mutexes**

## Visao ludica do projeto
*Aqui estão as coisas que você precisa saber se quiser ter sucesso nesta tarefa:*

- Um ou mais filósofos sentam-se em uma mesa redonda.\
  Há uma tigela grande de espaguete no meio da mesa.
- Os filósofos alternativamente **comem, pensam ou dormem.**\
  Enquanto comem, não pensam nem dormem;\
  enquanto pensam, não comem nem dormem;\
  e, claro, enquanto dormem, não comem nem pensam.
- Também há garfos na mesa. **Existem tantos garfos quanto filósofos.**
- Como servir e comer espaguete com apenas um garfo é muito inconveniente,\
  o filósofo pega os garfos direito e esquerdo para comer, um em cada mão.
- Quando um filósofo termina de comer, ele coloca os garfos de volta na mesa e\
comece a dormir. Uma vez acordados, eles começam a pensar novamente.\
A simulação para quando um filósofo morre de fome.
- Todo filósofo precisa comer e nunca deveria passar fome.
- Os filósofos não falam uns com os outros.
- Os filósofos não sabem se outro filósofo está prestes a morrer.
- Não há necessidade de dizer que os filósofos deveriam evitar morrer!

## Regras globais
*Você tem que escrever um programa para a parte obrigatória e outro para a\
parte bônus (se você decidir fazer a parte bônus). Ambos devem cumprir as\
seguintes regras:*

- Variáveis globais são proibidas!
- Seu(s) programa(s) deve(m) receber os seguintes argumentos:
  - **number_of_philosophers time_to_die time_to_eat time_to_sleep
    [number_of_times_each_philosopher_must_eat]**
- **número_de_filósofos:** O número de filósofos e também o número de garfos.
- **time_to_die** (em milissegundos): Se um filósofo não começasse a comer 
**time_to_die** milissegundos desde o início da última refeição ou o início\
da simulação, eles morrem.
- **time_to_eat** (em milissegundos): O tempo que um filósofo leva para comer.\
Durante esse tempo, eles precisarão segurar dois garfos.
- **time_to_sleep** (em milissegundos): O tempo que um filósofo passará dormindo.
- **number_of_times_each_philosopher_must_eat** (argumento opcional): Se todos\
filósofos comeram pelo menos **number_of_times_each_philosopher_must_eat** vezes,\
a simulação para. Se não for especificado, a simulação para quando um filósofo morre.
- Cada filósofo possui um número que varia de 1 a **number_of_philosophers.**
- O filósofo número 1 fica ao lado do filósofo **number_of_philosophers**.
Qualquer outro número filósofo **N** fica entre o número filósofo **N - 1**\
e o número filosófico **N + 1**.

## Sobre os logs do seu programa:
*Qualquer mudança de estado de um filósofo deve ser formatada da seguinte forma:*

- **timestamp_in_ms X has taken a fork**
- **timestamp_in_ms X is eating**
- **timestamp_in_ms X is sleeping**
- **timestamp_in_ms X is thinking**
- **timestamp_in_ms X died**

*Substitua **timestamp_in_ms** pelo carimbo de data/hora atual em milissegundos\
e **X** pelo número do filósofo.*

- Uma mensagem de estado exibida não deve ser confundida com outra mensagem.
- Uma mensagem anunciando a morte de um filósofo não deve ser exibida por mais\
de 10 ms após a morte real do filósofo.
- Novamente, os filósofos deveriam evitar morrer!

*Seu programa não deve ter nenhuma corrida de dados (**data races**).*

## Mandatorio
*As regras específicas da parte obrigatória são:*

- Cada filósofo deveria ser uma thread (fio).
- Há uma bifurcação entre cada par de filósofos. Portanto, se houver vários\
filósofos, cada filósofo tem um garfo no lado esquerdo e um garfo no lado\
direito. Se houvesse apenas um filósofo, deveria haver apenas um garfo na mesa.
- Para evitar que filósofos dupliquem forks, você deve proteger o estado dos\
forks com um mutex para cada um deles.