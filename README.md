# Mini Sistema Bancário
### Introdução
Neste projeto de trabalho, o/a aluno(a) deverá implementar um pequeno sistema bancário com menu de console.

### Motivação
No currículo 1998, esta disciplina é nomeada "Linguagens Comerciais de Programação". Antes de 1998, alunos costumeiramente aprendiam a "Linguagem Comum Orientada para os Negócios" (COBOL) e muitos dos exemplos eram focados em sistemas bancários.

### Justificativa
A vantagem de implementar um sistema bancário é sua importância intrínseca de auditoria contábil, que ensina os alunos a escrever testes de forma natural.

### Projeto e Requisitos
Implemente um sistema bancário simplista. Neste sistema, devem ser gerenciados os seguintes conceitos:

**Conceitos:**
1. Banco (só uma agência com vários clientes)
2. Cliente (do banco, pode ter várias contas)
3. Conta (de um cliente)
4. Transferência (entre duas contas)

### Caso de uso:
O/a operador(a) do sistema (não precisa ser identificado(a)) usa menus de texto.
Nestes menus, ele(a) pode selecionar a operação:
1. Lista clientes;
2. Lista contas;
3. Saldo do cliente;
4. Extrato do cliente;
5. Realizar transferência;
6. Mostrar valores totais de todas as contas.
As contas começam já com valores padrão, exemplo, 1000 reais para cada cliente.
O banco não recebe valores de fora, nem envia valores para fora. Depois de criar todas as contas no construtor, calcule o somatório total dos saldos. Este total deve ser constante. Ou seja, todas as transferências devem ser testadas com o total de todas as contas, antes e depois e verificar se o balanço é mantido.

Lance tipos específicos de exceções, como por exemplo, ao detectar número de contas inválido e falta de saldo para transferências. Use o tratamento de exceções para exibir mensagens ao operador.

Escreva destrutores e garanta que todos os ponteiros alocados com "new" sejam desalocados com "delete" ao término do programa.

Linguagem: C++ 2003.
## Dicas Gerais:
### Não:
- Não tente impressionar o professor com interface de texto complexa, o foco deste trabalho é a arquitetura das classes (seus relacionamentos e características).
- Não complique o código.
- Não use textos muito longos para o programa mostrar na tela.
- Nunca copie trabalho, trabalhos serão comparados. Cópias serão penalizadas.
- Nunca implemente funcionalidades desnecessárias! Alguns alunos copiam da internet trabalhos enormes com funcionalidades não pedidas e as vezes acham que copiar é melhor que fazer eles mesmos, o que não é verdade.
### Sim:
- Escreva comentários para cada classe e cada operação;
- Utilize moeda como centavos inteiros. Variáveis float e double causam arredondamento implícito e pode falhar no teste do balanço.
- O foco deste trabalho é C++ 1998, revisão 2003. Tente compilar no g++ com -std=c++98 para ter certeza que funciona com C++ 2003.
- Utilizem controle de versão e entregue as várias versões sequenciais. Para isso você pode usar GIT, HG, ou simplesmente separar as pastas em número de versão. Entregue tudo zipado com o repositório incluso. O histórico de modificações é uma grande prova que você implementou e evoluiu como aluno.
- Não compartilhem em repositórios públicos!
- Verificação e teste: Leia seus códigos antes de entregar; Teste seus códigos antes de entregar.
- Utilizem o chat durante as aulas:
- Conversem sobre o conteúdo;
- Tirem suas dúvidas.

## Créditos
Esse exercício/trabalho foi desenvolvido pelo professor _Tiago Gottardi_ na disciplina _"Programação orientada a Objeto"_ ministrado para a turma do periodo nortuno. (EMA9752/EMA9721-Comp-Not-2021) 
