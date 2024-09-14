# Formula E Weather Condition Sensor

<img src="https://github.com/Insider-E/InsiderE-Weather-Condition-Sensor/blob/main/circuit_design.png">

# Projeto IoT para Formula E - Monitoramento Ambiental

Este projeto utiliza um ESP32 para coletar dados ambientais (temperatura, umidade e luminosidade) e enviá-los para um servidor MQTT. Os dados são então exibidos em um dashboard criado com Node-RED.

## Componentes do Hardware

- ESP32
- Sensor DHT22 (temperatura e umidade)
- LDR (sensor de luminosidade)

## Funcionalidades

1. Leitura de temperatura e umidade usando o sensor DHT22
2. Medição de luminosidade usando um LDR (Light Dependent Resistor)
3. Envio dos dados coletados para um servidor MQTT
4. Exibição dos dados em um dashboard Node-RED

## Configuração

### ESP32

1. Conecte o DHT22 e o LDR ao ESP32 conforme o esquema de pinagem no código.
2. Instale as bibliotecas necessárias:
   - DHT sensor library
   - PubSubClient (para MQTT)
3. Configure as credenciais de WiFi e MQTT no código.
4. Faça o upload do código para o ESP32.

### Servidor MQTT

1. Configure um servidor MQTT (por exemplo, Mosquitto).
2. Certifique-se de que o servidor está acessível pela rede.

### Node-RED

1. Instale o Node-RED em seu ambiente.
2. Importe o fluxo fornecido para criar o dashboard (flows.json).
3. Configure os nós MQTT para se conectar ao seu servidor MQTT.

## Uso

1. Ligue o ESP32 e verifique se ele está se conectando ao WiFi e ao servidor MQTT.
2. Acesse o dashboard do Node-RED para visualizar os dados em tempo real.
3. Monitore a temperatura, umidade e luminosidade do ambiente.

## Troubleshooting

- Verifique as conexões dos sensores se os dados não estiverem sendo lidos corretamente.
- Confirme se as credenciais de WiFi e MQTT estão corretas no código do ESP32.
- Verifique os logs do Node-RED para problemas de conexão com o servidor MQTT.

## Contribuições

Contribuições para melhorar este projeto são bem-vindas. Por favor, abra uma issue para discutir mudanças propostas ou envie um pull request.

## Licença

Este projeto está licenciado sob a [MIT License](https://opensource.org/licenses/MIT).