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
 
  
