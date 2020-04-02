# README

## Construire le container

```bash
$ sudo docker build . -t magicfish:v1
```

## Lancer le container

```bash
$ sudo docker run -d --rm --name magicfish -p5555:5555 -t magicfish:v1
```

Faut le port 5555 ouvert, sinon tu peux le changer sur le "-p"
