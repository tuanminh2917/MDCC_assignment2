// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     char input[100];
//     char output[100];

//     // Nhập tên file gốc (phải đặt trong cùng thư mục với file C)
//     printf("Nhập tên video gốc (vd: input.mp4): ");
//     scanf("%s", input);

//     // Tạo tên file output
//     snprintf(output, sizeof(output), "output_overlay_bitrate.webm");

//     // Tạo command ffmpeg để overlay chữ động và thay đổi bitrate âm thanh
//     const char* command_template =
//         "ffmpeg -i Assignment2-converted.mkv \ -vf "drawtext=fontfile=/Library/Fonts/Arial.ttf:"
//      "text='Nguyễn Tiến Đạt  •  Trần Văn Long  •  Trương Công Đức  •  Bùi Tuấn Minh  |  VP9 + Opus':
//      "fontcolor=white:fontsize=28:
//      x=w-mod(t*100\,w+tw):y=h-60" \
// -b:v 800k -c:v libvpx-vp9 -c:a copy \
// output_overlay_800k.mkv
// ";

//     char command[500];
//     snprintf(command, sizeof(command), command_template, input, output);

//     printf("Đang thực hiện lệnh:\n%s\n", command);

//     int result = system(command);
//     if (result == 0) {
//         printf("✅ Video đã được xử lý và lưu thành '%s'\n", output);
//     } else {
//         printf("❌ Có lỗi xảy ra trong quá trình xử lý video.\n");
//     }

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    char output[100];

    // Nhập tên file gốc (phải đặt trong cùng thư mục với file C)
    // printf("Nhập tên video gốc (vd: input.webm): ");
    // scanf("%s", input);

    // Tạo tên file output
    snprintf(output, sizeof(output), "output_overlay_bitrate.webm");

    // Tạo lệnh ffmpeg để overlay chữ động và thay đổi bitrate
    // const char* command_template =
    
    // "ffmpeg -i Assignment_2_converted.mkv -vf \"drawtext=fontfile=/Library/Fonts/Arial.ttf:"
    // "text='Nguyễn Tiến Đạt  •  Trần Văn Long  •  Trương Công Đức  •  Bùi Tuấn Minh  |  VP9 + Opus ':"
    // "fontcolor=white:fontsize=28:"
    // "x=w-mod(t*(w+tw)/10\\,w+tw):y=h-60:enable='between(t,0,10)'\" "
    // "-b:v 800k -c:v libvpx-vp9 -c:a copy Assignment800k.mkv";

    // const char* command_template =
    
    // "ffmpeg -i Assignment_2_converted.mkv -vf \"drawtext=fontfile=/Library/Fonts/Arial.ttf:"
    // "text='Nguyễn Tiến Đạt  •  Trần Văn Long  •  Trương Công Đức  •  Bùi Tuấn Minh  |  VP9 + Opus ':"
    // "fontcolor=white:fontsize=28:"
    // "x=w-mod(t*(w+tw)/10\\,w+tw):y=h-60:enable='between(t,0,10)'\" "
    // "-b:v 500k -c:v libvpx-vp9 -c:a copy Assignment500k.mkv";

    //  const char* command_template =
    
    //  "ffmpeg -i Assignment_2_converted.mkv -vf \"drawtext=fontfile=/Library/Fonts/Arial.ttf:"
    //  "text='Nguyễn Tiến Đạt  •  Trần Văn Long  •  Trương Công Đức  •  Bùi Tuấn Minh  |  VP9 + Opus ':"
    //  "fontcolor=white:fontsize=28:"
    //  "x=w-mod(t*(w+tw)/10\\,w+tw):y=h-60:enable='between(t,0,10)'\" "
    //  "-b:v 300k -c:v libvpx-vp9 -c:a copy Assignment300k.mkv";
    
    //  const char* command_template =
    
    //  "ffmpeg -i Assignment_2_converted.mkv -vf \"drawtext=fontfile=/Library/Fonts/Arial.ttf:"
    //  "text='Nguyễn Tiến Đạt  •  Trần Văn Long  •  Trương Công Đức  •  Bùi Tuấn Minh  |  VP9 + Opus ':"
    //  "fontcolor=white:fontsize=28:"
    //  "x=w-mod(t*(w+tw)/10\\,w+tw):y=h-60:enable='between(t,0,10)'\" "
    //  "-b:v 1200k -c:v libvpx-vp9 -c:a copy Assignment1200k.mkv";

     const char* command_template =
    
     "ffmpeg -i Assignment_2_converted.mkv -vf \"drawtext=fontfile=/Library/Fonts/Arial.ttf:"
     "text='Nguyễn Tiến Đạt  •  Trần Văn Long  •  Trương Công Đức  •  Bùi Tuấn Minh  |  VP9 + Opus ':"
     "fontcolor=white:fontsize=28:"
     "x=w-mod(t*(w+tw)/10\\,w+tw):y=h-60:enable='between(t,0,10)'\" "
     "-b:v 2000k -c:v libvpx-vp9 -c:a copy Assignment2000k.mkv";

    char command[1000];
    snprintf(command, sizeof(command), command_template, input, output);

    printf("Đang thực hiện lệnh:\n%s\n", command);

    int result = system(command);
    if (result == 0) {
        printf("✅ Video đã được xử lý và lưu thành '%s'\n", output);
    } else {
        printf("❌ Có lỗi xảy ra trong quá trình xử lý video.\n");
    }

    return 0;
}

