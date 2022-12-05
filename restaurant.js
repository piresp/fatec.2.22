console.log('by https://github.com/piresp');

function createRestaurant(name, address, rate, type) {
    return {
        name,
        address,
        rate,
        type
    };
}

//function dataValid(arrayobj) {
//    let i = arrayobj.lenght 
//    arrayobj[i].rate > 5 || arrayobj[i].rate || typeof arrayobj[i].rate != "number" < 0 ? restaurantList.splice(i, 1) : 'valid';
//}

let panel = 1;
let restaurantList = [];
do {

    console.log('1 - Criar novo Restaurante');
    console.log('2 - Listar Restaurantes');
    console.log('3 - Deletar Restaurante');
    console.log('4 - Sair');

    switch (panel) {
        case 1:
            restaurantList.push(
                createRestaurant(
                    prompt('Nome do restaurante: '),
                    prompt('Endereço do restaurante: '),
                    prompt('Nota do restaurante \n0 - Horrivel\n1 -  Ruim\n2 - Razoável\n3 - Bom\n4 - Muito Bom\n5 - Espetacular:\n'),
                    prompt('Tipo da comida do restaurante: ')
                )
            );
            //dataValid(restaurantList);

        case 2:
            console.table(restaurantList)

        case 3:
            restaurantList.splice(
                prompt('Posição a ser excluida: '), 1
            );

        case 4:
            break;
        
        default:
            console.log('Comando Inválido.');
    }

} while (panel != 4)
