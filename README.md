# Syllogism Calculator

O programa realiza todas as combinações possíveis de inferências categóricas e modos e as avalia. Neste readme você pode encontrar uma pequena revisão do conteúdo para que seja possível entender o que foi escrito no programa. Juntamente com o resumo vai uma explicação um pouco maior sobre o projeto na sessão "Sobre o projeto".

Palavras chave: Lógica clássica, inferências, silogismo, proposições, termo, quantificador, interpretação booleana, C++, g++.

## Instalação

Como é um programa que não possui interface gráfica é preciso baixá-lo via git clone, compilar e então vai ter o executável. Pode ser compilado utilizando g++ sem problemas. O IDE que eu utilizei para escrever foi o Visual Studio, logo comentado no inicio do projeto tem a importação de um arquivo que só faz sentido neste IDE. 

```bash
git clone git@github.com:leoblima/syllogism.git
cd syllogism
g++ main.cpp -o nomeDesejado
```

## Uso

```bash
./nomeDesejado

# retorna todos as 256 combinações possíveis e quais são válidas
O silogismo eh : 1-A A A  valido 1 
O silogismo eh : 1-A A E  invalido 2 
O silogismo eh : 1-A A I  valido 3 
...
O silogismo eh : 4-O O O  invalido 256
```

## Sobre o projeto

Este projeto foi idealizado durante a realização de uma disciplina de lógica em 2018, logo eu ainda não tinha muito contato com a programação. Ele foi escrito em C++, pois foi a linguagem que eu aprendi anteriormente no meu curso de física computacional. 

Depois de muito tempo e agora sendo um desenvolvedor fullstack para Web, resolvi revisitar este código. Pensei em ajustá-lo antes de subir, mas achei que seria interessante manter registrado a trajetória deste projeto. O CMake foi adiconado posteriomente e básicamente pelo IDE que estou utilizando atualmente, o CLion. Não foi feita nenhuma alteração.

Como eu ainda não tinha muita pŕatica de programação, é possível ver várias incoerências no código, como mudança de línguas durante a nomeção das variáveis e funções, funções extensas, tudo escrito em um só arquivo, e outras práticas ruins de programação. Todavia, o código foi comentado e pode ser uma fonte de estudo do conteúdo de silogismo. Todas as regras estão descritas no código bem como as proposições. É interessante avaliar um projeto que foi escrito sob a ótica de um estudante de lógica e não de um programador. 

Acaba que o objetivo era preservar a estrutura da teoria e não otimizar ou seguir as formas da computação.  



##  Conceitos Básicos

O primeiro (i) é o próprio conceito de lógica, o segundo (ii) é o conceito de inferências, o terceiro (iii) verdade e validade e o quarto (iv) o conceito de silogismo. 

(i) Lógica é o estudo das consequências lógicas, ou seja, estuda o que configura uma inferência e quais as formas de justificá-las. Dessa forma, não cabe a lógica a análise de conteúdo, mas a forma como o conteúdo é expostos e a relação do conteúdo com uma possível conclusão. 

(ii) As inferências são formadas por proposições, um termo de consequência lógica e uma conclusão( que também é uma proposição). As formas das inferências podem variar, mas possuem alguns aspectos em comum. Na lógica Aristotélica, vai ser definido um número finito de formas válidas, mas, na lógica moderna, esse número não é tão definível assim.

(iii) O conceito de verdade pode render longas discussões, mas ninguém discute que o Verdadeiro eo Falso são qualidades das proposições. E a validade e invalidade qualidades das inferências. Como vimos, as inferências são formadas por proposições e é comum  confundir e dizer algo do tipo: “Essa inferência é verdadeira”. Quando as inferências são muito curtas elas podem ser muito semelhantes a uma proposição composta, sendo fácil confundir. 

(iv) O Silogismo é o nome comumente dado a teoria da inferência desenvolvida por Aristóteles. Essa teoria utiliza formas inferenciais bem definidas e gerais. As proposições que compõem as formas das inferências silogísticas podem ser verdadeira ou falsas do ponto de vista semântico e, do ponto de vista sintático, podem ser escritas na forma geral  (S + P). Sendo S o sujeito e P o predicado. 

## Teoria do Silogismo

1. Proposições Categóricas

	Como vimos no item iv, a teoria do silogismo utiliza nas suas inferências proposições do tipo S + P, mas essa fórmula pode ser mais detalhada. As proposições que seguem essa regra são chamadas de proposições categóricas. [S + P] pode ser escrito como [Q + Ts + C + Tp]. Na qual, Q significa quantificador, Ts significa termo subjetivo, C significa Cópula e Tp significa termo predicativo. 

	(i) Tentar definir de forma satisfatória e exegética o significado de termo seria impossível. A teoria do termo é tema muito complexo que vai entrar em outras áreas como filosofia da linguagem, metafísica, epistemologia e ontologia, mas precisamos deixar aqui uma definição para podermos trabalhar com os silogismos. Vamos entender termo como uma constante genérica(a, b, c...) que designa um, nenhum, alguns ou todos elementos de uma classe(K, L). Com isso, podemos entender o termo subjetivo(Ts) como sendo uma palavra que representa uma classe - e.g. Homem, Animal, Mamífero, Cachorro- e o termo predicativo(Tp) como uma outra classe - e.g. Mortal, Filósofo, Belo, Louco. 

	(ii) Os quantificadores, para Aristóteles, são dois: o quantificador universal e o particular. O quantificador universal é o “todo”, assim quando colocado junto a um Ts temos um sujeito composto como: todo homem e todo animal. O quantificador particular é o “algum” pode ser entendido como “ao menos um”, quando colocado junto a um Ts temos um sujeito composto como: algum homem e algum animal. Podemos pensar em nenhum como um quantificador, mas o nenhum pode ser reduzido à não todo. 

	(iii) Nos resta falar da cópula. A cópula é o que vai conectar o sujeito ao predicado. A cópula carrega com sigo as qualidades das proposições. As qualidades são duas: afirmativa e negativa. A cópula normalmente é o verbo “ser” no presente do indicativo. Assim a cópula é dita afirmativa quando não carrega uma negação, e.g. todo humano é animal. E ela é dita negativa quando ela carrega uma negação, e.g. todo humano não é animal. Nesse último exemplo, podemos ver que o quantificador(Q) é universal(todo), o termo subjetivo(Ts) é “humano”, a cópula(C) é negativa(não é) e o termo predicativo(Tp) é “animal”.
 
   (iv) Como dissemos no início dessa segunda parte, a teoria do silogismo de Aristóteles era bem definida e muito abrangente.  Usamos definida para evitar restrita, pois por mais que tenham todas as formas já realizadas, a teoria é bem abrangente. São quatro as possibilidades de proposições no silogismo Aristotélico. Os tipos são as combinações possíveis entre as quantidades(universal e particular) e as qualidades(afirmativa e negativa), ou seja, são quatro. São as quatros: (A) universal afirmativa - e.g. todo humano é animal-, (E) universal negativa - e.g. todo humano não é mortal ou nenhum humano é mortal-, (I) particular afirmativa - e.g. algum humano é animal-, (O) particular negativa - e.g. algum humano não é mortal. 

Partindo de um exemplo de proposição categórica, podemos exprimi-la de forma mais sucinta. Assim a frase: “todo homem é mortal” pode ser escrita como “todo a é b” sem prejuízo lógico, afinal a lógica não trata do conteúdo dos termos nas proposições, mas sim das suas formas inferenciais. Por ser uma universal afirmativa, convencionou-se que seria denotada pela letra maiúscula “A” e tendo os termos “a” e “b” ela pode ser escrita como Aab. As demais também tem as suas abreviações, sendo estas: Eab para as universais negativas, Iab para as particulares afirmativas e Oab para as particulares negativas.
 Vale ressaltar que os termos podem ser alterados e isso resultaria em outras proposições. Dessa forma, Aab é diferente de Aba e Acd. Se Aab fosse uma proposição como: todo homem é mortal, então Aba seria: todo mortal é homem e Acd seria todo c é d. Sendo Acd uma proposição completamente diferente, os termos poderiam ser substituídos por qualquer outra classe diferente das classes mortal e homem. Em um outro conjunto de proposições, Acd poderia ser considerado como: todo homem é mortal.  

## Lendo os resultados
 ```bash
   O silogismo eh : 1-A A A  valido 1
 ```
O que podemos retirar dessa resposta? 

O número na frente da sequência de letras representa a figura. As letras, no caso "A A A", como apresentado no texto, são as proposições categóricas que compõem a inferência. Por sua vez, o válido significa que é uma forma válida de inferência e o número por último serve como index.

Logo desse resultado temos que a seguinte forma de inferencia é válida:

Aab ^ Abc ⊢ Aac

Ou

Se todo A é B e todo B é C, então todo A é C.

## Desenvolvimento

Como podemos perceber, o programa não é interativo e não fornece todas as informações que poderia fornecer, como aonde as formas inválidas fogem das regras. Logo, tenho vontade de refatorar esse código e ampliá-lo para que possa ser interessante para qualquer um que se interesse pelo assunto.


## Contribuição
Pull requests são bem vindos. Assim como, ideias e sugestões de como organizar e expandir melhor o projeto. 
