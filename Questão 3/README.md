Cartões de crédito

Um cartão de crédito (ou débito), é claro, é um cartão de plástico com o qual você pode pagar por bens e serviços. Impresso nesse cartão há um número que também é armazenado em um banco de dados em algum lugar, para que quando seu cartão for usado para comprar algo, o credor saiba de quem cobrar. Há muitas pessoas com cartões de crédito neste mundo, então esses números são bem longos: American Express usa números de 15 dígitos, MasterCard usa números de 16 dígitos e Visa usa números de 13 e 16 dígitos. E esses são números decimais (0 a 9), não binários, o que significa, por exemplo, que a American Express poderia imprimir até 10^15 = 1.000.000.000.000.000 cartões únicos! (Isso é, hum, um quatrilhão.)

Na verdade, isso é um pouco exagerado, porque os números de cartão de crédito têm alguma estrutura. Todos os números American Express começam com 34 ou 37; a maioria dos números MasterCard começa com 51, 52, 53, 54 ou 55 (eles também têm alguns outros números iniciais potenciais com os quais não nos preocuparemos neste problema); e todos os números Visa começam com 4. Mas os números de cartão de crédito também têm uma "soma de verificação" incorporada a eles, uma relação matemática entre pelo menos um número e outros. Essa soma de verificação permite que computadores (ou humanos que gostam de matemática) detectem erros de digitação (por exemplo, transposições), se não números fraudulentos, sem ter que consultar um banco de dados, o que pode ser lento. Claro, um matemático desonesto certamente poderia criar um número falso que, no entanto, respeita a restrição matemática, então uma pesquisa no banco de dados ainda é necessária para verificações mais rigorosas.

Algoritmo de Luhn

Então qual é a fórmula secreta? Bem, a maioria dos cartões usa um algoritmo inventado por Hans Peter Luhn da IBM. De acordo com o algoritmo de Luhn, você pode determinar se um número de cartão de crédito é (sintaticamente) válido da seguinte forma:

Multiplique cada outro dígito por 2, começando pelo penúltimo dígito do número, e depois some os dígitos desses produtos.
Adicione a soma à soma dos dígitos que não foram multiplicados por 2.
Se o último dígito do total for 0 (ou, em termos mais formais, se o total módulo 10 for congruente a 0), o número é válido!
Isso é meio confuso, então vamos tentar um exemplo com o visto do David: 4003600000000014.

Para fins de discussão, vamos primeiro sublinhar cada dois dígitos, começando pelo penúltimo dígito do número:

4 0 0 3 6 0 0 0 0 0 0 0 0 0 1 4

Ok, vamos multiplicar cada um dos dígitos sublinhados por 2:

1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

Isso nos dá:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Agora vamos somar os dígitos desses produtos (ou seja, não os produtos em si):

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

Agora vamos adicionar essa soma (13) à soma dos algarismos que não foram multiplicados por 2 (começando pelo final):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

Sim, o último dígito dessa soma (20) é 0, então o cartão de David é legítimo!

Então, validar números de cartão de crédito não é difícil, mas fica um pouco tedioso manualmente. Vamos escrever um programa.

Detalhes da implementação
No arquivo chamado credit.cno creditdiretório, escreva um programa que solicite ao usuário um número de cartão de crédito e então informe (via printf) se é um número de cartão American Express, MasterCard ou Visa válido, conforme as definições de cada formato aqui. Para que possamos automatizar alguns testes do seu código, pedimos que a última linha de saída do seu programa seja AMEX\nor MASTERCARD\nor VISA\nor INVALID\n, nada mais, nada menos. Para simplificar, você pode assumir que a entrada do usuário será inteiramente numérica (ou seja, desprovida de hifens, como pode ser impresso em um cartão real) e que não terá zeros à esquerda. Mas não assuma que a entrada do usuário caberá em um int! Melhor usar get_longda biblioteca do CS50 para obter a entrada dos usuários. (Por quê?)

Considere o exemplo abaixo de como seu programa deve se comportar ao receber um número de cartão de crédito válido (sem hifens).

$ ./credit
Number: 4003600000000014
VISA
Agora, get_longele mesmo rejeitará hifens (e mais) de qualquer maneira:

$ ./credit
Number: 4003-6000-0000-0014
Number: foo
Number: 4003600000000014
VISA

$ ./credit
Number: 6176292929
INVALID

