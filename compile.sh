#!/bin/bash

gcc  -I./includes/ -I./libft/includes/ -L./libft/ -lft ft_ssl.c cli.c -o ft_ssl 
