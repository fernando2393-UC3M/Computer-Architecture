#!/usr/bin/env bash

#250 50 250
output1=$(./nasteroids_par 250 50 250 50.5 2000)
output2=$(./nasteroids_par 250 50 250 50.5 2000)
output3=$(./nasteroids_par 250 50 250 50.5 2000)
output4=$(./nasteroids_par 250 50 250 50.5 2000)
output5=$(./nasteroids_par 250 50 250 50.5 2000)
output6=$(./nasteroids_par 250 50 250 50.5 2000)
output7=$(./nasteroids_par 250 50 250 50.5 2000)
output8=$(./nasteroids_par 250 50 250 50.5 2000)
output9=$(./nasteroids_par 250 50 250 50.5 2000)
output10=$(./nasteroids_par 250 50 250 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 250 50 250"

#500 50 250
output1=$(./nasteroids_par 500 50 250 50.5 2000)
output2=$(./nasteroids_par 500 50 250 50.5 2000)
output3=$(./nasteroids_par 500 50 250 50.5 2000)
output4=$(./nasteroids_par 500 50 250 50.5 2000)
output5=$(./nasteroids_par 500 50 250 50.5 2000)
output6=$(./nasteroids_par 500 50 250 50.5 2000)
output7=$(./nasteroids_par 500 50 250 50.5 2000)
output8=$(./nasteroids_par 500 50 250 50.5 2000)
output9=$(./nasteroids_par 500 50 250 50.5 2000)
output10=$(./nasteroids_par 500 50 250 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 500 50 250"

#1000 50 250
output1=$(./nasteroids_par 1000 50 250 50.5 2000)
output2=$(./nasteroids_par 1000 50 250 50.5 2000)
output3=$(./nasteroids_par 1000 50 250 50.5 2000)
output4=$(./nasteroids_par 1000 50 250 50.5 2000)
output5=$(./nasteroids_par 1000 50 250 50.5 2000)
output6=$(./nasteroids_par 1000 50 250 50.5 2000)
output7=$(./nasteroids_par 1000 50 250 50.5 2000)
output8=$(./nasteroids_par 1000 50 250 50.5 2000)
output9=$(./nasteroids_par 1000 50 250 50.5 2000)
output10=$(./nasteroids_par 1000 50 250 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 1000 50 250"

#250 50 500
output1=$(./nasteroids_par 250 50 500 50.5 2000)
output2=$(./nasteroids_par 250 50 500 50.5 2000)
output3=$(./nasteroids_par 250 50 500 50.5 2000)
output4=$(./nasteroids_par 250 50 500 50.5 2000)
output5=$(./nasteroids_par 250 50 500 50.5 2000)
output6=$(./nasteroids_par 250 50 500 50.5 2000)
output7=$(./nasteroids_par 250 50 500 50.5 2000)
output8=$(./nasteroids_par 250 50 500 50.5 2000)
output9=$(./nasteroids_par 250 50 500 50.5 2000)
output10=$(./nasteroids_par 250 50 500 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 250 50 500"

#500 50 500
output1=$(./nasteroids_par 500 50 500 50.5 2000)
output2=$(./nasteroids_par 500 50 500 50.5 2000)
output3=$(./nasteroids_par 500 50 500 50.5 2000)
output4=$(./nasteroids_par 500 50 500 50.5 2000)
output5=$(./nasteroids_par 500 50 500 50.5 2000)
output6=$(./nasteroids_par 500 50 500 50.5 2000)
output7=$(./nasteroids_par 500 50 500 50.5 2000)
output8=$(./nasteroids_par 500 50 500 50.5 2000)
output9=$(./nasteroids_par 500 50 500 50.5 2000)
output10=$(./nasteroids_par 500 50 500 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 500 50 500"

#1000 50 500
output1=$(./nasteroids_par 1000 50 500 50.5 2000)
output2=$(./nasteroids_par 1000 50 500 50.5 2000)
output3=$(./nasteroids_par 1000 50 500 50.5 2000)
output4=$(./nasteroids_par 1000 50 500 50.5 2000)
output5=$(./nasteroids_par 1000 50 500 50.5 2000)
output6=$(./nasteroids_par 1000 50 500 50.5 2000)
output7=$(./nasteroids_par 1000 50 500 50.5 2000)
output8=$(./nasteroids_par 1000 50 500 50.5 2000)
output9=$(./nasteroids_par 1000 50 500 50.5 2000)
output10=$(./nasteroids_par 1000 50 500 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 1000 50 500"

#250 50 1000
output1=$(./nasteroids_par 250 50 1000 50.5 2000)
output2=$(./nasteroids_par 250 50 1000 50.5 2000)
output3=$(./nasteroids_par 250 50 1000 50.5 2000)
output4=$(./nasteroids_par 250 50 1000 50.5 2000)
output5=$(./nasteroids_par 250 50 1000 50.5 2000)
output6=$(./nasteroids_par 250 50 1000 50.5 2000)
output7=$(./nasteroids_par 250 50 1000 50.5 2000)
output8=$(./nasteroids_par 250 50 1000 50.5 2000)
output9=$(./nasteroids_par 250 50 1000 50.5 2000)
output10=$(./nasteroids_par 250 50 1000 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 250 50 1000"

#500 50 1000
output1=$(./nasteroids_par 500 50 1000 50.5 2000)
output2=$(./nasteroids_par 500 50 1000 50.5 2000)
output3=$(./nasteroids_par 500 50 1000 50.5 2000)
output4=$(./nasteroids_par 500 50 1000 50.5 2000)
output5=$(./nasteroids_par 500 50 1000 50.5 2000)
output6=$(./nasteroids_par 500 50 1000 50.5 2000)
output7=$(./nasteroids_par 500 50 1000 50.5 2000)
output8=$(./nasteroids_par 500 50 1000 50.5 2000)
output9=$(./nasteroids_par 500 50 1000 50.5 2000)
output10=$(./nasteroids_par 500 50 1000 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 500 50 1000"

#1000 50 1000
output1=$(./nasteroids_par 1000 50 1000 50.5 2000)
output2=$(./nasteroids_par 1000 50 1000 50.5 2000)
output3=$(./nasteroids_par 1000 50 1000 50.5 2000)
output4=$(./nasteroids_par 1000 50 1000 50.5 2000)
output5=$(./nasteroids_par 1000 50 1000 50.5 2000)
output6=$(./nasteroids_par 1000 50 1000 50.5 2000)
output7=$(./nasteroids_par 1000 50 1000 50.5 2000)
output8=$(./nasteroids_par 1000 50 1000 50.5 2000)
output9=$(./nasteroids_par 1000 50 1000 50.5 2000)
output10=$(./nasteroids_par 1000 50 1000 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 1000 50 1000"

#-------------------------------------------------------------------------------------------------------------------------

#250 100 250
output1=$(./nasteroids_par 250 100 250 50.5 2000)
output2=$(./nasteroids_par 250 100 250 50.5 2000)
output3=$(./nasteroids_par 250 100 250 50.5 2000)
output4=$(./nasteroids_par 250 100 250 50.5 2000)
output5=$(./nasteroids_par 250 100 250 50.5 2000)
output6=$(./nasteroids_par 250 100 250 50.5 2000)
output7=$(./nasteroids_par 250 100 250 50.5 2000)
output8=$(./nasteroids_par 250 100 250 50.5 2000)
output9=$(./nasteroids_par 250 100 250 50.5 2000)
output10=$(./nasteroids_par 250 100 250 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 250 100 250"

#500 100 250
output1=$(./nasteroids_par 500 100 250 50.5 2000)
output2=$(./nasteroids_par 500 100 250 50.5 2000)
output3=$(./nasteroids_par 500 100 250 50.5 2000)
output4=$(./nasteroids_par 500 100 250 50.5 2000)
output5=$(./nasteroids_par 500 100 250 50.5 2000)
output6=$(./nasteroids_par 500 100 250 50.5 2000)
output7=$(./nasteroids_par 500 100 250 50.5 2000)
output8=$(./nasteroids_par 500 100 250 50.5 2000)
output9=$(./nasteroids_par 500 100 250 50.5 2000)
output10=$(./nasteroids_par 500 100 250 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 500 100 250"

#1000 100 250
output1=$(./nasteroids_par 1000 100 250 50.5 2000)
output2=$(./nasteroids_par 1000 100 250 50.5 2000)
output3=$(./nasteroids_par 1000 100 250 50.5 2000)
output4=$(./nasteroids_par 1000 100 250 50.5 2000)
output5=$(./nasteroids_par 1000 100 250 50.5 2000)
output6=$(./nasteroids_par 1000 100 250 50.5 2000)
output7=$(./nasteroids_par 1000 100 250 50.5 2000)
output8=$(./nasteroids_par 1000 100 250 50.5 2000)
output9=$(./nasteroids_par 1000 100 250 50.5 2000)
output10=$(./nasteroids_par 1000 100 250 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 1000 100 250"

#250 100 500
output1=$(./nasteroids_par 250 100 500 50.5 2000)
output2=$(./nasteroids_par 250 100 500 50.5 2000)
output3=$(./nasteroids_par 250 100 500 50.5 2000)
output4=$(./nasteroids_par 250 100 500 50.5 2000)
output5=$(./nasteroids_par 250 100 500 50.5 2000)
output6=$(./nasteroids_par 250 100 500 50.5 2000)
output7=$(./nasteroids_par 250 100 500 50.5 2000)
output8=$(./nasteroids_par 250 100 500 50.5 2000)
output9=$(./nasteroids_par 250 100 500 50.5 2000)
output10=$(./nasteroids_par 250 100 500 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 250 100 500"

#500 100 500
output1=$(./nasteroids_par 500 100 500 50.5 2000)
output2=$(./nasteroids_par 500 100 500 50.5 2000)
output3=$(./nasteroids_par 500 100 500 50.5 2000)
output4=$(./nasteroids_par 500 100 500 50.5 2000)
output5=$(./nasteroids_par 500 100 500 50.5 2000)
output6=$(./nasteroids_par 500 100 500 50.5 2000)
output7=$(./nasteroids_par 500 100 500 50.5 2000)
output8=$(./nasteroids_par 500 100 500 50.5 2000)
output9=$(./nasteroids_par 500 100 500 50.5 2000)
output10=$(./nasteroids_par 500 100 500 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 500 100 500"

#1000 100 500
output1=$(./nasteroids_par 1000 100 500 50.5 2000)
output2=$(./nasteroids_par 1000 100 500 50.5 2000)
output3=$(./nasteroids_par 1000 100 500 50.5 2000)
output4=$(./nasteroids_par 1000 100 500 50.5 2000)
output5=$(./nasteroids_par 1000 100 500 50.5 2000)
output6=$(./nasteroids_par 1000 100 500 50.5 2000)
output7=$(./nasteroids_par 1000 100 500 50.5 2000)
output8=$(./nasteroids_par 1000 100 500 50.5 2000)
output9=$(./nasteroids_par 1000 100 500 50.5 2000)
output10=$(./nasteroids_par 1000 100 500 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 1000 100 500"

#250 100 1000
output1=$(./nasteroids_par 250 100 1000 50.5 2000)
output2=$(./nasteroids_par 250 100 1000 50.5 2000)
output3=$(./nasteroids_par 250 100 1000 50.5 2000)
output4=$(./nasteroids_par 250 100 1000 50.5 2000)
output5=$(./nasteroids_par 250 100 1000 50.5 2000)
output6=$(./nasteroids_par 250 100 1000 50.5 2000)
output7=$(./nasteroids_par 250 100 1000 50.5 2000)
output8=$(./nasteroids_par 250 100 1000 50.5 2000)
output9=$(./nasteroids_par 250 100 1000 50.5 2000)
output10=$(./nasteroids_par 250 100 1000 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 250 100 1000"

#500 100 1000
output1=$(./nasteroids_par 500 100 1000 50.5 2000)
output2=$(./nasteroids_par 500 100 1000 50.5 2000)
output3=$(./nasteroids_par 500 100 1000 50.5 2000)
output4=$(./nasteroids_par 500 100 1000 50.5 2000)
output5=$(./nasteroids_par 500 100 1000 50.5 2000)
output6=$(./nasteroids_par 500 100 1000 50.5 2000)
output7=$(./nasteroids_par 500 100 1000 50.5 2000)
output8=$(./nasteroids_par 500 100 1000 50.5 2000)
output9=$(./nasteroids_par 500 100 1000 50.5 2000)
output10=$(./nasteroids_par 500 100 1000 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 500 100 1000"

#1000 100 1000
output1=$(./nasteroids_par 1000 100 1000 50.5 2000)
output2=$(./nasteroids_par 1000 100 1000 50.5 2000)
output3=$(./nasteroids_par 1000 100 1000 50.5 2000)
output4=$(./nasteroids_par 1000 100 1000 50.5 2000)
output5=$(./nasteroids_par 1000 100 1000 50.5 2000)
output6=$(./nasteroids_par 1000 100 1000 50.5 2000)
output7=$(./nasteroids_par 1000 100 1000 50.5 2000)
output8=$(./nasteroids_par 1000 100 1000 50.5 2000)
output9=$(./nasteroids_par 1000 100 1000 50.5 2000)
output10=$(./nasteroids_par 1000 100 1000 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 1000 100 1000"

#-------------------------------------------------------------------------------------------------------------------------

#250 200 250
output1=$(./nasteroids_par 250 200 250 50.5 2000)
output2=$(./nasteroids_par 250 200 250 50.5 2000)
output3=$(./nasteroids_par 250 200 250 50.5 2000)
output4=$(./nasteroids_par 250 200 250 50.5 2000)
output5=$(./nasteroids_par 250 200 250 50.5 2000)
output6=$(./nasteroids_par 250 200 250 50.5 2000)
output7=$(./nasteroids_par 250 200 250 50.5 2000)
output8=$(./nasteroids_par 250 200 250 50.5 2000)
output9=$(./nasteroids_par 250 200 250 50.5 2000)
output10=$(./nasteroids_par 250 200 250 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 250 200 250"

#500 200 250
output1=$(./nasteroids_par 500 200 250 50.5 2000)
output2=$(./nasteroids_par 500 200 250 50.5 2000)
output3=$(./nasteroids_par 500 200 250 50.5 2000)
output4=$(./nasteroids_par 500 200 250 50.5 2000)
output5=$(./nasteroids_par 500 200 250 50.5 2000)
output6=$(./nasteroids_par 500 200 250 50.5 2000)
output7=$(./nasteroids_par 500 200 250 50.5 2000)
output8=$(./nasteroids_par 500 200 250 50.5 2000)
output9=$(./nasteroids_par 500 200 250 50.5 2000)
output10=$(./nasteroids_par 500 200 250 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 500 200 250"

#1000 200 250
output1=$(./nasteroids_par 1000 200 250 50.5 2000)
output2=$(./nasteroids_par 1000 200 250 50.5 2000)
output3=$(./nasteroids_par 1000 200 250 50.5 2000)
output4=$(./nasteroids_par 1000 200 250 50.5 2000)
output5=$(./nasteroids_par 1000 200 250 50.5 2000)
output6=$(./nasteroids_par 1000 200 250 50.5 2000)
output7=$(./nasteroids_par 1000 200 250 50.5 2000)
output8=$(./nasteroids_par 1000 200 250 50.5 2000)
output9=$(./nasteroids_par 1000 200 250 50.5 2000)
output10=$(./nasteroids_par 1000 200 250 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 1000 200 250"

#250 200 500
output1=$(./nasteroids_par 250 200 500 50.5 2000)
output2=$(./nasteroids_par 250 200 500 50.5 2000)
output3=$(./nasteroids_par 250 200 500 50.5 2000)
output4=$(./nasteroids_par 250 200 500 50.5 2000)
output5=$(./nasteroids_par 250 200 500 50.5 2000)
output6=$(./nasteroids_par 250 200 500 50.5 2000)
output7=$(./nasteroids_par 250 200 500 50.5 2000)
output8=$(./nasteroids_par 250 200 500 50.5 2000)
output9=$(./nasteroids_par 250 200 500 50.5 2000)
output10=$(./nasteroids_par 250 200 500 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 250 200 500"

#500 200 500
output1=$(./nasteroids_par 500 200 500 50.5 2000)
output2=$(./nasteroids_par 500 200 500 50.5 2000)
output3=$(./nasteroids_par 500 200 500 50.5 2000)
output4=$(./nasteroids_par 500 200 500 50.5 2000)
output5=$(./nasteroids_par 500 200 500 50.5 2000)
output6=$(./nasteroids_par 500 200 500 50.5 2000)
output7=$(./nasteroids_par 500 200 500 50.5 2000)
output8=$(./nasteroids_par 500 200 500 50.5 2000)
output9=$(./nasteroids_par 500 200 500 50.5 2000)
output10=$(./nasteroids_par 500 200 500 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 500 200 500"

#1000 200 500
output1=$(./nasteroids_par 1000 200 500 50.5 2000)
output2=$(./nasteroids_par 1000 200 500 50.5 2000)
output3=$(./nasteroids_par 1000 200 500 50.5 2000)
output4=$(./nasteroids_par 1000 200 500 50.5 2000)
output5=$(./nasteroids_par 1000 200 500 50.5 2000)
output6=$(./nasteroids_par 1000 200 500 50.5 2000)
output7=$(./nasteroids_par 1000 200 500 50.5 2000)
output8=$(./nasteroids_par 1000 200 500 50.5 2000)
output9=$(./nasteroids_par 1000 200 500 50.5 2000)
output10=$(./nasteroids_par 1000 200 500 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 1000 200 500"

#250 200 1000
output1=$(./nasteroids_par 250 200 1000 50.5 2000)
output2=$(./nasteroids_par 250 200 1000 50.5 2000)
output3=$(./nasteroids_par 250 200 1000 50.5 2000)
output4=$(./nasteroids_par 250 200 1000 50.5 2000)
output5=$(./nasteroids_par 250 200 1000 50.5 2000)
output6=$(./nasteroids_par 250 200 1000 50.5 2000)
output7=$(./nasteroids_par 250 200 1000 50.5 2000)
output8=$(./nasteroids_par 250 200 1000 50.5 2000)
output9=$(./nasteroids_par 250 200 1000 50.5 2000)
output10=$(./nasteroids_par 250 200 1000 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 250 200 1000"

#500 200 1000
output1=$(./nasteroids_par 500 200 1000 50.5 2000)
output2=$(./nasteroids_par 500 200 1000 50.5 2000)
output3=$(./nasteroids_par 500 200 1000 50.5 2000)
output4=$(./nasteroids_par 500 200 1000 50.5 2000)
output5=$(./nasteroids_par 500 200 1000 50.5 2000)
output6=$(./nasteroids_par 500 200 1000 50.5 2000)
output7=$(./nasteroids_par 500 200 1000 50.5 2000)
output8=$(./nasteroids_par 500 200 1000 50.5 2000)
output9=$(./nasteroids_par 500 200 1000 50.5 2000)
output10=$(./nasteroids_par 500 200 1000 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 500 200 1000"

#1000 200 1000
output1=$(./nasteroids_par 1000 200 1000 50.5 2000)
output2=$(./nasteroids_par 1000 200 1000 50.5 2000)
output3=$(./nasteroids_par 1000 200 1000 50.5 2000)
output4=$(./nasteroids_par 1000 200 1000 50.5 2000)
output5=$(./nasteroids_par 1000 200 1000 50.5 2000)
output6=$(./nasteroids_par 1000 200 1000 50.5 2000)
output7=$(./nasteroids_par 1000 200 1000 50.5 2000)
output8=$(./nasteroids_par 1000 200 1000 50.5 2000)
output9=$(./nasteroids_par 1000 200 1000 50.5 2000)
output10=$(./nasteroids_par 1000 200 1000 50.5 2000)

result=$((output1 + output2 + output3 + output4 + output5 + output6 + output7 + output8 + output9 + output10))
result=$((result/10))

echo "The average time is $result microseconds for the sequence 1000 200 1000"
