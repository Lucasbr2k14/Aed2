class ListaContigua:
    #------------------------------------------------
    def __init__(self, capacidade=10):        
        self.dados = [None] * capacidade
        self.tamanho = 0
    #------------------------------------------------
    def esta_vazia(self):
        return self.tamanho == 0
    #------------------------------------------------
    def esta_cheia(self):
        return self.tamanho == len(self.dados)
    #------------------------------------------------
    def tamanho_atual(self):
        return self.tamanho
    #------------------------------------------------
    def inserir_no_final(self, elemento):
        if self.esta_cheia():
            raise Exception("Lista cheia! Não é possível inserir.")
        self.dados[self.tamanho] = elemento
        self.tamanho += 1
    #------------------------------------------------
    def inserir_na_posicao(self, posicao, elemento):
        if self.esta_cheia():
            raise Exception("Lista cheia! Não é possível inserir.")
        if posicao < 0 or posicao > self.tamanho:
            raise IndexError("Posição inválida!")

			  # Desloca elementos para a direita para abrir espaço
        for i in range(self.tamanho, posicao, -1):
            self.dados[i] = self.dados[i-1]

        self.dados[posicao] = elemento
        self.tamanho += 1
    #------------------------------------------------
    def remover_da_posicao(self, posicao):
        if self.esta_vazia():
            raise Exception("Lista vazia! Não é possível remover.")
        if posicao < 0 or posicao >= self.tamanho:
            raise IndexError("Posição inválida!")

				# Armazena o elemento a ser removido
        elemento = self.dados[posicao]

			  # Desloca elementos para a esquerda para preencher o espaço
        for i in range(posicao, self.tamanho - 1):
            self.dados[i] = self.dados[i+1]

        self.dados[self.tamanho - 1] = None
        self.tamanho -= 1
        return elemento
    #------------------------------------------------
    def buscar(self, elemento):
        for i in range(self.tamanho):
            if self.dados[i] == elemento:
                return i
        return -1# Elemento não encontrado
    #------------------------------------------------
    def acessar(self, posicao):
        if posicao < 0 or posicao >= self.tamanho:
            raise IndexError("Posição inválida!")
        return self.dados[posicao]
    #------------------------------------------------
    def atualizar(self, posicao, elemento):
        if posicao < 0 or posicao >= self.tamanho:
            raise IndexError("Posição inválida!")
        self.dados[posicao] = elemento
    #------------------------------------------------
    def inserir_ordenado(self, elemento):
        if self.esta_cheia():
            raise Exception("Lista cheia! Não é possível inserir.")

        posicao = 0
        while posicao < self.tamanho and self.dados[posicao] < elemento:
            posicao += 1

        self.inserir_na_posicao(posicao, elemento)
    #------------------------------------------------
    def reverter(self):
        inicio = 0
        fim = self.tamanho - 1
        while inicio < fim:
            self.dados[inicio], self.dados[fim] = self.dados[fim], self.dados[inicio]
            inicio += 1
            fim -= 1
    #------------------------------------------------
    def remover_duplicatas(self):
        for i in range(self.tamanho):
            for j in range(self.tamanho):
                if self.dados[i] == self.dados[j]:
                    self.remover_da_posicao(i)

    def __str__(self):
        return str([self.dados[i] for i in range(self.tamanho)])
    
lista = ListaContigua()
lista.inserir_ordenado(10)
lista.inserir_ordenado(2)
lista.inserir_ordenado(8)
lista.inserir_ordenado(1)
lista.inserir_ordenado(7)
lista.inserir_ordenado(7)
lista.inserir_ordenado(7)
lista.inserir_ordenado(7)
lista.inserir_ordenado(7)
lista.inserir_ordenado(3)
lista.remover_duplicatas()

print(lista)