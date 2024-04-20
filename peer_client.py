import socket

# Configurações de rede
HOST = '127.0.0.1'  # Endereço IP local
PORT = 65432        # Porta de comunicação

# Mensagem a ser enviada
message = "Olá, este é um exemplo de comunicação P2P em Python!"

# Cria um socket TCP/IP
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # Conecta ao servidor
    s.connect((HOST, PORT))
    # Envia a mensagem ao servidor
    s.sendall(message.encode())
    # Recebe a resposta do servidor
    data = s.recv(1024)

print('Mensagem recebida do servidor:', data.decode())
