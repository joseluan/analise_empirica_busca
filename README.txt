Desenvolvedor: José Luan Silva do Nascimento
#Compilando
Esse trabalho fiz da seguinte maneira, cada analise fiz um programa principal deixe como analise_.cpp o começo dos nomes dos programas.
Para você conseguir fazer os testes em sua máquina é preciso ter instalado os seguintes programas  (cmake, g++) em seu computador, logo após
abra a pasta build e digite o comando no terminal make analise_x, onde x é o nome do programa que vai ser compilado.

#Executando
Uma vez compilado digite no terminal, ./analise_x Y, Y é a quantidades de amostras que a saída do programa terá.
Pronto com o programa já executado voce terá na pasta onde foi executado um aquivo .txt que terá uma lista dos tempos de execução ou 
a quantidade de passos dos algoritmos.
	- Para não ocorrer falta de memória para alocar e/ou a exceção IndexOfOutBounds o programa se limita a de 1 á 1000
	  a entrada de quantidade de amostras.

#Visualizando
Para visualizar os dados você precisa ter instalado em seu computador o programa gnuplot, depois de instalado é necessario abri-lo e executar 
os comandos para plotar o gráfico. Ex.: plot "plot 'busca_42_passos.txt' using 1:2 title 'interativo' with lines" e "'busca.txt' with lines".
