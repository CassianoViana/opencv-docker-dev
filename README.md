# build da imagem
docker image build -t opencv:1.0 .

# construção do container
docker container run -it -d --name trabalho-visao opencv:1.0

# vscode
- Instalar extensão do c++ da Microsoft
- Instalar extensão remote container
- Conectar no container rodando pelo vscode e abrir pasta opencv/src

- Ainda não consegui fazer funcionar a comunicação do display do docker com o host. Então esse repositório serve como guia para instação do opencv no linux
