#include <stdio.h>

int determineMaxItems(int maximumLimit) {
    int totalSpent = 0;
    int items = 0;
    int i = 1;

    // Using a do-while loop for a different structure
    do {
        int price = i + 1; // Base price starts at $2 for item 1 (i starts at 1)
        if (i % 3 == 0) {
            price = price * 2 / 3; // Apply 66% coupon
        }

        if (totalSpent + price > maximumLimit) {
            break; // Stop if the next item exceeds the limit
        }

        totalSpent += price;
        items++;
        i++;
    } while (totalSpent <= maximumLimit);

    printf("I can only afford %d items.\n", items);
    return 1; // Difficulty rating
}

int outputProcessGrade(double calculatedGrade) {
    char letterGrade;

    if (calculatedGrade >= 90) {
        letterGrade = 'A';
    } else if (calculatedGrade >= 80) {
        letterGrade = 'B';
    } else if (calculatedGrade >= 70) {
        letterGrade = 'C';
    } else if (calculatedGrade >= 60) {
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }

    printf("Your grade based on %.2f will be %c\n", calculatedGrade, letterGrade);
    return letterGrade; // Return the letter grade
}

int determineNumericalGrade() {
    int grades[8];
    double weightedAverage = 0;
    int count = 0;

    // Using a for loop to scan the grades
    for (count = 0; count < 8; count++) {
        printf("Enter grade %d: ", count + 1);
        scanf("%d", &grades[count]);
    }

    // Calculate weighted average
    weightedAverage += (grades[0] + grades[1] + grades[2]) * 0.1; // 10% each for first 3
    weightedAverage += (grades[3] + grades[4]) * 0.2; // 20% each for next 2
    weightedAverage += (grades[5] + grades[6]) * 0.05; // 5% each for next 2
    weightedAverage += (100 - (3 * 10 + 2 * 20 + 2 * 5)) * grades[7] / 100; // Remaining weight for last

    printf("The weighted average based on the entered values is %.2f\n", weightedAverage);
    outputProcessGrade(weightedAverage);
    return 1; // Difficulty rating
}

void sendEmails(int daysLeft, int hoursLeft) {
    int totalHoursRemaining = (daysLeft * 24) + hoursLeft;

    // Do not print if within the 24-hour period
    if (totalHoursRemaining > 24) {
        printf("Sent an email with %d hours remaining.\n", totalHoursRemaining);
    }
}

int main(int argc, char **argv) {
    int maxLimit;
    printf("Enter your maximum budget: ");
    scanf("%d", &maxLimit);
    
    determineMaxItems(maxLimit);
    determineNumericalGrade();
    
    int daysLeft, hoursLeft;
    printf("Enter days and hours left (separated by space): ");
    scanf("%d %d", &daysLeft, &hoursLeft);
    
    sendEmails(daysLeft, hoursLeft);

    return 0; // Simple integer return
}
