//Feito por: Lívia Neves

#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria 
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL || primeiro->valor >= novo->valor) {
		novo->prox = primeiro;
		primeiro = novo;
	}
	else {
		NO* atual = primeiro;
		while (atual->prox != NULL && atual->prox->valor < novo->valor) {
			atual = atual->prox;
		}
		if (atual->prox != NULL && atual->prox->valor == novo->valor) {
			cout << "O elemento já está na lista.";
			free(novo);
		}
		else {
			novo->prox = atual->prox;
			atual->prox = novo;
		}
	}
}

void excluirElemento()
{
	int valor;
	cout << "Que elemento você deseja excluir?";
	cin >> valor;

	NO* atual = primeiro;
	NO* anterior = NULL;

	while (atual != NULL && atual->valor < valor) {
		anterior = atual;
		atual = atual->prox;
	}

	if (atual != NULL && atual->valor == valor) {
		if (anterior == NULL) {
			primeiro = atual->prox;
		}
		else {
			anterior->prox = atual->prox;
		}
		free(atual);
		cout << "EXCLUIDO";
	}
	else {
		cout << "NAO ENCONTRADO";
	}
}



void buscarElemento()
{
	int valor;
	cout << "Digite o elemento a ser buscado: ";
	cin >> valor;

	NO* atual = primeiro;
	while (atual != NULL && atual->valor < valor) {
		atual = atual->prox;
	}

	if (atual != NULL && atual->valor == valor) {
		cout << "ELEMENTO ENCONTRADO";
	}
	else {
		cout << "NAO ENCONTRADO";
	}

}

