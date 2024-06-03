extern "C" {
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

#include <iostream>
#include <string>

using namespace std;

// Function to convert a grayscale pixel value to ASCII character
char pixelToAscii(int pixelValue) {
    static const string asciiChars = "@%#*+=-:. ";
    int charIndex = pixelValue * (asciiChars.size() - 1) / 255;
    return asciiChars[charIndex];
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <video_file_path>" << endl;
        return 1;
    }

    const char* videoFilePath = argv[1];
    av_register_all();

    AVFormatContext* formatContext = nullptr;
    if (avformat_open_input(&formatContext, videoFilePath, nullptr, nullptr) != 0) {
        cout << "Error: Couldn't open the video file." << endl;
        return 1;
    }

    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        cout << "Error: Couldn't find stream information." << endl;
        avformat_close_input(&formatContext);
        return 1;
    }

    AVCodec* codec = nullptr;
    int videoStreamIndex = -1;
    AVCodecParameters* codecParams = nullptr;

    for (unsigned int i = 0; i < formatContext->nb_streams; ++i) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStreamIndex = i;
            codecParams = formatContext->streams[i]->codecpar;
            codec = avcodec_find_decoder(codecParams->codec_id);
            if (!codec) {
                cout << "Error: Unsupported codec." << endl;
                avformat_close_input(&formatContext);
                return 1;
            }
            break;
        }
    }

    AVCodecContext* codecContext = avcodec_alloc_context3(codec);
    if (!codecContext) {
        cout << "Error: Couldn't allocate codec context." << endl;
        avformat_close_input(&formatContext);
        return 1;
    }

    if (avcodec_parameters_to_context(codecContext, codecParams) < 0) {
        cout << "Error: Couldn't copy codec parameters." << endl;
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        return 1;
    }

    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
        cout << "Error: Couldn't open codec." << endl;
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        return 1;
    }

    AVFrame* frame = av_frame_alloc();
    AVPacket* packet = av_packet_alloc();
    if (!frame || !packet) {
        cout << "Error: Couldn't allocate frame/packet." << endl;
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        return 1;
    }

    AVPixelFormat targetPixelFormat = AV_PIX_FMT_GRAY8;
    SwsContext* swsContext = sws_getContext(
        codecContext->width, codecContext->height, codecContext->pix_fmt,
        codecContext->width, codecContext->height, targetPixelFormat,
        SWS_BILINEAR, nullptr, nullptr, nullptr);

    while (av_read_frame(formatContext, packet) >= 0) {
        if (packet->stream_index == videoStreamIndex) {
            if (avcodec_send_packet(codecContext, packet) != 0) {
                cout << "Error: Failed to send packet to decoder." << endl;
                break;
            }

            while (avcodec_receive_frame(codecContext, frame) == 0) {
                for (int y = 0; y < frame->height; ++y) {
                    for (int x = 0; x < frame->width; ++x) {
                        uint8_t* pixelPtr = &frame->data[0][y * frame->linesize[0] + x];
                        char asciiChar = pixelToAscii(*pixelPtr);
                        cout << asciiChar;
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }

        av_packet_unref(packet);
    }

    av_frame_free(&frame);
    av_packet_free(&packet);
    avcodec_free_context(&codecContext);
    avformat_close_input(&formatContext);

    return 0;
}
