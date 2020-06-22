# Projeto da disciplina de Objetos Inteligentes Conectados

## Turma 05K11.

## Alunos:

## Leonardo Quintiliano dos Santos
## Luca Scattolin Manuguerra


 Requisitos avaliados no artigo:
 
#### 1.Introdução:

#### 2.Materiais e Métodos:

#### 3.Resultados:

#### 4.Conclusões:

#### 5.O artigo:

#### 6.Referências:

***********************************************Todos os tópicos seguem abaixo **********************************************************

### 1.Neste projeto, desenvolvemos um sistema de aquecimento de agua com iot,para que possa funcionar automaticamente com um unico clique
utliziando um sensor  e um módulo nodeMCU.

O sistema estará conectado a uma tomada ou fonte externa de energia para que um aquecedor seja acionado e
de acordo com a temperatura da agua em tempo real fornecida pelo sensor, um rele será ligado ou desligado,
controlando o aquecedor.
Haverá uma lampada ligada também ao rele, informando visualmente quando o aquecedor estará ligado ou não.

O sistema também conta com um dashboard contendo um indicador mostrando a temperatura do sensor  e
um botão para ligar e desligar o aquecedor no qual o mesmo está sempre desligado e quando o botão for pressionado,se a agua 
estiver a uma temperatura menor que a desejada,o aquecedor deverá ligar e caso a temperatura esteja maior, ele permanecera desligado.
O dashboard foi implementado no Node-RED, se comunicando com o sistema via protocolo MQTT utilizando o broker IBM CLOUD 
https://cloud.ibm.com/.

Um vídeo demonstrando o sistema em funcionamento se encontra disponível em https://youtu.be/PSYkpyM_V9E.

2.O sistema foi construído com os seguintes materiais:

* 1 MÓDULO NODEMCU ESP-12 ESP8266.
* 1 SENSOR DE TEMPERATURA DS18B20 A PROVA D' AGUA.
* 1 FONTE CHAVEADA DE 5V.
* 1 LAMPADA 220V.
* 1 PROTOBOARD.
* 1 RESISTOR DE 4K7 OHMS.
* 1 MÓDULO RELE.
* 10 JUMPER MACHOS E FÊMEAS.
* 1 AQUECEDOR MASTER PARA AQUÁRIO.
* 1 CONVERSOR 3.3v PARA 5v.

![](https://github.com/LeonardoQuintiliano/IoT-Project/blob/master/imagens/IoTProjeto.jpg)


3.Software arduino & sua programação & 4.Resultado (pode ir junto de cada informação de código)

Bibliotecas


![](https://github.com/LeonardoQuintiliano/IoT-Project/blob/master/imagens/biblioteca.jpg)

Definição dos pinos do sensor & rele

![](https://github.com/LeonardoQuintiliano/IoT-Project/blob/master/imagens/PinSensorRele.jpg)

Definição das variaveis

![](https://github.com/LeonardoQuintiliano/IoT-Project/blob/master/imagens/variaveis.jpg)

void setup
![](https://github.com/LeonardoQuintiliano/IoT-Project/blob/master/imagens/voidsetup.jpg)

void loop
![](https://github.com/LeonardoQuintiliano/IoT-Project/blob/master/imagens/voidloop.jpg)

void leitura sensor
![](https://github.com/LeonardoQuintiliano/IoT-Project/blob/master/imagens/voidLeiturasensor.jpg)


5.(ARTIGO DO LEO)

6.(REFERENCES)
