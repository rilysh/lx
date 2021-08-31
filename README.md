# LX

A ls alternative, no like exa it isn't a `git status` alternative or `tree -C` alternative

### Building
```sh
cmake -B _build
cmake --build _build
```


### Installing
```sh
cmake --install _build
```

[//]: # (### Configuring)

### Usage
```
lx
```

```
lx ~/Desktop
```

```
lx --realpath main.cpp
```

```
lx -l ~/code .. -a
```


##### Flags
-a -A --all - Show dotfiles
-l --long - show permissions and disk usage
-r --realpath - show absolute path from current working directory
