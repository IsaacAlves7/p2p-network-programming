# P2P programming
<img src="https://github.com/user-attachments/assets/fabb9362-8950-46ef-a52e-17052e88b33f" align="right" height="377">

Vamos entrar fundo nisso sem mistificação, mas com um cuidado importante: o Spotify nunca foi um “Napster disfarçado”, e a arquitetura P2P dele era controlada, criptografada e dependente do servidor. Vou te explicar tecnicamente como ela funcionava de verdade, por que existia, por que foi abandonada e, no fim, vou te mostrar código realista que reproduz o modelo técnico (não o sistema comercial) usando arquivos genéricos, não músicas, exatamente como exercício de engenharia distribuída.

Programação reativa e sistemas reativos você já viu que são coisas diferentes; aqui acontece algo parecido: quando se fala “Spotify P2P”, muita gente imagina um swarm caótico, mas na prática era um sistema híbrido client–server + P2P assistido, muito mais próximo de BitTorrent com autoridade central do que de redes P2P puras.

Na arquitetura antiga, o Spotify Server continuava sendo a autoridade absoluta. Ele cuidava de autenticação, catálogo, licenças, DRM, chaves de descriptografia, metadados, controle de versão dos arquivos de áudio e autorização de playback. O cliente nunca “procurava músicas na rede” por conta própria.

> Ele sempre perguntava ao servidor: “posso tocar esse track_id?” e “de onde posso baixar os blocos?”. 

O servidor então respondia com algo parecido com um tracker do BitTorrent: uma lista de peers válidos, mais o fallback para CDN própria caso não houvesse peers suficientes ou a latência estivesse ruim.

O áudio não era transmitido como um arquivo inteiro, mas como blocos pequenos (chunks), normalmente de tamanho fixo, criptografados, com checksums. Esses blocos eram cacheados localmente no disco do cliente. Esse cache não era “compartilhado livremente”: ele só podia ser servido para outros clientes autenticados, usando um protocolo proprietário, com limites agressivos de banda, priorizando sempre o próprio playback do usuário. Se o cliente estivesse tocando música ou com CPU alta, ele simplesmente não servia nada.

O P2P entrava apenas no plano de dados, nunca no plano de controle. Toda a inteligência continuava no servidor. O cliente perguntava: “quero o track X”, o servidor respondia: “você pode baixar os blocos 0–120 desses peers A, B e C; se algum falhar, vá na CDN”. Isso resolvia três problemas enormes em 2008–2013: custo de CDN, picos regionais de tráfego e latência em mercados novos. Em países onde poucos usuários ouviam uma música, vinha da CDN. Em países onde milhares ouviam o mesmo hit, os próprios usuários distribuíam entre si.

Agora, vamos para a parte que você pediu explicitamente: como isso se traduz em código e arquitetura real, do zero, sem romantizar e sem copiar Spotify, mas reproduzindo o modelo técnico.

Imagine quatro componentes: um servidor central, um cliente, um cache local e um subsistema P2P. O servidor expõe uma API HTTP simples. O cliente pede um “asset” genérico (não música). O servidor responde com metadados, hashes e peers disponíveis. O cliente tenta baixar os chunks dos peers via TCP direto. Se falhar, baixa do servidor. Cada chunk é salvo no cache local e pode ser servido a outros peers.

## Development
Este é apenas um exemplo simples de comunicação P2P em Python usando sockets.

Para testar este exemplo:

1. Execute o script `peer_server.py` em um terminal.
2. Execute o script `peer_client.py` em outro terminal.
3. Observe a troca de mensagens entre os pares.
