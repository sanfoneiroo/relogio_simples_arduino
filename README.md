# relogio_simples_arduino
Relógio simples com Arduino + LCD Shield + Termômetro 

Este projeto implementa um relógio básico em Arduino usando apenas o LCD Keypad Shield (16x2 + 5 botões).
A contagem de tempo é feita a partir do clock interno do Arduino (millis()), sem necessidade de módulos RTC externos.

A configuração do horário é feita via serial, podendo ser realizada pelo Arduino IDE, terminal do PC ou até mesmo por aplicativos de monitor serial no celular.

Posteriormente foi adicionado um sensor NTC para medir a temperatura ambiente
Posteriormente foi modificada a configuração de relógio via serial para botões do shield

## Funcionalidades

Exibe a hora no formato HH:MM em um display LCD 16x2.

Permite configurar a hora via porta serial. **
Permite configurar a hora via botões do shield

Usa os botões do shield para interações simples:

Select → Liga/Desliga luz do display (pino digital 10).

Direita → Adiciona minuto.

Esquerda → Subtrai minuto.

Cima → Adiciona hora.

Baixo → Subtrai hora.


## Configuração via Serial
Apagada no código atual

Para ajustar o relógio, pressione o botão Select e insira a hora no formato HHMM.
Exemplo:

Digite a hora no formato HHMM:
1530

## Configuração via botões

Utilize o botão Select para ascender/apagar a luz do display, pressione o botao para  cima para  adicionar 1 hora, para baixo para  subtrair 1 hora, para esquerda para subtrair 1 minuto e para  direita para adicionar 1 minuto


Resultado → Relógio configurado para 15:30.


## Hardware necessário

Arduino UNO (ou compatível)

LCD Keypad Shield (16x2 + 5 botões)

Sensor NTC + Resistor


## Possíveis melhorias

Utilizar o relógio interno como gatilho para automações, executando comandos em horários definidos (ex: ligar/desligar dispositivos, acionar relés, alarmes, rotinas diárias).

Integrar em projetos maiores que necessitem de agendamento, sem depender de módulos RTC adicionais.

## Licença

Este projeto é open-source. Utilize, modifique e compartilhe livremente.
