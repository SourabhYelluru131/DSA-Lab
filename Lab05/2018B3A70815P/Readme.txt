/* README.TXT */
Author : Sourabh S Yelluru
Lab05 - 2018B3A70815P
Contents - 
/*=========         Code        =========*/
driver.c
record.h
record.c
spaceAndTime.h
spaceAndTime.c
/*=========  input/output files =========*/
10
100
1000
10000
100000
result.txt
output.csv
output.xlsx
/*=========       images       ========= */
readTime.png      		  // Time to read various number of records from input file
sortTime.ong       		  // Time to sort the record array of various sizes
RecursiveStackMemory.png  // Approx. size of the recursive stack (during recursive call of insertion sort)

To re-run the code - 
1. Delete result.txt
2. Run the following
>> gcc -c driver.c
>> gcc -c record.c
>> gcc -c spaceAndTime.c
>> gcc -o exe driver.o record.o spaceAndTime.o
>> ./exe 10
>> ./exe 100
>> ./exe 1000
>> ./exe 10000
>> ./exe 100000
3. Convert it into excel by preferred method from the output printed in result.txt
4. Plot the chart for each

/* END OF README.TXT */
