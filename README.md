# Formula E Weather Condition Sensor

<img src="https://github.com/Insider-E/InsiderE-Weather-Condition-Sensor/blob/main/circuit_design.png">

Este repositório contém o código-fonte e a documentação para um projeto de sensor de condições climáticas desenvolvido para a Fórmula E. Este sensor foi projetado para monitorar e registrar dados ambientais cruciais que podem influenciar o desempenho dos carros durante as corridas. Utilizando a plataforma Arduino, o sensor coleta informações em tempo real sobre temperatura, umidade, pressão atmosférica e luminosidade, fornecendo dados precisos e confiáveis para a equipe técnica.

## Funcionalidades

- **Monitoramento de Temperatura:** Medição precisa da temperatura ambiente utilizando sensores digitais.
- **Detecção de Umidade:** Avaliação da umidade relativa do ar para entender as condições atmosféricas.
- **Sensor de Luminosidade:** Monitoramento da intensidade da luz para ajustes estratégicos durante a corrida.
- **Interface de Exibição:** Exibição dos dados em tempo real em um display LCD ou via comunicação serial para um sistema central.

## Componentes Utilizados

- **Arduino Uno:** Microcontrolador principal do projeto.
- **TMP36:** Sensor de temperatura.
- **Potenciometro:** Para simular a umidade e ligar o LCD.
- **LDR:** Resistor dependente de luz para medir a luminosidade.
- **Display LCD 16x2:** Para exibir os dados em tempo real.
- **Protoboard:** Para montar e testar os circuitos de forma rápida e prática.
- **Hobby Gearmotor:** Motor DC para adicionar movimento ao projeto.
- **Driver de Motor L293D:** Driver para controlar o hobby gearmotor.
- **Osciloscópio:** Para visualizar sinais elétricos e ajudar na depuração do circuito

## Instalação

1. Clone este repositório:
   ```bash
   git clone https://github.com/Insider-E/InsiderE-Weather-Condition-Sensor
   ```
2. Instale as bibliotecas necessárias no Arduino IDE:
   - Adafruit Sensor
   - DHT sensor library
   - Liquid Crystal

3. Carregue o código no Arduino Uno através do Arduino IDE.

## Utilização

1. Conecte os sensores aos pinos correspondentes no Arduino conforme indicado no arquivo `circuit_design.png`.
2. Carregue o código e abra o monitor serial no Arduino IDE para visualizar os dados em tempo real.

## Integrantes:

- David Murillo de Oliveira Soares (RM 559078)
- Davi dos Reis Garcia (RM 556741)
- Yasmin Gonçalves Coelho (RM 559147)
- Yasmin Naomi Minemoto (RM 559154)


## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues para sugestões de melhorias ou para enviar pull requests.

---

Este sensor é uma ferramenta essencial para as equipes da Fórmula E, ajudando a maximizar o desempenho e a segurança dos carros durante as corridas. Seja bem-vindo a explorar, utilizar e melhorar este projeto!
