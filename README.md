# relogio_simples_arduino
Relógio simples com Arduino + LCD Shield

Este projeto implementa um relógio básico em Arduino usando apenas o LCD Keypad Shield (16x2 + 5 botões).
A contagem de tempo é feita a partir do clock interno do Arduino (millis()), sem necessidade de módulos RTC externos.

A configuração do horário é feita via serial, podendo ser realizada pelo Arduino IDE, terminal do PC ou até mesmo por aplicativos de monitor serial no celular.

## Funcionalidades

Exibe a hora no formato HH:MM em um display LCD 16x2.

Permite configurar a hora via porta serial.

Usa os botões do shield para interações simples:

Direita → Liga lanterna (pino digital 10).

Esquerda → Desliga lanterna.

Select → Ativa modo de ajuste do relógio (via serial).

## Configuração via Serial

Para ajustar o relógio, pressione o botão Select e insira a hora no formato HHMM.
Exemplo:

Digite a hora no formato HHMM:
1530


Resultado → Relógio configurado para 15:30.

## Exemplo de uso no terminal

No Linux/macOS, você pode usar o comando screen para se conectar ao Arduino.
Substitua pela porta correta do seu dispositivo (no exemplo, /dev/tty.usbserial-A5069RR4):

screen /dev/tty.usbserial-A5069RR4 9600


Para sair do screen, use a combinação de teclas:

CTRL + A  seguido de  K

## Hardware necessário

Arduino UNO (ou compatível)

LCD Keypad Shield (16x2 + 5 botões)


## Possíveis melhorias

Utilizar o relógio interno como gatilho para automações, executando comandos em horários definidos (ex: ligar/desligar dispositivos, acionar relés, alarmes, rotinas diárias).

Integrar em projetos maiores que necessitem de agendamento, sem depender de módulos RTC adicionais.

Adicionar contagem de segundos para maior precisão.

Salvar a hora configurada em memória não volátil (EEPROM) para manter o horário após reinicializações.

## Licença

Este projeto é open-source. Utilize, modifique e compartilhe livremente.