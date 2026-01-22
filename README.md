# ⚔️ Arduino Lightsaber (WS2813 + DFPlayer)

![Status](https://img.shields.io/badge/Status-Functional-brightgreen)
![Platform](https://img.shields.io/badge/Platform-Arduino%20Nano-blue)
![LEDs](https://img.shields.io/badge/LEDs-WS2813-orange)
![Audio](https://img.shields.io/badge/Audio-DFPlayer%20Mini-red)

Um projeto de Sabre de Luz DIY (Do It Yourself) de baixo custo, utilizando Arduino, fita de LED endereçável WS2813 e módulo de áudio DFPlayer Mini. O projeto foca em efeitos de ignição/retração suaves ("efeito cinema") e áudio sincronizado.

## ✨ Funcionalidades

* **Efeito Cinema:** Ignição e retração gradual da lâmina (base para ponta / ponta para base).
* **Som Sincronizado:** Efeitos sonoros de ligar e desligar via cartão SD.
* **Controle de Botão Único:** Clique para ligar, clique para desligar.
* **LED Indicador:** O botão acende quando o sabre está ativo.
* **Proteção de Dados:** Uso de fita WS2813 com canal de backup (maior durabilidade).
* **Personalizável:** Cores e velocidades ajustáveis via código.

## 🛠️ Lista de Materiais (Hardware)

| Componente | Detalhes |
| :--- | :--- |
| **Microcontrolador** | Arduino Nano (ATmega328P) |
| **LEDs** | Fita WS2813 (60 LEDs/m) - Aprox. 82cm (49 LEDs) |
| **Áudio** | Módulo DFPlayer Mini + Cartão SD (Formatado em FAT32) |
| **Alto-falante** | 3 Watts 4 Ohms (ou similar) |
| **Bateria** | 1x Célula Li-Ion 18650 (High Drain recomendado, ex: Sony VTC6) |
| **Carregamento** | Módulo TP4056 (USB-C) |
| **Botão** | Push Button (Momentâneo) iluminado ou simples |
| **Lâmina** | Tubo de Policarbonato Leitoso (T8) |

## 🔌 Esquema de Ligação

### Pinagem do Arduino

| Pino Arduino | Componente | Descrição |
| :--- | :--- | :--- |
| **D2** | LED Botão | LED indicador (opcional) |
| **D4** | Botão | Entrada do botão (Pull-down) |
| **D6** | Fita LED (DI) | Dados da fita WS2813 |
| **D10** | DFPlayer TX | Comunicação Serial (RX Virtual) |
| **D11** | DFPlayer RX | Comunicação Serial (TX Virtual) |
| **5V** | - | Alimentação (SE usar USB). **Use Vin ou 5V direto da bateria para uso final** |
| **GND** | GND Comum | Todos os terras devem estar unidos |

> **⚠️ Atenção:** Para a fita de LED (49 LEDs), a alimentação deve vir **diretamente da bateria/fonte**, não passando por dentro do regulador do Arduino.

## 💾 Estrutura do Cartão SD

O DFPlayer Mini requer uma estrutura de arquivos específica. Formate o cartão em **FAT32** e organize assim:

```text
Raiz do SD
└── mp3
    ├── 0001.mp3  <-- Som de Ignição (Ligar)
    └── 0002.mp3  <-- Som de Retração (Desligar)
