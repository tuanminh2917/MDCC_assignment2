import subprocess
import re

REFERENCE = "Assignment_2.mp4"
videos = [
    "Assignment300k.mkv",
    "Assignment500k.mkv",
    "Assignment800k.mkv",
    "Assignment1200k.mkv",
    "Assignment2000k.mkv"
]

def extract_metrics(output):
    psnr = re.search(r'average:([\d.]+)', output)
    ssim = re.search(r'All:([\d.]+)', output)
    return (psnr.group(1) if psnr else "N/A", ssim.group(1) if ssim else "N/A")

for video in videos:
    print(f"\n📼 Video: {video}")
    cmd = [
        "ffmpeg", "-i", video, "-i", REFERENCE,
        "-lavfi", "[0:v][1:v]psnr;[0:v][1:v]ssim",
        "-f", "null", "-"
    ]
    result = subprocess.run(cmd, stderr=subprocess.PIPE, text=True)
    psnr, ssim = extract_metrics(result.stderr)
    print(f"🔹 PSNR: {psnr} dB")
    print(f"🔹 SSIM: {ssim}")
