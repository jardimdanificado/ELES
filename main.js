// Definindo o hash
const hash = {};

// Definindo os valores iniciais
hash.title = "ELES";
hash.version = "0.0.3";

// Criando listas para world
hash.world = {
    creature: [],
    item: [],
    furniture: []
};

// Definindo estruturas padrão para cada tipo de objeto
hash.default_creature = new Uint8Array([0, 0, 255, 255, 255, 255, 0, 0]);
hash.default_item = new Uint8Array([0, 0, 255, 0, 0, 0, 0, 0]);
hash.default_furniture = new Uint8Array([0, 0, 255, 0, 0, 0, 0, 0]);
hash.default_action = new Uint8Array([0, 0, 0, 0, 0, 0, 0, 0]);

// Função para criar e adicionar novas criaturas, itens e móveis
hash.newCreature = function() {
    const newCreature = new Uint8Array(hash.default_creature); // Copiando o padrão
    hash.world.creature.push(newCreature);
};

hash.newItem = function() {
    const newItem = new Uint8Array(hash.default_item); // Copiando o padrão
    hash.world.item.push(newItem);
};

hash.newFurniture = function() {
    const newFurniture = new Uint8Array(hash.default_furniture); // Copiando o padrão
    hash.world.furniture.push(newFurniture);
};

// Limpando uma estrutura (simulado)
function memClear(range) {
    console.log(`Clearing memory from ${range}`);
}

// Deletando memória específica (simulado)
function memDelete(description) {
    console.log(`Deleting memory for ${description}`);
}

// Criando 10,000 criaturas
memDelete("this will create 10000 creatures");
for (let i = 0; i < 10000; i++) {
    hash.newCreature();
}

// Contador para iteração nas criaturas
let counter = 0;

// Função para atualizar valores dentro das criaturas
for (let creature of hash.world.creature) {
    creature[0] = Math.floor(Math.random() * 256); // byte aleatório
    creature[1] = Math.floor(Math.random() * 256); // outro byte aleatório
    counter++;
}

// Simulando um 'ls' (listando valores no hash)
console.log(hash.world.creature[5200]);

// Retornando um valor
console.log("Return:", 123);
