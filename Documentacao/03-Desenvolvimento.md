
# Materiais

Os materiais utilizados no projeto foram:
- Bomba
- 5 resistores 
- Garrafa
- Esp32
- 2 protoboards 
- 15 fios
- Sensor de distância 
- Potenciômetro 
- Led rgb
- Led verde
- Chave dois estados
- Transistor

# Desenvolvimento

Descreva aqui como foi o desenvolvimento do trabalho, destacando cada uma das etapas necessárias para chegar até a solução final.

## Desenvolvimento do Aplicativo

### Interface

A interface do aplicativo foi desenvolvida de forma simples e intuitiva, permitindo que o usuário escolha bebidas e ative a máquina com poucos toques. Utilizamos MIT App Inventor, criando botões com a quantidade de mililitros que o usuario deseja e mensagens de retorno sobre o status da bebida.

### Código

O código do aplicativo foi desenvolvido com blocos que:

Estabelecem a conexão Bluetooth com o ESP32;

Enviam comandos em texto, como "drink1", "drink2", etc.;

Exibem mensagens de retorno recebidas do ESP32, como "pronto" ou "erro".

O aplicativo inicia tentando conectar ao módulo Bluetooth do ESP32, e uma vez conectado, os botões ficam habilitados para interação com o sistema físico.



## Desenvolvimento do Hardware

### Montagem

A montagem foi feita com o ESP32, conectado a uma protoboard junto com transistores NPN (como o 2N2222 ou BC548), resistores de base, fios jumper, bombas de líquido 5V e um sensor ultrassônico HC-SR04 para verificar a presença do copo.

As bombas foram conectadas ao ESP32 por meio de transistores, que funcionam como chaves para acionar os motores das bombas. O sensor ultrassônico foi fixado na estrutura da caixa para detectar se o copo está presente antes de iniciar o bombeamento, evitando desperdícios.

A caixa de MDF foi preparada com furos frontais para o sensor e passagem dos tubos. A placa de prototipagem e a fiação foram organizadas dentro da estrutura.

### Desenvolvimento do Código

O código do ESP32 foi escrito na IDE do Arduino em C++, utilizando a biblioteca BluetoothSerial.h.

As principais funções do código são:

Iniciar o módulo Bluetooth com um nome identificável;

Esperar comandos recebidos via Bluetooth;

Interpretar os comandos recebidos e ativar as bombas correspondentes;

Checar, com o sensor ultrassônico, se o copo está presente antes de liberar os líquidos;

Enviar mensagens de volta ao aplicativo confirmando o andamento da operação.

## Comunicação entre App e Hardware

Toda a comunicação entre o aplicativo e o hardware foi feita usando Bluetooth clássico. O ESP32 foi configurado como um servidor Bluetooth, utilizando a biblioteca BluetoothSerial. O aplicativo, ao ser iniciado, se conecta ao ESP32 por meio do módulo de pareamento e envia comandos de texto.
