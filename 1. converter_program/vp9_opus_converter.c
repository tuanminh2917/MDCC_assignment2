#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    // Insert the input video file name here
    char input_file[100];
    printf("Enter the input video file name: ");
    // Read the input video file name from the user
    fgets(input_file, sizeof(input_file), stdin);
    input_file[strcspn(input_file, "\n")] = '\0';

    // Insert the output video file name here
    char output_file[100];
    printf("Enter the output video file name: ");
    // Read the output video file name from the user
    fgets(output_file, 100, stdin);
    output_file[strcspn(output_file, "\n")] = '\0';
    

    // Construct the FFmpeg command to convert the video file to VP9 with Opus audio codec
    char command[512];
    snprintf(command, sizeof(command), "ffmpeg -i %s -c:v libvpx-vp9 -c:a libopus -ac 2 %s", input_file, output_file);

    // Execute the FFmpeg command
    int result = system(command);
    if (result == -1) {
        fprintf(stderr, "Error executing command: %s\n", command);
        return 1;
    }
    // Check the result of the command execution
    if (result != 0) {
        fprintf(stderr, "Error converting video file: %s\n", command);
        return 1;
    }

    // Print success message
    printf("Video file converted successfully: %s\n", output_file);
    // Print the command used for conversion
    printf("Command used: %s\n", command);
    // Print the input and output file names
    printf("Input file: %s\n", input_file);     
    printf("Output file: %s\n", output_file);
    return 0;
}