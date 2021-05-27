/*
* Atividade Prática - Exercício 1
* Aluno: Marcos Fabricio Sizanosky RU-3395570
* Professor: Winston Sen Lun Fung
* Data criação: 27/04/2021
*/

#include <stdio.h>
#include <locale.h>

// Declaração da struct que armazena os dados do funcionário.
struct dados_funcionario {
    char nome_completo[80];
    float valor_salario;
};

// Função para limpar o buffer do teclado.
void limpa_buffer_teclado();

int main() {
    printf("Hello World!\n\n");

    // Função para habilitar a utilização de caracteres da lingua portuguesa.
    setlocale(LC_ALL, "Portuguese");

    // Declaração das variáveis e ponteiros.
    // Variável "funcionario" recebe a struct "cadastro_funcionario".
    struct dados_funcionario funcionario, *p_func;
    p_func = &funcionario; // Ponteiro para struct.
    double aliquota, deducao; // Variável para aliquota do imposto e valor a ser deduzido.

    // Cabeçalho do programa e informações ao usuário.
    printf("-=-=-=-=-=-= CADASTRO FUNCIONÁRIOS =-=-=-=-=-=-\n\n");
    printf("- Digite o nome completo do funcionário.\n");
    printf("- Digite o salário.\n");
    printf("- Visualize na tela a alíquota do imposto de renda e o valor que" 
           "será deduzido do salário do funcionário.\n\n");

    // As entradas do usuário são armazenadas na struct através dos ponteiros.
    printf("Nome completo: ");
    fgets(p_func->nome_completo, 79, stdin);
    limpa_buffer_teclado();

    printf("Salário: R$ ");
    scanf_s("%f", &p_func->valor_salario);
    limpa_buffer_teclado();

    //Bloco a seguir calcula qual é a dedução do imposto com base na alíquota.
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

    // Imprime na tela os dados do funcionário calculados anteriormente.
    printf("\n+=+=+=+=+=+= REGISTRO FUNCIONÁRIOS =+=+=+=+=+=+\n\n");
    printf("Nome................: %s\n", p_func->nome_completo);
    printf("Salário.............: R$ %.2f\n", p_func->valor_salario);
    printf("Alíquota imposto....: %.2f%%\n", aliquota);
    printf("Valor dedução.......: R$ %.2f\n", deducao);

    return 0;
}

void limpa_buffer_teclado() {
    /* Está função é utilizada para limpar o buffer do teclado após
     * um "scanf_s".
     */

    char c;
    while ((c = getchar()) != '\n' && c != EOF);

}