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
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* procu = posicaoElemento(novo->valor);
	if (procu == NULL) {
		if (primeiro == NULL)
		{
			primeiro = novo;
		}
		else
		{
			NO* aux = primeiro;

			NO* mudar = NULL;
			while (aux->prox != NULL) {
				
				if (novo->valor < aux->prox->valor) {
					
					if (novo->valor < aux->valor) {
						primeiro = novo;
						novo->prox = aux;
					}
					mudar = aux->prox;
					aux->prox = novo;
					novo->prox = mudar;
					break;
				}

				else {
					aux = aux->prox;
				}
			}

			while (aux->prox == NULL) {
				
				if (novo->valor < aux->valor) {
					primeiro = novo;
					novo->prox = aux;
				}
				else {
					aux->prox = novo;
				}
			}
		}
	}
	else {
		cout << "O numero ja existe na lista.\n";
	}
}

void excluirElemento()
{
	int valor;
	cout << "Digite o numero que deseja excluir: " << endl;
	cin >> valor;
	NO* procu = posicaoElemento(valor);

	if (procu != NULL) {
		NO* aux = primeiro;
		NO* ex = NULL;

		if (aux->valor == valor) {
			ex = primeiro;
			primeiro = aux->prox;
			free(ex);
		}
		else if (aux->prox != NULL) {
			while (aux->prox->valor == valor) {
				ex = aux->prox;
				primeiro->prox = ex->prox;
				free(ex);
				break;
			}

		}
	}
}

void buscarElemento(){
	int valor;
	cout << "Digite o numero que deseja excluir: \n";
	cin >> valor;
	NO* procu = posicaoElemento(valor);
	NO* aux = primeiro;
	if (procu != NULL) {
		while (aux->prox->valor < valor) {
			aux = aux->prox;
		}
		NO* posicao = aux->prox;
		cout << "O numero esta na posicao: " << posicao << endl;
	}
	else {
		cout << "Numero nao encontrado.\n";
	}
}


NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}