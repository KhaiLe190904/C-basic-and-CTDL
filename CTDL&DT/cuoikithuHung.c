#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIKES 1000
#define DAY_START 21600
#define DAY_END 64800   

typedef struct {
    char plate[12];
    int time_in;
    int is_moto;
} Vehicle;

Vehicle parking_lot[MAX_BIKES];
int vehicle_count = 0;
int total_earnings = 0;

int time_to_seconds(const char *time) {
    int hours, minutes, seconds;
    sscanf(time, "%d:%d:%d", &hours, &minutes, &seconds);
    return hours * 3600 + minutes * 60 + seconds;
}

int calculate_bill(int time_in, int time_out, int is_moto) {
    int day_rate = is_moto ? 3 : 1;
    int night_rate = is_moto ? 5 : 2;
    int overnight_rate = is_moto ? 8 : 3;
    int over_two_nights_rate = is_moto ? 13 : 5;

    int bill = 0;
    if (time_out < time_in) {
        time_out += 24 * 3600; 
    }
    int stayed_over_night = (time_in < DAY_START && time_out > DAY_START) || (time_in < DAY_END && time_out > DAY_END);
    if (time_in < DAY_START) {
        if (time_out <= DAY_END) {
            bill = stayed_over_night ? overnight_rate : night_rate;
        } else {
            bill = over_two_nights_rate;
        }
    } else if (time_in < DAY_END) {
        if (time_out <= DAY_END) {
            bill = day_rate;
        } else {
            bill = stayed_over_night ? (day_rate + night_rate) : night_rate;
        }
    } else {
        bill = night_rate;
    }

    return bill;
}

int find_vehicle(const char *plate) {
    for (int i = 0; i < vehicle_count; ++i) {
        if (strcmp(parking_lot[i].plate, plate) == 0) {
            return i;
        }
    }
    return -1;
}

int park_vehicle(const char *time, const char *plate) {
    if (find_vehicle(plate) != -1) {
        return 0;
    }
    strcpy(parking_lot[vehicle_count].plate, plate);
    parking_lot[vehicle_count].time_in = time_to_seconds(time);
    parking_lot[vehicle_count].is_moto = (plate[0] != 'x');
    vehicle_count++;
    return 1;
}

int leave_parking_lot(const char *time, const char *plate) {
    int index = find_vehicle(plate);
    if (index == -1) {
        return 0;
    }
    int time_out = time_to_seconds(time);
    int bill = calculate_bill(parking_lot[index].time_in, time_out, parking_lot[index].is_moto);
    total_earnings += bill;
    for (int i = index; i < vehicle_count - 1; ++i) {
        parking_lot[i] = parking_lot[i + 1];
    }
    vehicle_count--;
    return bill;
}

int count_motos() {
    int count = 0;
    for (int i = 0; i < vehicle_count; ++i) {
        if (parking_lot[i].is_moto) {
            count++;
        }
    }
    return count;
}

int main() {
    char line[256], command[10], time[9], plate[12];
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '*') {
            break;
        }
                sscanf(line, "%s %s", time, plate);
        park_vehicle(time, plate);
    }

    while (1) {
        if (scanf("%s", command) != 1) break;

        if (strcmp(command, "*") == 0) {
            break;
        } else if (strcmp(command, "list") == 0) {
            for (int i = 0; i < vehicle_count; i++) {
                printf("%s\n", parking_lot[i].plate);
            }
        } else if (strcmp(command, "find") == 0) {
            scanf("%s", plate);
            int index = find_vehicle(plate);
            printf("%d\n", index);
        } else if (strcmp(command, "in") == 0) {
            scanf("%s %s", time, plate);
            int result = park_vehicle(time, plate);
            printf("%d\n", result);
        } else if (strcmp(command, "out") == 0) {
            scanf("%s %s", time, plate);
            int result = leave_parking_lot(time, plate);
            printf("%d\n", result > 0 ? 1 : 0);
        } else if (strcmp(command, "cnt-moto") == 0) {
            int moto_count = count_motos();
            printf("%d\n", moto_count);
        } else if (strcmp(command, "bill") == 0) {
            scanf("%s %s", time, plate);
            int index = find_vehicle(plate);
            if (index == -1) {
                printf("-1\n");
            } else {
                int time_out = time_to_seconds(time);
                int bill = calculate_bill(parking_lot[index].time_in, time_out, parking_lot[index].is_moto);
                printf("%d\n", bill);
            }
        } else if (strcmp(command, "billall") == 0) {
            printf("%d\n", total_earnings);
        }
    }

    return 0;
}
