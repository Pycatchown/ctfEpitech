#!/bin/bash

while : 
do
    su -c "exec socat TCP-LISTEN:4252,reuseaddr,fork EXEC:/pwn/babysDontDrinkCoffe,stderr" - pwnuser;
done