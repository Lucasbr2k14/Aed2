class ListaContigua:
    def __init__(self, tamanho:int=10):
        self.dados:list[None | int] = [None] * tamanho
        self.tamanho_total:int = tamanho
        self.gravados:int = 0

    def esta_vazia(self) -> bool:
        return bool(self.gravados)

    def esta_cheia(self) -> bool:
        return self.tamanho_total == self.gravados
    
    def adicionar_no_final(self, valor:int):
        if not self.esta_cheia():
            self.dados[self.gravados] = valor
            self.gravados += 1
        else:
            print("Erro: lista está cheia.")
            return
        
    def adicionar_na_posi(self, posicao:int, valor:int):
        if posicao < 0 or posicao >= self.tamanho_total:
            print("Erro: posição inválida.")
            return
        
        if self.esta_cheia():
            print("Erro: a lista está cheia")
            return

        for i in range(self.gravados, posicao, -1):
            print(f"-> {i}")
            self.dados[i] = self.dados[i-1]

        self.dados[posicao] = valor
        self.gravados += 1


    def __str__(self) -> str:
        return str(self.dados)

lista = ListaContigua()
lista.adicionar_no_final(11)
lista.adicionar_na_posi(0, 10)
lista.adicionar_na_posi(3, 21)
lista.adicionar_na_posi(3, 23)




# lista.adicionar_na_posi(10,20)
# lista.adicionar_na_posi(10, 20)
print(lista)
