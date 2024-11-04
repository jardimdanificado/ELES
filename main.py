import os
import random
import time

# Definindo o hash como um dicionário
hash_map = {}

# Definindo os valores iniciais
hash_map["title"] = "ELES"
hash_map["version"] = "0.0.3"

# Criando listas para o mundo
hash_map["world"] = {
    "creature": [],
    "item": [],
    "furniture": []
}

# Definindo estruturas padrão para cada tipo de objeto
hash_map["default_creature"] = bytearray([0, 0, 255, 255, 255, 255, 0, 0])
hash_map["default_item"] = bytearray([0, 0, 255, 0, 0, 0, 0, 0])
hash_map["default_furniture"] = bytearray([0, 0, 255, 0, 0, 0, 0, 0])
hash_map["default_action"] = bytearray([0, 0, 0, 0, 0, 0, 0, 0])

# Funções para criar e adicionar novas criaturas, itens e móveis
def new_creature():
    new_creature = bytearray(hash_map["default_creature"])  # Copiando o padrão
    hash_map["world"]["creature"].append(new_creature)

def new_item():
    new_item = bytearray(hash_map["default_item"])  # Copiando o padrão
    hash_map["world"]["item"].append(new_item)

def new_furniture():
    new_furniture = bytearray(hash_map["default_furniture"])  # Copiando o padrão
    hash_map["world"]["furniture"].append(new_furniture)

# Função para simular a limpeza de memória
def mem_clear(range_description):
    print(f"Clearing memory from {range_description}")

# Função para simular exclusão de memória
def mem_delete(description):
    print(f"Deleting memory for {description}")

# Criando 10.000 criaturas
mem_delete("this will create 10000 creatures")
for _ in range(10000):
    new_creature()

# Atualizando cada criatura com valores aleatórios
counter = 0
for creature in hash_map["world"]["creature"]:
    creature[0] = random.randint(0, 255)  # byte aleatório
    creature[1] = random.randint(0, 255)  # outro byte aleatório
    counter += 1

# Simulando um 'ls' (listando valores no hash)
print("Keys in hash_map:", list(hash_map.keys()))

# Retornando um valor
print("Return:", 123)
