# Run in docker

Simple and fast setup of EOS.IO on Docker is also available.

## Install Dependencies

- [Docker](https://docs.docker.com) Docker 17.05 or higher is required

## Docker Requirement

- At least 7GB RAM (Docker -> Preferences -> Advanced -> Memory -> 7GB or above)
- If the build below fails, make sure you've adjusted Docker Memory settings and try again.

## Build eos image

```bash
git clone https://github.com/keywolf/elasticsearch_plugin.git
cd elasticsearch_plugin/Docker
docker build --no-cache . -t eos_with_es_plugin
```

The above will build off the most recent commit to the master branch by default. If you would like to target a specific branch/tag, you may use a build argument. For example, if you wished to generate a docker image based off of the v1.4.2 tag, you could do the following:

```bash
docker build -t eos_with_es_plugin:v1.4.2 --build-arg branch=v1.4.2 .
```

By default, the symbol in eosio.system is set to SYS. You can override this using the symbol argument while building the docker image.

```bash
docker build -t eos_with_es_plugin --build-arg symbol=<symbol> .
```

## Start nodeos docker container only

```bash
docker run -d --name nodeos -p 8888:8888 -p 9876:9876 -t eos_with_es_plugin nodeosd.sh --elastic-url http://172.17.0.1:9200 --elastic-store-block-states 0 --elastic-store-blocks 0 --elastic-store-transactions 0 --elastic-store-transaction-traces 0 --elastic-thread-pool-size 8 --elastic-bulker-pool-size 4 --elastic-bulk-size 8 --elastic-filter-on ':setcode:' --elastic-filter-on ':setabi:' --elastic-filter-on 'eosio.token:transfer:' --elastic-index-wipe --replay-blockchain
```

By default, all data is persisted in a docker volume. It can be deleted if the data is outdated or corrupted:

```bash
$ docker inspect --format '{{ range .Mounts }}{{ .Name }} {{ end }}' nodeos
fdc265730a4f697346fa8b078c176e315b959e79365fc9cbd11f090ea0cb5cbc
$ docker volume rm fdc265730a4f697346fa8b078c176e315b959e79365fc9cbd11f090ea0cb5cbc
```

Alternately, you can directly mount host directory into the container

```bash
docker run -d --name nodeos -v /path-to-data-dir:/opt/eosio/bin/data-dir -p 8888:8888 -p 9876:9876 -t eos_with_es_plugin nodeosd.sh --elastic-url http://172.17.0.1:9200 --elastic-store-block-states 0 --elastic-store-blocks 0 --elastic-store-transactions 0 --elastic-store-transaction-traces 0 --elastic-thread-pool-size 8 --elastic-bulker-pool-size 4 --elastic-bulk-size 8 --elastic-filter-on ':setcode:' --elastic-filter-on ':setabi:' --elastic-filter-on 'eosio.token:transfer:' --elastic-index-wipe --replay-blockchain
```

## Get chain info

```bash
curl http://127.0.0.1:8888/v1/chain/get_info
```
