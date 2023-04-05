#! /usr/bin/bash

start=5000
increment=5000
last=100000

for ((i=start; i<=last; i+=increment)); do
    order_file="o"$i".txt"
    desorder_file="d"$i".txt"
    python order_database.py $i $order_file
    python desorder_database.py $i $desorder_file
    build/tree-benchmark $order_file "out."$order_file
    build/tree-benchmark $desorder_database "out."$desorder_file
done

