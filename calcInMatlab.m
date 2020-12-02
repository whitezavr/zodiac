numDaysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
numDaysInMonthLeap = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

numDaysInMonthSum = zeros(12,1);
numDaysInMonthSumLeap = zeros(12,1);

for i = 2:1:12
numDaysInMonthSum(i, 1) = numDaysInMonthSum(i-1,1) + numDaysInMonth(1, i);
numDaysInMonthSumLeap(i, 1) = numDaysInMonthSumLeap(i-1,1) + numDaysInMonthLeap(1, i);
end
