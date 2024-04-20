import socket

# Configurações de rede
HOST = '127.0.0.1'  # Endereço IP local
PORT = 65432        # Porta de comunicação

# Cria um socket TCP/IP
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # Liga o socket ao endereço e porta especificados
    s.bind((HOST, PORT))
    # Escuta conexões entrantes
    s.listen()

    print('Aguardando conexões...')
    # Aceita a conexão e obtém o objeto de conexão e o endereço do cliente
    conn, addr = s.accept()
    with conn:
        print('Conectado por', addr)
        while True:
            # Recebe dados do cliente
            data = conn.recv(1024)
            if not data:
                break
            print('Mensagem recebida:', data.decode())
            # Envia dados de volta ao cliente
            conn.sendall(data)
