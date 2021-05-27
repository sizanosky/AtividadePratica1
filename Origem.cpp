/*
* Atividade Pr�tica - Exerc�cio 1
* Aluno: Marcos Fabricio Sizanosky RU-3395570
* Professor: Winston Sen Lun Fung
* Data cria��o: 27/04/2021
*/

#include <stdio.h>
#include <locale.h>

// Declara��o da struct que armazena os dados do funcion�rio.
struct dados_funcionario {
    char nome_completo[80];
    float valor_salario;
};

// Fun��o para limpar o buffer do teclado.
void limpa_buffer_teclado();

int main() {
    printf("Hello World!\n\n");

    // Fun��o para habilitar a utiliza��o de caracteres da lingua portuguesa.
    setlocale(LC_ALL, "Portuguese");

    // Declara��o das vari�veis e ponteiros.
    // Vari�vel "funcionario" recebe a struct "cadastro_funcionario".
    struct dados_funcionario funcionario, *p_func;
    p_func = &funcionario; // Ponteiro para struct.
    double aliquota, deducao; // Vari�vel para aliquota do imposto e valor a ser deduzido.

    // Cabe�alho do programa e informa��es ao usu�rio.
    printf("-=-=-=-=-=-= CADASTRO FUNCION�RIOS =-=-=-=-=-=-\n\n");
    printf("- Digite o nome completo do funcion�rio.\n");
    printf("- Digite o sal�rio.\n");
    printf("- Visualize na tela a al�quota do imposto de renda e o valor que" 
           "ser� deduzido do sal�rio do funcion�rio.\n\n");

    // As entradas do usu�rio s�o armazenadas na struct atrav�s dos ponteiros.
    printf("Nome completo: ");
    fgets(p_func->nome_completo, 79, stdin);
    limpa_buffer_teclado();

    printf("Sal�rio: R$ ");
    scanf_s("%f", &p_func->valor_salario);
    limpa_buffer_teclado();

    //Bloco a seguir calcula qual � a dedu��o do imposto com base na al�quota.
    if (p_func->valor_salario <= 1903.98) {
        aliquota = 0;
        deducao = 0;
    }

    else if (p_func->valor_salario <= 2826.65) {
        aliquota = 7.50;
        deducao = (p_func->valor_salario * 0.075);
    }

    else if (p_func->valor_salario <= 3751.05) {
        aliquota = 15.00;
        deducao = (p_func->valor_salario * 0.150);
    }

    else if (p_func->valor_salario <= 4664.88) {
        aliquota = 22.50;
        deducao = (p_func->valor_salario * 0.225);
    }

    else { // (p_func->valor_salario > 4664.88)
        aliquota = 27.50;
        deducao = (p_func->valor_salario * 0.275);
    }

    // Imprime na tela os dados do funcion�rio calculados anteriormente.
    printf("\n+=+=+=+=+=+= REGISTRO FUNCION�RIOS =+=+=+=+=+=+\n\n");
    printf("Nome................: %s\n", p_func->nome_completo);
    printf("Sal�rio.............: R$ %.2f\n", p_func->valor_salario);
    printf("Al�quota imposto....: %.2f%%\n", aliquota);
    printf("Valor dedu��o.......: R$ %.2f\n", deducao);

    return 0;
}

void limpa_buffer_teclado() {
    /* Est� fun��o � utilizada para limpar o buffer do teclado ap�s
     * um "scanf_s".
     */

    char c;
    while ((c = getchar()) != '\n' && c != EOF);

}