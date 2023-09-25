# echoUART

Esse projeto implementa um periférico e um central.
O periférico contém 
    - Uma característica com permissão de escrita e que irá receber os dados
    - Uma característica sem permissão e que realiza notificação
        - a notificação é enviada sempre que um dado for recebido
        - o conteúdo da notificação é o dado recebido com as letras minúsculas convertidas para maiúsculas

O central:
    - procura e se conecta ao periférico
    - envia ao periférico o que o usuário escreve no terminal
    - imprime a resposta enviada pelo periférico
 
# Como utilizar:
Abra e faça o build do Central com PLATFORMIO.
Abra e faça o build do Peripheral com PLATFORMIO.

Abra o renode e escreva
s @"DIRETORIO DO PROJETO"\ble.resc

EM CASO DE ERRO, VERIFIQUE O CAMINHO DO PROJETO E DAS FIRMWARES FEITAS NOS BUILDS.
