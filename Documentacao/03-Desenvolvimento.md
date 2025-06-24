
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

O desenvolvimento do projeto da máquina de drinks foi realizado em etapas, envolvendo tanto a construção da interface do aplicativo quanto a montagem e programação do hardware. A comunicação foi feita exclusivamente via **Bluetooth**, garantindo portabilidade e independência de rede. A seguir, detalhamos cada uma das etapas necessárias para chegar à solução final.

A interface do aplicativo foi desenvolvida com foco na simplicidade e na usabilidade. Utilizando um ambiente de desenvolvimento visual como o **MIT App Inventor**, foram criadas telas com botões representando os diferentes drinks disponíveis. Cada botão envia um comando específico para o hardware, facilitando a escolha da bebida pelo usuário. Também foram inseridas mensagens visuais para indicar o status do preparo, como “Preparando bebida...” e “Drink pronto!”.

O código do aplicativo foi elaborado para permitir a conexão Bluetooth com o ESP32 e o envio de comandos em formato de texto. Cada botão executa uma rotina que:

* Conecta ao dispositivo Bluetooth;
* Envia o comando correspondente ao drink escolhido (ex: `drink1`, `drink2`);
* Aguarda uma resposta do ESP32 (ex: `ok`, `erro`);
* Mostra a mensagem apropriada ao usuário com base na resposta recebida.

A montagem do hardware foi feita utilizando um **ESP32**, conectado a uma **protoboard**. Foram utilizados **transistores NPN** (como o 2N2222), **resistores de base**, **bombas peristálticas 5V** para líquidos e um **sensor ultrassônico HC-SR04**. O sensor foi instalado na frente da caixa para detectar a presença do copo e evitar o acionamento das bombas sem recipiente.

O sistema foi montado dentro de uma **estrutura de MDF**, com orifícios para os tubos das bebidas e para o sensor. A alimentação foi feita via cabo USB conectado ao ESP32, e a disposição dos fios foi organizada para facilitar manutenção e evitar curtos.

O código do ESP32 foi desenvolvido na **IDE do Arduino**, utilizando a biblioteca `BluetoothSerial.h`. Ele é responsável por:

* Iniciar o Bluetooth com um nome visível para o aplicativo;
* Receber e interpretar os comandos enviados pelo app;
* Verificar a presença do copo utilizando o sensor ultrassônico;
* Ativar as bombas correspondentes por um tempo determinado;
* Enviar uma resposta de confirmação ao app.

A comunicação foi feita inteiramente via **Bluetooth**, sem necessidade de conexão Wi-Fi. O ESP32 atua como servidor Bluetooth, aguardando a conexão do aplicativo. Após o emparelhamento, o aplicativo envia comandos e recebe respostas em tempo real.

Esse modelo de comunicação traz diversas vantagens:

* Funciona mesmo em locais sem internet;
* Emparelhamento rápido e direto;
* Baixo consumo de energia;
* Facilidade de desenvolvimento e manutenção.

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
