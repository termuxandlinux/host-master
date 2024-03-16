# Set your own Virtual Host, but in easy, for beginners

# PPA Host
ppa
```
sudo add-apt-repository ppa:alexander314/ubuntu-amhf-unstable
sudo apt update
```

# Wget Version
wget
```bash
wget https://github.com/termuxandlinux/host-master/raw/main/.backup/1.0/host-master_1.0_armhf.deb
```
# Manual

manual (For Experts)
```bash
sudo nano /etc/apt/sources.list.d/alexander314-ubuntu-amhf.list

```

```txt
deb https://ppa.launchpadcontent.net/alexander314/ubuntu-amhf-unstable/ubuntu mantic main
deb-src https://ppa.launchpadcontent.net/alexander314/ubuntu-amhf-unstable/ubuntu mantic main

```


