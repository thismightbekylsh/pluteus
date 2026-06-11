# Material de Suporte

Esse material vai ajudá-los a entender os componentes utilizados no hardware, a programação do software no arduino e o que precisa ser desenvolvido para competir.

## Sumário
- [Hardware](#hardware)
    - [1. Arduino Mega 2560](#1-arduino-mega-2560)
        - [1.1 POWER](#11-power)
        - [1.2 ANALOG IN](#12-analog-in)
        - [1.3 DIGITAL](#13-digital)
        - [1.4 PWM](#14-pwm)
        - [1.5 COMMUNICATION](#15-communication)
- [Software](#software)
- [A Competição](#3-a-competição)

## Hardware

### 1. Arduino Mega 2560

Esse é o cérebro do nosso robô, toda a programação que fazemos para controlar os outros componentes é compilada nele e interpretada. Ele é composto de portas digitais, analógicas, de alimentação e outras funções.

![ARDUINO MEGA](https://majestronicz.in/cdn/shop/files/Arduino_MEGA_2560.jpg?v=1725085620")

### 1.1 POWER

- IOREF ( ***NÃO UTILIZAMOS*** ) 

Em resumo, o pino IOREF é apenas uma saída de leitura para que os shields saibam com qual nível de tensão lógica (5V ou 3.3V) o Arduino está trabalhando, garantindo maior segurança e universalidade no ecossistema Arduino. Você não deve usá-lo para alimentar componentes pesados, apenas como referência de sinal.

- RESET ( ***NÃO UTILIZAMOS*** )

A porta RESET do Arduino Mega 2560 serve para reiniciar o microcontrolador, fazendo com que o programa enviado para a placa comece a ser executado novamente do absoluto zero.

- 3.3V ( ***NÃO UTILIZAMOS ATÉ O MOMENTO*** )

A porta (ou pino) 3.3V do Arduino Mega 2560 é um pino de saída de alimentação. A função dele é fornecer energia elétrica regulada nessa voltagem específica para alimentar componentes externos.

- 5V

A porta (ou pino) 5V é a principal fonte de alimentação de saída para circuitos externos no Arduino Mega 2560. Como o microcontrolador da placa (ATmega2560) opera nativamente em 5V, esta é a tensão padrão para a esmagadora maioria dos componentes clássicos do ecossistema Arduino.

- GND

A porta (ou pino) GND significa "Ground" (que se traduz como Terra ou Massa em eletrônica).

O Arduino Mega possui 5 pinos GND espalhados pela placa, e todos eles estão conectados internamente entre si.

- VIN

A porta (ou pino) VIN significa "Voltage In" (Entrada de Tensão). Ela é uma das portas mais versáteis do Arduino Mega 2560, pois serve tanto como uma entrada para alimentar a placa quanto como uma saída de energia bruta.

### 1.2 ANALOG IN

As portas do intervalo A0 até A15 (Totalizando 16 pinos) são chamadas de analógicas. Diferente das portas digitais que trabalham com valores de HIGH ou LOW (ligado e desligado), essas portas podem enviar e receber valores variáveis de energia. 0-256 ou 0-1024 em alguns casos.

### 1.3 DIGITAL 

As portas DIGITAL (0 a 53) do Arduino Mega 2560 são pinos bidirecionais projetados para enviar ou receber sinais elétricos discretos, operando exclusivamente em dois estados lógicos: ALTO (5V, ligado) ou BAIXO (0V/GND, desligado).

### 1.4 PWM

A sigla PWM significa Pulse Width Modulation (Modulação por Largura de Pulso). Em placas de desenvolvimento (como o Arduino), as portas PWM são pinos digitais especiais que conseguem simular um sinal analógico.

### 1.5 COMMUNICATION

As portas de Communication (Comunicação) do Arduino Mega 2560 são pinos dedicados à troca de dados entre a placa e outros dispositivos, como computadores, sensores complexos, telas ou outros microcontroladores.

O Arduino Mega 2560 se destaca por possuir quatro tipos de barramentos de comunicação nativos:

- **Serial / UART**: 
Utiliza dois pinos para cada porta: um para transmitir dados (TX) e outro para receber dados (RX). Os pinos RX de um dispositivo devem ser conectados ao TX do outro, e vice-versa.
    - **Serial (Pinos 0 - RX e 1 - TX)**: Conectada diretamente ao chip USB da placa. É a porta usada para enviar o código do computador para o Arduino e para exibir dados no Monitor Serial.
    - **Serial1 (Pinos 19 - RX e 18 - TX)**
    - **Serial2 (Pinos 17 - RX e 16 - TX)**
    - **Serial3 (Pinos 15 - RX e 14 - TX)**

- **I2C** ( ***NÃO UTILIZAMOS*** ): É um barramento de comunicação síncrono que permite conectar dezenas de dispositivos usando apenas dois fios, compartilhando a mesma linha de dados. Utiliza um pino para o sinal de clock (SCL) e outro pino para os dados (SDA). Cada dispositivo conectado ao barramento possui um endereço hexadecimal exclusivo (como uma identidade). O Arduino (Mestre) envia o endereço do dispositivo com quem deseja falar e transmite os dados na linha compartilhada.

- **SPI** ( ***NÃO UTILIZAMOS*** ): É o barramento síncrono mais rápido da placa, ideal para transferir grandes volumes de dados em curtos períodos de tempo. Ele funciona de forma full-duplex (envia e recebe dados exatamente ao mesmo tempo). Utiliza quatro fios obrigatórios:
    - **MISO (Master In Slave Out)**: Linha por onde o Arduino recebe os dados do periférico.
    - **MOSI (Master Out Slave In)**:
    Linha por onde o Arduino envia dados para o periférico.
    - **SCK (Serial Clock)**: Linha que sincroniza o tempo de envio dos dados.
    - **SS (Slave Select)**: Pino usado para ativar o periférico específico com o qual o Arduino quer falar. Cada novo dispositivo SPI precisa de um pino SS exclusivo.

